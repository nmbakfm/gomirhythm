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
    bool pressKey;
    
    Roomba(ofPoint pos, float vel);         // コンストラクタ
    int vacuum(vector<Trash> &trashes, int currentMS);    // ゴミを吸い取る
    void update(ofPoint pos);    // 画面更新ごとに呼び出される
    void draw(int state);      // ロボット掃除機を描画する
    
private:
    ofImage roombaImg;
    float radius;
    float deg;
};

// ステージの状態
enum States
{
    OK = 0,
    WARN = 1,
    NG = 2,
    STAGE_CLEAR = 3,
    GAME_OVER = 4
};

#endif /* defined(__gomirhythm__Roomba__) */
