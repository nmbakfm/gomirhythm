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
    trashes.resize(1);
    roombas.resize(1);
}

//--------------------------------------------------------------
void GameScene::update(){
    ofPoint accel = ofPoint(0.0f, 0.0f);
    // 加速度を与えてRoomba を更新する
    for(int i = 0; i < roombas.size(); ++i)
    {
        roombas[i].update(accel);
    }
}

//--------------------------------------------------------------
void GameScene::draw(){
    for(int i= 0;i < trashes.size();i++)
    {
        //全てのtrashsの中身を描く
        trashes[i].draw();
    }
    
    // Roomba を描画する
    for(int i = 0; i < roombas.size(); ++i)
    {
        roombas[i].draw();
    }
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
