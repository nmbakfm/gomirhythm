#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    scene = new TitleScene();
    fade_alpha = 255;
}

//--------------------------------------------------------------
void ofApp::update(){
    scene -> update();
    
    if(scene -> bChangeScene){
        if(fade_alpha < 255) fade_alpha += 5;
        else nextScene(scene -> to);
    }else{
        if(fade_alpha > 0) fade_alpha -= 5;
    }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    scene -> draw();
    
    ofSetColor(255, fade_alpha);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    scene -> keyPressed(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    scene -> keyReleased(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    scene -> mouseMoved(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    scene -> mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    scene -> mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    scene -> mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    scene -> windowResized(w, h);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    scene -> gotMessage(msg);
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    scene -> dragEvent(dragInfo);
}

void ofApp::nextScene(SCENE to){
    switch (to) {
        case GAME_SCENE:
            scene = new GameScene();
            break;
        case TITLE_SCENE:
            scene = new TitleScene();
            break;
        case GAME_OVER_SCENE:
            scene = new GameOverScene();
        default:
            break;
    }
}
