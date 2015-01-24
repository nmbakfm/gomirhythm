//
//  Trash.cpp
//  gomirhythm
//
//  Created by 田上洸貴 on 2015/01/24.
//
//

#include "Trash.h"

//-----------------------------------------------------
string ImageNames[1][3][3] =
{
    {
        // Stage 1
        {"snack.png", "kan_green.png", "book.png"},    // Roomba 1
        {"", "", ""},    // Roomba 2
        {"", "", ""}    // Roomba 3
    }
};

const int lifeMergin = 1000;

Trash::Trash(int msec, int sID, int rID, int tID)
{
    // 仮の処理 最終的にはRail.getPosition を使う
    if (msec == 10000)
    {
        position.set(256, 256);
    }
    else if(msec == 20000)
    {
        position.set(384, 384);
    }
    else
    {
        position.set(512, 512);
    }
    
    string imageName = ImageNames[sID][rID][tID];
    trashImg.loadImage(imageName);
    size.set(trashImg.width, trashImg.height);
    lifeMS = msec + lifeMergin;
    
    font.loadFont("vag.ttf", 72);
}

void Trash::vacuumed(string judge,int currentMS)
{
    font.drawString(judge, position.x, position.y);
    trashImg.clear();
    lifeMS = currentMS + 500;
}

void Trash::draw(){
    //ゴミの絵の表示
    trashImg.draw(position);
}

bool Trash::judgeLife(int currentMS)
{
    return (currentMS < lifeMS);
}