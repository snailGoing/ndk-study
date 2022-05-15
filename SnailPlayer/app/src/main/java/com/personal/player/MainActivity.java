package com.personal.player;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import com.snail.player.SnailPlayer;

/**
 * @author snail
 */
public class MainActivity extends AppCompatActivity {

    private String TAG = "SnailGoing";

    private Button bt_version;
    private TextView tv_msg;
    private SnailPlayer snailPlayer;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        initView();
        initData();
    }

    private void initData() {
        snailPlayer = new SnailPlayer();
    }

    private void initView() {
        bt_version = findViewById(R.id.bt_version);
        tv_msg = findViewById(R.id.tv_msg);
        bt_version.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String text = snailPlayer.getFFmpegVersion();
                Log.d(TAG, "" + text);
                tv_msg.setText(text);
            }
        });
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        snailPlayer = null;
    }
}