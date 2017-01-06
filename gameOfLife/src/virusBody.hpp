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
    
        void setup( int cellSize_, int cols_,int rows_, int id);
    void init();
        void addCell(int x, int y);
        void display();
        void grow( );
        ofVec2f calculateNewPos(Cell * cell);
        void eat( Cell * cell);
        void hunt(int x, int y, vector<vector<Cell*>> cellGrid);
    vector <ofVec2f *> findPostions();
    void kill(ofVec2f * pos);
    
    vector<vector<virusCell *>> parts;
    vector<ofVec2f * > positions;
    vector<ofVec2f> newPositions;
    vector<ofVec2f> initPositions;
    

    bool infected;
    
    int length;
    int cellSize;
    int initID;
    int spaces;
    int cols;
    int rows;
    int id;
};