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
    
        void setup(int x, int y);
        void addCell(int x, int y);
        void display();
        void grow();
   
    vector<virusCell *> parts;
    
    
    int length;
    int cellSize = 10;
    int initID = 0;
};