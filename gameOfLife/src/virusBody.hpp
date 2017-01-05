//
//  virusBody.hpp
//  gameOfLife
//
//  Created by Edmund Oetgen on 13/12/2016.
//
//

#pragma once

#include "ofMain.h" 
#include "virusCell.hpp"

class virusBody
{
    public:
    
        void setup(ofVec2f initPos, int spaces_, int cellSize_, int cols_,int rows_);
        void addCell(ofVec2f  pos);
        void display();
        void grow();
        ofVec2f calculateNewPos(ofVec2f oldPos);
    
   
    vector<virusCell *> parts;
    vector<ofVec2f > positions;
    vector<ofVec2f> newPositions;
    vector<ofVec2f> initPositions;
    

    
    
    int length;
    int cellSize;
    int initID;
    int spaces;
    int cols;
    int rows;
};