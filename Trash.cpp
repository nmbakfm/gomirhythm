//
//  Trash.cpp
//  gomirhythm
//
//  Created by 田上洸貴 on 2015/01/24.
//
//

#include "Trash.h"

//-----------------------------------------------------
enum Images
{
    SNACK = 1,
    KAN,
    BOOK
};

Trash::Trash(ofPoint pos, int imgId)
{
    position.set(pos);
    
    switch(imgId)
    {
        case SNACK:
            trashImg.loadImage("snack.png");
            break;
        case KAN:
            trashImg.loadImage("kan_green.png");
            break;
        case BOOK:
            trashImg.loadImage("book.png");
            break;
        default:
            ;
    }
    size.set(trashImg.width, trashImg.height);
    delFlag = false;
}

void Trash::draw(){
    //ゴミの絵の表示
    trashImg.draw(position);
    
}
