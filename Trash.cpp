//
//  Trash.cpp
//  gomirhythm
//
//  Created by 田上洸貴 on 2015/01/24.
//
//

#include "Trash.h"
#include "Rail.h"

//-----------------------------------------------------
string ImageNames[1][3][6] =
{
    {
        // Stage 1
        {"stage1/book.png", "stage1/denti.png", "stage1/game_character.png", "stage1/irui.png", "stage1/men.png", "stage1/snack.png"},    // Roomba 1
        {"", "", ""},    // Roomba 2
        {"", "", ""}    // Roomba 3
    }
};

const int lifeMergin = 1000;

Trash::Trash(int msec, int sID, int rID, int tID)
{
    string imageName = ImageNames[sID][rID][tID];
    trashImg.loadImage(imageName);
    size.set(trashImg.width, trashImg.height);
    
    rail = Rail(sID + 1);
    ofPoint pos = rail.getPosition(msec, rID);
    position.set(pos - (size / 2));
    
    lifeMS = msec + lifeMergin;
    
    font.loadFont("vag.ttf", 72);
}

void Trash::vacuumed(string judge, int currentMS)
{
    judgeName = judge;
    trashImg.clear();
    lifeMS = currentMS + 500;
}

void Trash::draw(){
    //ゴミの絵の表示
    trashImg.draw(position);
    font.drawString(judgeName, position.x, position.y);
    
    
}

bool Trash::judgeLife(int currentMS)
{
    return (currentMS < lifeMS);
}