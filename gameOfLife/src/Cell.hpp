//
//  Cell.hpp
//  gameOfLife
//
//  Created by Edmund Oetgen on 11/11/2016.
//
//

#pragma once


#include "ofApp.h"

class Cell {

public:
    //METHOD;
    void setup(float x_, float y_, float size_, int state_);
    void display();
    void savePrevious();
   // bool checkNeighbors(int NW, int N, int NE, int W, int E, int SW, int S, int SE);
    
    
    //VARIABLES
    float x;
    float y;
    float size;
    int state;
    int previous;
    

    Cell();

};


