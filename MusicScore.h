//
//  MusicScore.h
//  gomirhythm
//
//  Created by 南部 晃史 on 2015/01/24.
//
//

#ifndef __gomirhythm__MusicScore__
#define __gomirhythm__MusicScore__

#include "ofMain.h"
#include "ofxXmlSettings.h"

class MusicScore {
    
public:
    MusicScore(){};
    MusicScore(int stage_id);
    
    ofxXmlSettings xml;
    vector<int> MSs;
    vector<int> rIDs;
    vector<int> tIDs;
};

#endif /* defined(__gomirhythm__MusicScore__) */
