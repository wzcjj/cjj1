package com.example.administrator.button_test;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

/**
 * Created by Administrator on 2015/1/17.
 */
public class MainActivity extends Activity{
    private Button but = null;
    public void onCreate(Bundle aaa){
        super.onCreate(aaa);
        super.setContentView(R.layout.activity_main);
        this.but = (Button) super.findViewById(R.id.button);
        but.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                but.setText("clicked");
            }
        });
    }

}
