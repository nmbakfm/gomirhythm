//
//  Game.cpp
//  gomirhythm
//
//  Created by 南部 晃史 on 2015/01/24.
//
//

#include "GameScene.h"

//--------------------------------------------------------------
GameScene::GameScene(){
    score = 0;
    ofPoint trashPos = ofPoint(128, 128);
    trashes.push_back(Trash(10000, 0, 0, 0));
    trashPos = ofPoint(256, 256);
    trashes.push_back(Trash(20000, 0, 0, 1));
    trashPos = ofPoint(384, 384);
    trashes.push_back(Trash(30000, 0, 0, 2));
    roombas.resize(1);
    
    bgm.loadSound("Mixdown.mp3");
    bgm.play();
    rail = Rail(1);
}

//--------------------------------------------------------------
void GameScene::update(){
    ofPoint accel = ofPoint(0.0f, 0.0f);
    
    int bgmPosMS = bgm.getPositionMS();
    
    // 加速度を与えてRoomba を更新する
    for(int i = 0; i < roombas.size(); ++i)
    {
        roombas[i].update(accel);
        score += roombas[i].vacuum(trashes, bgmPosMS);
    }
    
    // BGM の再生時間を取得してtrash の削除判定をする
    vector<Trash>::iterator trashIt = trashes.begin();
    while(trashIt != trashes.end())
    {
        Trash trashTemp = *trashIt;
        
        //trashes の寿命を判定する
        if(!(trashTemp.judgeLife(bgmPosMS)))
        {
            trashes.erase(trashIt);
        }
        
        if(trashIt != trashes.end())
        {
            ++trashIt;
        }
    }
}

//--------------------------------------------------------------
void GameScene::draw(){
//    for(int i= 0;i < trashes.size();i++)
//    {
//        //全てのtrashsの中身を描く
//        trashes[i].draw();
//    }
//    
//    // Roomba を描画する
//    for(int i = 0; i < roombas.size(); ++i)
//    {
//        roombas[i].draw();
//    }
    
    rail.draw();
    
    ofCircle(rail.getPosition(ofGetElapsedTimeMillis(), 1), 10);
}

//--------------------------------------------------------------
void GameScene::keyPressed(int key){
    
}

//--------------------------------------------------------------
void GameScene::keyReleased(int key){
    
}

//--------------------------------------------------------------
void GameScene::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void GameScene::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void GameScene::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void GameScene::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void GameScene::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void GameScene::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void GameScene::dragEvent(ofDragInfo dragInfo){
    
}
