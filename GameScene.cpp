//
//  Game.cpp
//  gomirhythm
//
//  Created by 南部 晃史 on 2015/01/24.
//
//

#include "GameScene.h"
#include "ofApp.h"
#include "GameOver.h"

//--------------------------------------------------------------
GameScene::GameScene(){
    w = 1024;
    h = 768;
    score = 0;
    
    // MusicScore.xml から時間、ルンバID、ゴミの種類を読み込む
    musicScore = MusicScore(1);
    
    // getPosition で座標を取得する。
    rail = Rail(1);
    ofPoint roombaInitialPos = rail.getPosition(0, 0);
/*    ofPoint trashPos = rail.getPosition(musicScore.MSs[i], musicScore.rIDs[i]);
    trashes.push_back(Trash(10000, 0, 0, 0));
    trashPos = ofPoint(256, 256);
    trashes.push_back(Trash(20000, 0, 0, 1));
    trashPos = ofPoint(384, 384);
    trashes.push_back(Trash(30000, 0, 0, 2));*/
    roombas.push_back(Roomba(roombaInitialPos, rail.vel));
    
    bgImg.loadImage("stage1/background.png");
    bgm.loadSound("stage1/stage1.mp3");
    bgm.play();
    
    numOfTrash = 0;
    // MusicScore からtrash の数に応じたscore のしきい値テーブルを作成する
    for(int i = 0; i < musicScore.MSs.size(); ++i)
    {
        NGScores.push_back(75 * i);
        warnScores.push_back(150 * i);
    }
    // 最初のゴミを配置する
    trashes.push_back(Trash(musicScore.MSs[numOfTrash], 0, musicScore.rIDs[numOfTrash], musicScore.tIDs[numOfTrash]));

    scores.loadFont("vag.ttf", 72);
}

//--------------------------------------------------------------
void GameScene::update(){
    
    if(state == STAGE_CLEAR)
    {
        
    }
    else if(state == GAME_OVER)
    {
        // 背景を吸い込む
        //bgImg(w, h);
        w -= 20;
        h -= 20;
        if(w < 0)
        {
            change_scene(TITLE_SCENE);
            w = 0;
        }
        if(h < 0)
        {
            h = 0;
        }
    }
    else
    {
        ofPoint accel = ofPoint(0.0f, 0.0f);
    
        int bgmPosMS = bgm.getPositionMS();
    
        // 加速度を与えてRoomba を更新する
        for(int i = 0; i < roombas.size(); ++i)
        {
            roombas[i].update(accel);
            score += roombas[i].vacuum(trashes, bgmPosMS);
        }
        // 現在のスコアを判定してRoomba の状態を変更する
        if(score < NGScores[numOfTrash])
        {
            // NG にする
            state = NG;
        }
        else if(score < warnScores[numOfTrash])
        {
            // warn にする
            state = WARN;
        }
        else
        {
            // OK にする
            state = OK;
        }
    
        // BGM の再生時間を取得してtrash の削除判定をする
        vector<Trash>::iterator trashIt = trashes.begin();
        while(trashIt != trashes.end())
        {
            Trash trashTemp = *trashIt;
        
            //trashes の寿命を判定する
            if(!(trashTemp.judgeLife(bgmPosMS)))
            {
                // ゴミを消す
                trashes.erase(trashIt);
            
                // 次のゴミを置く
                if(numOfTrash < musicScore.MSs.size() - 1)
                {
                    ++numOfTrash;
                    trashes.push_back(Trash(musicScore.MSs[numOfTrash], 0, musicScore.rIDs[numOfTrash], musicScore.tIDs[numOfTrash]));
                }
                else
                {
                    // 終了 ステージクリアかゲームオーバーの処理をする
                    if(score < NGScores[numOfTrash])
                    {
                        // ゲームオーバー
                        state = GAME_OVER;
                    }
                    else
                    {
                        // ステージクリア
                        state = STAGE_CLEAR;
                    }
                }
            }
        
            if(trashIt != trashes.end())
            {
                ++trashIt;
            }
        }
    }
}

//--------------------------------------------------------------
void GameScene::draw(){
    bgImg.draw(rail.getPosition(bgm.getPositionMS(), 0).x * (1 - w / 1024.), rail.getPosition(bgm.getPositionMS(), 0).y * (1 - h / 768.), w, w*3/4);
    
    for(int i= 0;i < trashes.size();i++)
    {
        //全てのtrashsの中身を描く
        trashes[i].draw();
    }
    
    // Roomba を描画する
    for(int i = 0; i < roombas.size(); ++i)
    {
        roombas[i].draw(rail.getPosition(bgm.getPositionMS(), i), state);
    }
    rail.draw();
    
    scores.drawString(ofToString(score), 400, 80);
}



//--------------------------------------------------------------
void GameScene::keyPressed(int key){
    
}

//--------------------------------------------------------------
void GameScene::keyReleased(int key){
    
}

//--------------------------------------------------------------
void GameScene::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void GameScene::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void GameScene::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void GameScene::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void GameScene::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void GameScene::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void GameScene::dragEvent(ofDragInfo dragInfo){
    
}
