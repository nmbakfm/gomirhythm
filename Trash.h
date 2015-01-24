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

class Trash {
    
public:
    Trash();
    ofPoint position;
    void draw();
    
private:
    ofImage trashImg;
    
};

#endif /* defined(__gomirhythm__Trash__) */
