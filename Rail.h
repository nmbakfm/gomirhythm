//
//  Rail.h
//  gomirhythm
//
//  Created by 南部 晃史 on 2015/01/24.
//
//

#ifndef __gomirhythm__Rail__
#define __gomirhythm__Rail__

#include "ofMain.h"
#include "ofxXmlSettings.h"

class Rail {
    
public:
    Rail(){};
    Rail(int stage_id);
    void draw();
    
    ofxXmlSettings xml;
    vector<ofPoint> vertices;
};

#endif /* defined(__gomirhythm__Rail__) */
