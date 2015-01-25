//
//  Trash.h
//  gomirhythm
//
//  Created by 田上洸貴 on 2015/01/24.
//
//

#ifndef __gomirhythm__Trash__
#define __gomirhythm__Trash__

#include "ofMain.h"
#include "SceneBase.h"
#include "Rail.h"

class Trash {
    
public:
    Trash(int msec, int sID, int rID, int tID);
    ofPoint position;
    ofPoint size;
    bool delFlag;
    void draw();
    bool judgeLife(int currentMS);
    void vacuumed(string judge,int currentMS);
    int trashMS;
    
private:
    ofImage trashImg;
    int lifeMS;
    ofTrueTypeFont font;
    string judgeName;
    Rail rail;
};

#endif /* defined(__gomirhythm__Trash__) */
