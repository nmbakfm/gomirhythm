//
//  Roomba.cpp
//  gomirhythm
//
//  Created by SAWAHATAHiroaki on 2015/01/24.
//
//

#include "Roomba.h"
#include <math.h>

// 判定用
class JudgeArea
{
public:
    string name;
    float radius;
    int score;

    JudgeArea(string areaName, float areaRadius, int areaScore)
    {
        name = areaName;
        radius = areaRadius;
        score = areaScore;
    }
};

vector<JudgeArea> areas;

// コンストラクタ
Roomba::Roomba(ofPoint pos, float vel)
{
    // メンバ変数の初期化をする
    position.set(pos);
    velocity = vel;
    
    // Roomba の画像を読み込む
    roombaImg.loadImage("runba_blue.png");
    size.set(roombaImg.width, roombaImg.height);
    
    // 判定用のエリア設定
    areas.push_back(JudgeArea("Perfect", 20.0f, 300));
    areas.push_back(JudgeArea("Good", 50.0f, 200));
}

// ゴミを吸い込む
int Roomba::vacuum(vector<Trash> &trashes, int currentMS)
{
    // 戻り値（スコア）の宣言
    int score = 0;
    
    // Roomba の中心座標を計算する
    ofPoint roombaPos(roombaImg.width, roombaImg.height);
    roombaPos /= 2;
    roombaPos += position;
    
    vector<Trash>::iterator trashIt = trashes.begin();
    while(trashIt != trashes.end())
    {
        // Trashes のpos を取得する
        Trash* trashTemp = &(*trashIt);
        ofPoint trashPos = trashTemp->position;
        // trash の中心座標を計算する
        trashPos += (trashTemp->size / 2);
        
        // 自分とゴミの距離を計算する
        float distance = sqrt(pow(static_cast<double>(roombaPos.x - trashPos.x), 2.0) +
                              pow(static_cast<double>(roombaPos.y - trashPos.y), 2.0));
        
        // 自分のpos と比較する
        vector<JudgeArea>::iterator areaIt = areas.begin();
        while(areaIt != areas.end())
        {
            JudgeArea areaTemp = *areaIt;
            if((distance <= areaTemp.radius))
            {
                if(ofGetKeyPressed('a'))
                {
                    // 座標が一致してキー入力をしていたら、trash を削除してスコアを加算する
                    trashTemp->vacuumed(areaTemp.name, currentMS);
                    score += areaTemp.score;
                    break;
                }
            }
            ++areaIt;
        }
        
        if(trashIt != trashes.end())
        {
            ++trashIt;
        }
    }
    
    //scorefont.drawString("Score",400,80);
    return score;
}

// 画面更新ごとに呼び出される
void Roomba::update(ofPoint accel)
{
    // pos とvel を更新する
//    pos += vel;
//    vel += accel;
}
    
// ロボット掃除機を描画する
void Roomba::draw(ofPoint pos, int state)
{
    // pos の位置を中心にロボット掃除機を描画する
    position = pos - (size / 2);
    
    switch(state)
    {
        case WARN:
            // 点滅表示させる
            ofSetColor(128);
//            roombaImg.setColor(128);
            roombaImg.draw(position);
            break;
        case NG:
            // 煙を出す
            ofSetColor(0);
//            roombaImg.setColor(255);
            roombaImg.draw(position);
            break;
        default:
            ofSetColor(255);
//            roombaImg.setColor(0);
            roombaImg.draw(position);
            break;
    }
    
//    ofCircle(384, 384, areas[1].radius);
}
