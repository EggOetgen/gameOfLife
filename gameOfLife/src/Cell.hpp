//
//  Cell.hpp
//  gameOfLife
//
//  Created by Edmund Oetgen on 11/11/2016.
//
//

#pragma once


#include "ofMain.h"

class Cell {

public:
    //METHOD;
    void setup(float x_, float y_, float size_, int state_);
    void display();
    void savePrevious();
    void checkState(int neighbors);
    
    
    //VARIABLES
    float x;
    float y;
    float size;
    int state;
    int previous;
    

    Cell();

};


