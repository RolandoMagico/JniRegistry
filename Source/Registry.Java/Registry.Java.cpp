/***********************************************************************************************************************
 MIT License

 Copyright(c) 2020 Roland Reinl

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files(the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions :

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
***********************************************************************************************************************/

/***********************************************************************************************************************
 INCLUDES
***********************************************************************************************************************/
#include "rolandomagico_jniregistry_Registry.h"
#include <windows.h>

/***********************************************************************************************************************
 DEFINES
***********************************************************************************************************************/

/***********************************************************************************************************************
 TYPES
***********************************************************************************************************************/

/***********************************************************************************************************************
 LOCAL CONSTANTS
***********************************************************************************************************************/

/***********************************************************************************************************************
 LOCAL VARIABLES
***********************************************************************************************************************/

/***********************************************************************************************************************
 LOCAL FUNCTION DECLARATIONS
***********************************************************************************************************************/

/***********************************************************************************************************************
 IMPLEMENTATION
***********************************************************************************************************************/
LSTATUS ReadRegistry(JNIEnv* env, jint hKey, jstring location, jstring key, PVOID buffer, LPDWORD bufferLength)
{
  DWORD pdwType;
  const char *nativeKey = env->GetStringUTFChars(key, FALSE);
  const char *nativeLocation = env->GetStringUTFChars(location, FALSE);

  LSTATUS status = RegGetValueA(((HKEY)(ULONG_PTR)((LONG)hKey)), nativeLocation, nativeKey, RRF_RT_ANY, &pdwType, buffer, bufferLength);

  env->ReleaseStringUTFChars(key, nativeKey);
  env->ReleaseStringUTFChars(location, nativeLocation);

  return status;
}

JNIEXPORT jlong JNICALL Java_rolandomagico_jniregistry_Registry_readLongValue(JNIEnv* env, jobject, jint hKey, jstring location, jstring key, jlong defaultValue)
{
	long buffer;
	DWORD bufferLength = sizeof(buffer);
	
  if (ReadRegistry(env, hKey, location, key, &buffer, &bufferLength) == ERROR_SUCCESS)
  {
    return buffer;
  }
  else
  {
    return defaultValue;
  }
}

JNIEXPORT jstring JNICALL Java_rolandomagico_jniregistry_Registry_readStringValue(JNIEnv* env, jobject, jint hKey, jstring location, jstring key, jstring defaultValue)
{
	char buffer[1024];
	DWORD bufferLength = sizeof(buffer);

  if (ReadRegistry(env, hKey, location, key, &buffer, &bufferLength) == ERROR_SUCCESS)
	{
		return env->NewStringUTF(buffer);
	}
	else
	{
		return defaultValue;
	}
}

JNIEXPORT void JNICALL Java_rolandomagico_jniregistry_Registry_writeStringValue(JNIEnv* env, jobject, jint hKey, jstring location, jstring key, jstring value)
{
  const char* nativeKey = env->GetStringUTFChars(key, FALSE);
  const char* nativeLocation = env->GetStringUTFChars(location, FALSE);
  const char* nativeValue = env->GetStringUTFChars(value, FALSE);

  HKEY localKey;

  size_t size = strlen(nativeLocation) + 1;
  wchar_t* nativeLocation_wc = new wchar_t[size];
  size_t outSize;
  mbstowcs_s(&outSize, nativeLocation_wc, size, nativeLocation, size - 1);
  RegOpenKeyEx(((HKEY)(ULONG_PTR)((LONG)hKey)), nativeLocation_wc, 0, KEY_SET_VALUE, &localKey);
  LSTATUS status = RegSetValueExA(localKey, nativeKey, NULL, REG_SZ, (const BYTE *)nativeValue, (DWORD)(strlen(nativeValue) + 1));
  RegCloseKey(localKey);

  env->ReleaseStringUTFChars(key, nativeKey);
  env->ReleaseStringUTFChars(location, nativeLocation);
  env->ReleaseStringUTFChars(value, nativeValue);
}

/***********************************************************************************************************************
 EOF
***********************************************************************************************************************/