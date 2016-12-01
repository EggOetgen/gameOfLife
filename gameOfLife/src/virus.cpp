//
//  virus.cpp
//  gameOfLife
//
//  Created by Edmund Oetgen on 01/12/2016.
//
//

#include "virus.hpp"

void virus::setup()
{
    history.assign(5, 0);
    
    contaminated = true;
    
    dead.r=255;
    dead.g = 0;
    dead.b=1;
}

void virus::display()
{
    if      (state == 0){
        if(dead.r > 100)
        dead.r *= 0.9999999999999;
        
        dead.b = (dead.b *= 10)%255;
        ofSetColor(dead);
}
    else if (state ==1){
        dead.b = (dead.b *= 10)%255;
        ofSetColor(dead);
    }
    
    ofDrawRectangle(x, y, size, size);
    
}
