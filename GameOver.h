//
//  GameOver.h
//  gomirhythm
//
//  Created by 田上洸貴 on 2015/01/25.
//
//

#ifndef __gomirhythm__GameOver__
#define __gomirhythm__GameOver__

#include "SceneBase.h"

class GameOverScene : public SceneBase {
    ofSoundPlayer bgm;
    ofImage bgImg;
    
public:
    GameOverScene();
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

#endif /* defined(__gomirhythm__GameOver__) */
