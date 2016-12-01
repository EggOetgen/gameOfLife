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
    void checkState(int neighbors, int hunters);
    void god(int mouseX, int mouseY);
    
    
    //VARIABLES
    float x;
    float y;
    int size;
    int state;
    int previous;
    
    ofColor alive;
    ofColor dead;
    ofColor prevColor;
    

    Cell();

};


