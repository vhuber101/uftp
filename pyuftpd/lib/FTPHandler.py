import os
import threading

import BecomeUser, Connector, Log, Protocol, Server, Session

def create_session(connector: Connector, config, LOG: Log):
    try:
        LOG.info("Processing %s" % connector.info())
        job = Protocol.establish_connection(connector, config)
        if job is None:
            connector.write_message("530 Not logged in: no matching transfer request found")
            connector.close()
            return
        LOG.info("Established connection for '%s'" % job['user'])
    except Exception as e:
        LOG.error(e)
        connector.close()
        return
    limit = config['MAX_CONNECTIONS']
    if len(job['_PIDS'])==limit:
        connector.write_message("500 Too many open FTP sessions!")
        connector.close()
        return
    
    pid = os.fork()
    if pid:
        # parent, store relevant data
        # and continue with accept loop
        LOG.info("Created new UFTP session, child process <%s>" % pid)
        with job['_LOCK']:
            job['_PIDS'].append(pid)
        return

    #
    # child - drop privileges and launch session processing
    #
    user = job['user']
    groups = job.get('group')
    try:
        user_switch_status = BecomeUser.become_user(user, groups, config, LOG)
        if user_switch_status is not True:
            connector.write_message("530 Not logged in: %s" % user_switch_status)
            raise Exception("Cannot switch UID/GID: %s" % user_switch_status)
        connector.write_message("230 Login successful")
        job['UFTP_NOWRITE'] = config["UFTP_NOWRITE"]
        session = Session.Session(connector, job, LOG)
        session.run()
        LOG.info("Finished processing FTP session for '%s'" % user)
    except Exception as e:
        LOG.error(e)
    connector.close()
    os._exit(0)

def ftp_listener(ftp_server, config, LOG: Log):
    LOG.info("Started FTP listener thread.")
    while True:
        try:
            connector = Server.accept_ftp(ftp_server, LOG)
            worker_thread = threading.Thread(target=create_session,
                                  args=(connector, config, LOG))
            worker_thread.start()
        except Exception as e:
            LOG.error(e)
