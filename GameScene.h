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
#include "Roomba.h"

class GameScene : public SceneBase {
    int stage;
    int score;
    
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
    
    //トラッシュクラスの動的配列
    vector<Trash> trashes;

    // ロボット掃除機の実体宣言
    vector<Roomba> roombas;
};

#endif /* defined(__gomirhythm__Game__) */
