//
//  TitleScene.h
//  gomirhythm
//
//  Created by 南部 晃史 on 2015/01/25.
//
//

#ifndef __gomirhythm__TitleScene__
#define __gomirhythm__TitleScene__

#include "SceneBase.h"

class TitleScene : public SceneBase {
    ofSoundPlayer bgm;
    ofImage bgImg;
    
public:
    TitleScene();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
};

#endif /* defined(__gomirhythm__TitleScene__) */
