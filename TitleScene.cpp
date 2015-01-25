//
//  TitleScene.cpp
//  gomirhythm
//
//  Created by 南部 晃史 on 2015/01/25.
//
//

#include "TitleScene.h"

//--------------------------------------------------------------
TitleScene::TitleScene(){
    bgImg.loadImage("title.png");
    start.loadSound("start.mp3");
    
    bgm.loadSound("title.mp3");
    bgm.setLoop(true);
    if(bgm.isLoaded()) bgm.play();
}

//--------------------------------------------------------------
void TitleScene::update(){
    
}

//--------------------------------------------------------------
void TitleScene::draw(){
    bgImg.draw(0, 0, ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void TitleScene::keyPressed(int key){
    
}

//--------------------------------------------------------------
void TitleScene::keyReleased(int key){
    start.play();
    change_scene(GAME_SCENE);
}

//--------------------------------------------------------------
void TitleScene::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void TitleScene::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void TitleScene::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void TitleScene::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void TitleScene::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void TitleScene::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void TitleScene::dragEvent(ofDragInfo dragInfo){
    
}
