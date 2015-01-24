//
//  Rail.cpp
//  gomirhythm
//
//  Created by 南部 晃史 on 2015/01/24.
//
//

#include "Rail.h"

Rail::Rail(int stage_id){
    stringstream ss;
    ss <<  "stages/stage" << stage_id << ".xml";
    xml.load(ss.str());
    
    xml.pushTag("rails");
    xml.pushTag("rail");
    int numberOfVertices = xml.getNumTags("vertex");
    for (int i = 0; i<numberOfVertices; ++i) {
        xml.pushTag("vertex", i);
        ofPoint p;
        p.x = xml.getValue("x", 0.0);
        p.y = xml.getValue("y", 0.0);
        
        vertices.push_back(p);
        xml.popTag(); // vertex
    }
    xml.popTag(); //rail
    xml.popTag(); //rails
}

void Rail::draw(){
    for (vector<ofPoint>::iterator it = vertices.begin(); it != vertices.end()-1; ++it) {
        ofLine(*it, *(it+1));
    }
}