//
//  Roomba.cpp
//  gomirhythm
//
//  Created by SAWAHATAHiroaki on 2015/01/24.
//
//

#include "Roomba.h"

// コンストラクタ
Roomba::Roomba()
{
    // メンバ変数の初期化をする
    pos.set(0.0f, 0.0f);
    vel.set(1.0f, 1.0f);
    radius = 10.0;
    
    // Roomba の画像を読み込む
    roombaImg.loadImage("runba_blue.png");
}

// ゴミを吸い込む
void Roomba::vacuum()
{
    // Trashes のpos を取得する
    // 自分のpos と比較する
    // 座標が近ければ該当のtrash を削除する
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
//    ofCircle(pos.x, pos.y, radius);
}
