/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class eu_unicore_uftp_server_unix_UnixUser */

#ifndef _Included_eu_unicore_uftp_server_unix_UnixUser
#define _Included_eu_unicore_uftp_server_unix_UnixUser
#ifdef __cplusplus
extern "C" {
#endif
#undef eu_unicore_uftp_server_unix_UnixUser_SUCCESS
#define eu_unicore_uftp_server_unix_UnixUser_SUCCESS 0L
#undef eu_unicore_uftp_server_unix_UnixUser_FAILURE
#define eu_unicore_uftp_server_unix_UnixUser_FAILURE -1L
/*
 * Class:     eu_unicore_uftp_server_unix_UnixUser
 * Method:    whoami
 * Signature: ()Leu/unicore/uftp/server/unix/UnixUser;
 */
JNIEXPORT jobject JNICALL Java_eu_unicore_uftp_server_unix_UnixUser_whoami
  (JNIEnv *, jclass);

/*
 * Class:     eu_unicore_uftp_server_unix_UnixUser
 * Method:    lookupByLoginName
 * Signature: (Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_eu_unicore_uftp_server_unix_UnixUser_lookupByLoginName
  (JNIEnv *, jobject, jstring);

/*
 * Class:     eu_unicore_uftp_server_unix_UnixUser
 * Method:    lookupByUid
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_eu_unicore_uftp_server_unix_UnixUser_lookupByUid
  (JNIEnv *, jobject, jint);

/*
 * Class:     eu_unicore_uftp_server_unix_UnixUser
 * Method:    setUid
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_eu_unicore_uftp_server_unix_UnixUser_setUid
  (JNIEnv *, jclass, jint);

/*
 * Class:     eu_unicore_uftp_server_unix_UnixUser
 * Method:    setEUid
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_eu_unicore_uftp_server_unix_UnixUser_setEUid
  (JNIEnv *, jclass, jint);

/*
 * Class:     eu_unicore_uftp_server_unix_UnixUser
 * Method:    setReUid
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_eu_unicore_uftp_server_unix_UnixUser_setReUid
  (JNIEnv *, jclass, jint, jint);

/*
 * Class:     eu_unicore_uftp_server_unix_UnixUser
 * Method:    setGid
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_eu_unicore_uftp_server_unix_UnixUser_setGid
  (JNIEnv *, jclass, jint);

/*
 * Class:     eu_unicore_uftp_server_unix_UnixUser
 * Method:    setEGid
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_eu_unicore_uftp_server_unix_UnixUser_setEGid
  (JNIEnv *, jclass, jint);

/*
 * Class:     eu_unicore_uftp_server_unix_UnixUser
 * Method:    setReGid
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_eu_unicore_uftp_server_unix_UnixUser_setReGid
  (JNIEnv *, jclass, jint, jint);

/*
 * Class:     eu_unicore_uftp_server_unix_UnixUser
 * Method:    initGroups
 * Signature: (Ljava/lang/String;I)I
 */
JNIEXPORT jint JNICALL Java_eu_unicore_uftp_server_unix_UnixUser_initGroups
  (JNIEnv *, jclass, jstring, jint);

#ifdef __cplusplus
}
#endif
#endif
