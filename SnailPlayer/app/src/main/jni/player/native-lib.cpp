//
// Created by SnailGoing on 2022/5/15.
//

#include <jni.h>
#include <string>
#include <assert.h>

extern "C"{
    #include <libavutil/avutil.h>
}


JavaVM *vm = nullptr;

void prepare(JNIEnv *env, jobject thiz, jstring source) {

}

void start(JNIEnv *env, jobject thiz) {

}

void seek(JNIEnv *env, jobject thiz, jint value) {

}

void stop(JNIEnv *env, jobject thiz) {

}

void setSurface(JNIEnv *env, jobject thiz, jobject surface) {

}

jint getDuration(JNIEnv *env, jobject thiz) {

}

void release(JNIEnv *env, jobject thiz) {

}

/**
 * 动态注册
 */
static const char* const snailPlayerClass = "com/snail/player/SnailPlayer";
/**
 * 动态注册方法
 * {java层方法名, (参数)返回值, (void*)注册方法}
 */
static JNINativeMethod gMethods[] = {
        {"prepareNative", "(Ljava/lang/String;)V",(void *)prepare},
        {"startNative", "()V", (void *)start},
        {"seekNative", "(I)V", (void *)seek},
        {"stopNative", "()V", (void *)stop},
        {"releaseNative", "()V", (void *)release},
        {"setSurfaceNative", "(Landroid/view/Surface;)V", (void *)setSurface},
        {"getDurationNative", "()I", (void *)getDuration}
};

/**
 * 动态注册
 * @param env
 * @param className
 * @param gMethods
 * @param numMethods
 * @return
 */
static int registerMethods(JNIEnv *env, const char *className,
                           JNINativeMethod *gMethods, int numMethods) {
    jclass clazz = env->FindClass(className);
    if (clazz == NULL) {
        return JNI_FALSE;
    }
    //注册native方法
    if (env->RegisterNatives(clazz, gMethods, numMethods) < 0) {
        return JNI_FALSE;
    }
    return JNI_TRUE;
}

extern "C" JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    ::vm = vm;
    JNIEnv *env = NULL;
    if (vm->GetEnv((void **) &env, JNI_VERSION_1_6) != JNI_OK) {
        return JNI_ERR;
    }
    assert(env != NULL);

    // 注册native方法
    if (!registerMethods(env, snailPlayerClass, gMethods, sizeof(gMethods) / sizeof(gMethods[0]))) {
        return JNI_ERR;
    }

    return JNI_VERSION_1_6;
}

/**
 * 静态注册
 */
extern "C" JNIEXPORT jstring JNICALL Java_com_snail_player_SnailPlayer_getFFmpegVersionNative(
        JNIEnv *env, jobject thiz) {
    std::string info = "FFmpeg的版本号是:";
    info.append(av_version_info());
    return env->NewStringUTF(info.c_str());
}