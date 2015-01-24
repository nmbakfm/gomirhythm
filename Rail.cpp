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
    all_length = 0;
    for(vector<ofPoint>::iterator it = vertices.begin(); it != vertices.end()-1; ++it){
        float current_line_length = ofDist(it->x, it->y, (it+1)->x, (it+1)->y);
        all_length += current_line_length;
        lengths.push_back(current_line_length);
    }
    vel = 0.1;
}

ofPoint Rail::getPosition(int ms, int roomba_id){
    if (ms * vel > all_length){
        return vertices[vertices.size()-1];
    }
    
    float displacement_length = 0;
    float rest;
    float current_line_id;
    
    for(int i = 0; lengths.size() > i; ++i){
        displacement_length += lengths[i];
        if (displacement_length > ms * vel) {
            rest = displacement_length - ms * vel;
            current_line_id = i;
            break;
        }
    }
    cout << "current_line_id:" << current_line_id << endl;
    cout << "vertices_num" << vertices.size() << endl;
    cout << "move_length" << ms * vel << endl;
    float rest_ratio = rest/lengths[current_line_id];
    return rest_ratio * vertices[current_line_id] + (1-rest_ratio) * vertices[current_line_id+1];
}

void Rail::draw(){
    for (vector<ofPoint>::iterator it = vertices.begin(); it != vertices.end()-1; ++it) {
        ofLine(*it, *(it+1));
    }
}