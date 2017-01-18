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
    
        void setup( int cellSize_, int cols_,int rows_);
    void init();
        void addCell(int x, int y);
        void display();
        void grow( );
        void clear ();
    
    
    vector <ofVec2f *> findPostions();
    
    vector<vector<virusCell *>> parts;
    vector<ofVec2f * > positions;
 
   
   
    
    int length;
    int cellSize;
    int initID;
    int spaces;
    int cols;
    int rows;
   
};