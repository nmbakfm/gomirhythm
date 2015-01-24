//
//  Roomba.h
//  gomirhythm
//
//  Created by SAWAHATAHiroaki on 2015/01/24.
//
//

#ifndef __gomirhythm__Roomba__
#define __gomirhythm__Roomba__

#include "ofMain.h"

// ロボット掃除機クラス
class Roomba
{
public:
    ofPoint pos;    // 位置
    ofPoint vel;    // 速度
    
    Roomba();         // コンストラクタ
    void vacuum();    // ゴミを吸い取る
    void update(ofPoint accel);    // 画面更新ごとに呼び出される 引数：加速度
    void draw();      // ロボット掃除機を描画する
    
private:
    ofImage roombaImg;
    float radius;
};

#endif /* defined(__gomirhythm__Roomba__) */
