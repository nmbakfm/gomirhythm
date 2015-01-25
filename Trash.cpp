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
string ImageNames[1][3][12] =
{
    {
        // Stage 1
        {"stage1/book.png", "stage1/denti.png", "stage1/game_character.png", "stage1/irui.png",
         "stage1/men.png", "stage1/snack.png", "stage1/can.png", "stage1/kinoko.png", "stage1/negi.png",
         "stage1/penguin.png", "stage1/sakana.png", "stage1/zassi.png"},    // Roomba 1
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
    delFlag = false;
    lifeMS = msec + lifeMergin;
    trashMS = msec;
    
    font.loadFont("vag.ttf", 72);
}

void Trash::vacuumed(string judge, int currentMS)
{
    judgeName = judge;
    trashImg.clear();
    lifeMS = currentMS + 500;
    delFlag = true;
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