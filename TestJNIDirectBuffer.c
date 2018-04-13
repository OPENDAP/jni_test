//
#include <jni.h>
#include <stdio.h>
#include "TestJNIDirectBuffer.h"

JNIEXPORT void JNICALL Java_TestJNIDirectBuffer_write(JNIEnv *env, jobject thisObj, jobject buffer) 
{
  
  jclass thisClass = (*env)->GetObjectClass(env,thisObj);

  jmethodID bufCompleteCallBack = (*env)->GetMethodID(env, thisClass, "complete", "()V");
  if (NULL == bufCompleteCallBack) return;
  
  jbyte* dbStart = (*env)->GetDirectBufferAddress(env,buffer);
  jlong dbSize = (*env)->GetDirectBufferCapacity(env,buffer);

  for (int i=0; i<dbSize /*1000*/; i++) 
    {
      dbStart[i] = i % 127;
    }

  (*env)->CallVoidMethod(env,thisObj,bufCompleteCallBack);

}

JNIEXPORT jdouble JNICALL Java_TestJNIDirectBuffer_size(JNIEnv *env, jobject thisObj, jobject buffer)
{  

  jbyte* dbStart = (*env)->GetDirectBufferAddress(env,buffer);
  jlong dbSize = (*env)->GetDirectBufferCapacity(env,buffer);
  jdouble result;

  printf("In C, the size of the direct buffer is %ld\n",dbSize);

  result = (jdouble)dbSize*2;

  printf("In C, the size * 2 as a double is %g\n", result);
  
  return result;

}
