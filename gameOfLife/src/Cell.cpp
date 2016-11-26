//
//  Cell.cpp
//  gameOfLife
//
//  Created by Edmund Oetgen on 11/11/2016.
//
//

#include "Cell.hpp"

//Cell::Cell(){
    
//}

void Cell::setup(float x_, float y_, float size_, int state_)
    {
        x        = x_;
        y        = y_;
        size     = size_;
        state    = state_;
        previous = state;
    }

void Cell::display()
    {
        if (state == 0)
            ofSetColor(255);
        else
            ofSetColor(0);
        
        ofDrawRectangle(x, y, size, size);                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
    }

void Cell::savePrevious()
    {
        previous = state;
    }

