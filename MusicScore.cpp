//
//  MusicScore.cpp
//  gomirhythm
//
//  Created by 南部 晃史 on 2015/01/24.
//
//

#include "MusicScore.h"

MusicScore::MusicScore(int stage_id)
{
    stringstream ss;
    ss <<  "scores/stage" << stage_id << ".xml";
    xml.load(ss.str());
    
    xml.pushTag("trashes");
    int numberOfTrashes = xml.getNumTags("trash");
    for (int i = 0; i<numberOfTrashes; ++i) {
        xml.pushTag("trash", i);
        int msec = xml.getValue("msec", 0);
        int rID = xml.getValue("roomba", 0);
        int tID = xml.getValue("type", 0);
        MSs.push_back(msec);
        int appearMS = msec - 5000;
        if(appearMS < 0)
        {
            appearMS = 0;
        }
        appearMSs.push_back(appearMS);
        rIDs.push_back(rID);
        tIDs.push_back(tID);
        xml.popTag(); // trash
    }
    xml.popTag(); // trashes
}
