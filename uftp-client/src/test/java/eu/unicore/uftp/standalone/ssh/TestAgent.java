package eu.unicore.uftp.standalone.ssh;

import static org.junit.Assert.assertTrue;

import java.io.File;

import org.apache.commons.io.FileUtils;
import org.apache.log4j.Level;
import org.apache.log4j.Logger;

import eu.unicore.uftp.authserver.authenticate.sshkey.SSHKey;
import eu.unicore.uftp.authserver.authenticate.sshkey.SSHUtils;

/**
 * functional test that tests the agent support using real keys
 */
public class TestAgent {
	
	//@Test
	public void testSigningUsingAgent() throws Exception {
		String token = "test123";
		String user = "demouser";
		File privKey = new File(System.getProperty("user.home")+"/.ssh/id_rsa");
		SshKeyHandler handler = new SshKeyHandler(privKey, user, token);
		SSHKey authData = handler.getAuthData();
		String pubKey = FileUtils.readFileToString(new File(System.getProperty("user.home")+"/.ssh/id_rsa.pub"));
		boolean success = SSHUtils.validateAuthData(authData, pubKey);
		assertTrue("Signature validation failed!",success);
	}

	//@Test
	public void testSigningUsingAgentDSA() throws Exception {
		Logger.getLogger(SSHUtils.class).setLevel(Level.DEBUG);
		String token = "test123";
		String user = "demouser";
		File privKey = new File(System.getProperty("user.home")+"/.ssh/id_dsa");
		SshKeyHandler handler = new SshKeyHandler(privKey, user, token);
		SSHKey authData = handler.getAuthData();
		String pubKey = FileUtils.readFileToString(new File(System.getProperty("user.home")+"/.ssh/id_dsa.pub"));
		boolean success = SSHUtils.validateAuthData(authData, pubKey);
		assertTrue("Signature validation failed!",success);
	}
}
