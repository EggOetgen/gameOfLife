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
    
        void setup(ofVec2f initPos, int spaces_);
        void addCell(ofVec2f pos);
        void display();
        void grow();
        ofVec2f calculateNewPos(const ofVec2f & prevPos);
   
    vector<virusCell *> parts;
    vector<ofVec2f> positions;
    
    
    int length;
    int cellSize;
    int initID;
    int spaces;
};