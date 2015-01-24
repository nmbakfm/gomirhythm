//
//  SceneBase.h
//  gomirhythm
//
//  Created by 南部 晃史 on 2015/01/24.
//
//

#ifndef __gomirhythm__SceneBase__
#define __gomirhythm__SceneBase__

#include "ofMain.h"

class SceneBase {
    
public:
    SceneBase(){};
    virtual void update() = 0;
    virtual void draw() = 0;
    
    virtual void keyPressed(int key) = 0;
    virtual void keyReleased(int key) = 0;
    virtual void mouseMoved(int x, int y ) = 0;
    virtual void mouseDragged(int x, int y, int button) = 0;
    virtual void mousePressed(int x, int y, int button) = 0;
    virtual void mouseReleased(int x, int y, int button) = 0;
    virtual void windowResized(int w, int h) = 0;
    virtual void dragEvent(ofDragInfo dragInfo) = 0;
    virtual void gotMessage(ofMessage msg) = 0;
};

#endif /* defined(__gomirhythm__SceneBase__) */
