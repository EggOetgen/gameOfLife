//
//  virus.cpp
//  gameOfLife
//
//  Created by Edmund Oetgen on 01/12/2016.
//
//

#include "virusCell.hpp"

void virusCell::setup(float x_, float y_, float size_, int state_, int id)
{
    x        = x_;
    y        = y_;
    size     = size_;
    state    = state_;

    dead.g=255;
    dead.r = 0;
    dead.b=1;
    
}


void virusCell::display()
{
   
        dead.g = ofMap(state, 0, 1, 100, 255);
        
        dead.b = (dead.b *= 10)%255;
        ofSetColor(dead);

    
    
        ofDrawRectangle(x, y, size, size);
    
    
}
