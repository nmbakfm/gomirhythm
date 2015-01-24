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
#include "Trash.h"



// ロボット掃除機クラス
class Roomba
{
public:
    ofPoint size;
    ofPoint position;    // 位置
    float velocity;    // 速度
    
    Roomba(ofPoint pos, float vel);         // コンストラクタ
    int vacuum(vector<Trash> &trashes, int currentMS);    // ゴミを吸い取る
    void update(ofPoint accel);    // 画面更新ごとに呼び出される 引数：加速度
    void draw(ofPoint pos, int state);      // ロボット掃除機を描画する
    
private:
    ofImage roombaImg;
    float radius;
};

// ステージの状態
enum States
{
    OK,
    WARN,
    NG,
    STAGE_CLEAR,
    GAME_OVER
};

#endif /* defined(__gomirhythm__Roomba__) */
