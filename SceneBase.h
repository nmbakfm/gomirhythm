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
};

#endif /* defined(__gomirhythm__SceneBase__) */
