//
//  Trash.cpp
//  gomirhythm
//
//  Created by 田上洸貴 on 2015/01/24.
//
//

#include "Trash.h"

//-----------------------------------------------------
Trash::Trash()
{
    position.set(256,256);
    
    trashImg.loadImage("snack.png");
    size.set(trashImg.width, trashImg.height);
}

void Trash::draw(){
    //ゴミの絵の表示
    trashImg.draw(position);
    
}
