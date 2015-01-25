//
//  GameOver.cpp
//  gomirhythm
//
//  Created by 田上洸貴 on 2015/01/25.
//
//

#include "GameOver.h"

//--------------------------------------------------------------
GameOverScene::GameOverScene(){
    bgImg.loadImage("gameover.png");
}

//--------------------------------------------------------------
void GameOverScene::update(){
    
}

//--------------------------------------------------------------
void GameOverScene::draw(){
    bgImg.draw(0, 0, ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void GameOverScene::keyPressed(int key){
    
}

//--------------------------------------------------------------
void GameOverScene::keyReleased(int key){
    change_scene(TITLE_SCENE);
}

//--------------------------------------------------------------
void GameOverScene::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void GameOverScene::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void GameOverScene::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void GameOverScene::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void GameOverScene::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void GameOverScene::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void GameOverScene::dragEvent(ofDragInfo dragInfo){
    
}
