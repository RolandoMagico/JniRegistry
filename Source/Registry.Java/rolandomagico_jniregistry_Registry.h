/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class rolandomagico_jniregistry_Registry */

#ifndef _Included_rolandomagico_jniregistry_Registry
#define _Included_rolandomagico_jniregistry_Registry
#ifdef __cplusplus
extern "C" {
#endif
#undef rolandomagico_jniregistry_Registry_HKEY_CLASSES_ROOT
#define rolandomagico_jniregistry_Registry_HKEY_CLASSES_ROOT -2147483648L
#undef rolandomagico_jniregistry_Registry_HKEY_CURRENT_CONFIG
#define rolandomagico_jniregistry_Registry_HKEY_CURRENT_CONFIG -2147483643L
#undef rolandomagico_jniregistry_Registry_HKEY_CURRENT_USER
#define rolandomagico_jniregistry_Registry_HKEY_CURRENT_USER -2147483647L
#undef rolandomagico_jniregistry_Registry_HKEY_LOCAL_MACHINE
#define rolandomagico_jniregistry_Registry_HKEY_LOCAL_MACHINE -2147483646L
#undef rolandomagico_jniregistry_Registry_HKEY_PERFORMANCE_DATA
#define rolandomagico_jniregistry_Registry_HKEY_PERFORMANCE_DATA -2147483644L
#undef rolandomagico_jniregistry_Registry_HKEY_PERFORMANCE_NLSTEXT
#define rolandomagico_jniregistry_Registry_HKEY_PERFORMANCE_NLSTEXT -2147483552L
#undef rolandomagico_jniregistry_Registry_HKEY_PERFORMANCE_TEXT
#define rolandomagico_jniregistry_Registry_HKEY_PERFORMANCE_TEXT -2147483568L
#undef rolandomagico_jniregistry_Registry_HKEY_USERS
#define rolandomagico_jniregistry_Registry_HKEY_USERS -2147483645L
/*
 * Class:     rolandomagico_jniregistry_Registry
 * Method:    readLongValue
 * Signature: (ILjava/lang/String;Ljava/lang/String;J)J
 */
JNIEXPORT jlong JNICALL Java_rolandomagico_jniregistry_Registry_readLongValue
  (JNIEnv *, jobject, jint, jstring, jstring, jlong);

/*
 * Class:     rolandomagico_jniregistry_Registry
 * Method:    writeStringValue
 * Signature: (ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_rolandomagico_jniregistry_Registry_writeStringValue
  (JNIEnv *, jobject, jint, jstring, jstring, jstring);

/*
 * Class:     rolandomagico_jniregistry_Registry
 * Method:    readStringValue
 * Signature: (ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_rolandomagico_jniregistry_Registry_readStringValue
  (JNIEnv *, jobject, jint, jstring, jstring, jstring);

#ifdef __cplusplus
}
#endif
#endif
