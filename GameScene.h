//
//  Game.h
//  gomirhythm
//
//  Created by 南部 晃史 on 2015/01/24.
//
//

#ifndef __gomirhythm__Game__
#define __gomirhythm__Game__

#include "ofMain.h"
#include "SceneBase.h"
#include "Trash.h"

class GameScene : public SceneBase {
    int stage;
    
public:
    GameScene();
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
    
    Trash trash;
    //トラッシュクラスの動的配列
    vector<Trash *> trashs;
    
};

#endif /* defined(__gomirhythm__Game__) */
