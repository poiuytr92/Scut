/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
#include "ScutSmsUtilsjni.h"
#include <android/log.h>

#if defined(SCUT_IPHONE) || defined(SCUT__ANDROID)
#include<errno.h>
#endif

#define  LOG_TAG    "SmsUtils"
#include "Cocos2dJni.h"
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
/* Header for class com_nd_lib_NdUitilityJni */
extern JavaVM *gJavaVM;
/*
jint JNI_OnLoad(JavaVM *vm, void *reserved)
{
	gJavaVM = vm;
	return JNI_VERSION_1_4;
}
*/

struct SmsUtilsMethodJNI
{
	JNIEnv *    env;
	jclass      classID;
	jmethodID   methodID;
};


static bool getMethodID(struct SmsUtilsMethodJNI& t, const char *className, const char *methodName, const char *paramCode)
{
	bool ret = false;
	do 
	{
		if (gJavaVM->GetEnv((void**)&t.env, JNI_VERSION_1_4) != JNI_OK)
		{
			LOGE("Failed to get the environment using GetEnv()");
			break;
		}

		if (gJavaVM->AttachCurrentThread(&t.env, 0) < 0)
		{
			LOGE("Failed to get the environment using AttachCurrentThread()");
			break;
		}

		t.classID = t.env->FindClass(className);
		if (! t.classID)
		{
			LOGE("Failed to find class of %s", className);
			break;
		}

		t.methodID = t.env->GetStaticMethodID(t.classID, methodName, paramCode);
		if (! t.methodID)
		{
			LOGE("Failed to find method id of %s errorno=%s", methodName, strerror(errno));
			break;
		}
		LOGE("Success to find method id of %s", methodName);

		ret = true;
	} while (0);

	return ret;
}

jstring stoJstring( JNIEnv* env, const char* pat )
{
	//定义java String类 strClass
	jclass strClass = (env)->FindClass("Ljava/lang/String;");
	LOGE("FindClass errorno=%s", strerror(errno));
	//获取java String类方法String(byte[],String)的构造器,用于将本地byte[]数组转换为一个新String
	//构造函数作为特例,方法名字为"<init>"
	jmethodID ctorID = (env)->GetMethodID(strClass, "<init>", "([BLjava/lang/String;)V");
	LOGE("GetMethodID errorno=%s", strerror(errno));
	//建立byte数组
	jbyteArray bytes = (env)->NewByteArray(strlen(pat));
	LOGE("NewByteArray errorno=%s", strerror(errno));
	//将char* 转换为byte数组
	(env)->SetByteArrayRegion(bytes, 0, strlen(pat), (jbyte*)pat);
	LOGE("SetByteArrayRegion errorno=%s", strerror(errno));
	// 设置String, 保存语言类型,用于byte数组转换至String时的参数
	jstring encoding = (env)->NewStringUTF("GB2312"); 
	LOGE("NewStringUTF errorno=%s", strerror(errno));
	//将byte数组转换为java String,并输出
	return (jstring)(env)->NewObject(strClass, ctorID, bytes, encoding);
}

bool androidSendSms(std::string strMsg, std::string strTels)
{
	SmsUtilsMethodJNI t;
	char* ret = NULL;

	if (getMethodID(t, 
		"com/nd/lib/SmsUtils",
		"sendMsg",
		"(Ljava/lang/String;Ljava/lang/String;)Z"))
	{
		LOGE("Success androidSendSms strMsg:%s strTels:%s errorno=%s", strMsg.c_str(), strTels.c_str(),strerror(errno));
		{
			jstring jmsg = t.env->NewStringUTF(strMsg.c_str());//stoJstring(t.env, strMsg.c_str());//
			jstring jtels = t.env->NewStringUTF(strTels.c_str());
			t.env->CallStaticObjectMethod(t.classID, t.methodID, jmsg, jtels);
		}
		LOGE("Success androidSendSms errorno=%s", strerror(errno));
		return true;
	}

	return false;
}




