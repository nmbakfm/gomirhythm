#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    scene = new GameScene();
}

//--------------------------------------------------------------
void ofApp::update(){
    scene -> update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    scene -> draw();
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
