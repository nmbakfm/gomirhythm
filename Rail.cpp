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
    
    // xmlをロード
    ss <<  "stages/stage" << stage_id << ".xml";
    xml.load(ss.str());
    
    // xmlをパース
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
    
    // 全長と、それぞれのポイントの長さを計算
    all_length = 0;
    for(vector<ofPoint>::iterator it = vertices.begin(); it != vertices.end()-1; ++it){
        float current_line_length = ofDist(it->x, it->y, (it+1)->x, (it+1)->y);
        all_length += current_line_length;
        lengths.push_back(current_line_length);
    }
    
    // @todo: Roombaの速度をMusicScoreのほうとあわせる。
    vel = 0.1;
}

ofPoint Rail::getPosition(int ms, int roomba_id){
    // 最終地点まで行ったら、その地点を返す。
    if (ms * vel > all_length){
        return vertices[vertices.size()-1];
    }
    
    float displacement_length = 0;
    float rest;
    float current_line_id;
    
    // その時間での位置を計算して返す
    for(int i = 0; lengths.size() > i; ++i){
        displacement_length += lengths[i];
        if (displacement_length > ms * vel) {
            rest = displacement_length - ms * vel;
            current_line_id = i;
            break;
        }
    }
    float rest_ratio = rest/lengths[current_line_id];
    return rest_ratio * vertices[current_line_id] + (1-rest_ratio) * vertices[current_line_id+1];
}

void Rail::update(){
    hue ++;
    if(hue > 255) hue = 0;
}

void Rail::draw(){
    // 移動する軌跡を表示
    ofColor col;
    col.setHsb(hue, 255, 255);
    ofSetColor(col);
    ofSetLineWidth(5);
    for (vector<ofPoint>::iterator it = vertices.begin(); it != vertices.end()-1; ++it) {
        ofLine(*it, *(it+1));
    }
}
