package com.snail.player;

import android.view.Surface;

/**
 * @Description: 蜗牛播放器
 * @Author: 蜗牛
 * @CreateDate: 2022/5/15 6:11 PM
 * @Version: 1.0
 */
public class SnailPlayer {

    static {
        System.loadLibrary("native-lib");
    }

    public SnailPlayer() {

    }

    public void prepare(String dataSource) {
        prepareNative(dataSource);
    }

    public void start() {
        startNative();
    }

    public void stop() {
        stopNative();
    }

    public void release() {
        releaseNative();
    }

    public void setSurface(Surface surface) {
        //setSurfaceNative(surface);
    }

    public int getDuration() {
        return getDurationNative();
    }

    public void seek(int value) {
        seekNative(value);
    }

    public String getFFmpegVersion() {
        return getFFmpegVersionNative();
    }



    /****************** native函数区域 start *******************/
    /**
     * 动态注册如下函数：
     */
    private native void prepareNative(String dataSource);
    private native void startNative();
    private native void stopNative();
    private native void releaseNative();
    private native void setSurfaceNative(Surface surface);
    private native int getDurationNative();
    private native void seekNative(int value);

    /**
     * 静态注册版本函数
     */
    private native String getFFmpegVersionNative();
    /****************** native函数区域 end *******************/
}
