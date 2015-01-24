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

    void SetParam(string areaName, float areaRadius)
    {
        name = areaName;
        radius = areaRadius;
    }
};

vector<JudgeArea> areas;

// コンストラクタ
Roomba::Roomba()
{
    // メンバ変数の初期化をする
    pos.set(0.0f, 0.0f);
    vel.set(1.0f, 1.0f);
    radius = 10.0;
    
    // Roomba の画像を読み込む
    roombaImg.loadImage("runba_blue.png");
    
    // 判定用のエリア設定
    areas.resize(2);
    areas[0].SetParam("Perfect", 20.0f);
    areas[1].SetParam("Good", 50.0f);
}

// ゴミを吸い込む
void Roomba::vacuum(vector<Trash> &trashes)
{
    // Roomba の中心座標を計算する
    ofPoint roombaPos(roombaImg.width, roombaImg.height);
    roombaPos /= 2;
    roombaPos += pos;
    
    vector<Trash>::iterator trashIt = trashes.begin();
    while(trashIt != trashes.end())
    {
        // Trashes のpos を取得する
        Trash trashTemp = *trashIt;
        ofPoint trashPos = trashTemp.position;
        // trash の中心座標を計算する
        trashPos += (trashTemp.size / 2);
        
        // 自分のpos と比較する
        float distance = sqrt(pow(static_cast<double>(roombaPos.x - trashPos.x), 2.0) +
                              pow(static_cast<double>(roombaPos.y - trashPos.y), 2.0));
        vector<JudgeArea>::iterator areaIt = areas.begin();
        while(areaIt != areas.end())
        {
            JudgeArea areaTemp = *areaIt;
            if((distance <= areaTemp.radius) && (ofGetKeyPressed('a')))
            {
                // 座標が一致したらtrash を削除する
                trashes.erase(trashIt);
                break;
            }
            ++areaIt;
        }
        
        if(trashIt != trashes.end())
        {
            ++trashIt;
        }
    }

}

// 画面更新ごとに呼び出される
void Roomba::update(ofPoint accel)
{
    // pos とvel を更新する
    pos += vel;
    vel += accel;
}
    
// ロボット掃除機を描画する
void Roomba::draw()
{
    // pos の位置にロボット掃除機を描画する
    roombaImg.draw(pos);
    ofCircle(384, 384, areas[1].radius);
//    ofCircle(pos.x, pos.y, radius);
}
