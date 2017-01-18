//
//  virus.cpp
//  gameOfLife
//
//  Created by Edmund Oetgen on 01/12/2016.
//
//

#include "virusCell.hpp"

void virusCell::setup(ofVec2f pos_, float size_, int state_)
{
    pos     = pos_;
    size    = size_;
    state   = state_;
   
    birth = ofGetElapsedTimef();
    
    
    
    dead.g=1;
    dead.r = 0;
    dead.b=0;
    
    
}

void virusCell::display()
{
    if (state > 0.1){
        dead.g = state;
        
        dead.b = ofMap(age, 0, birth, 0.1, 1) ;
        ofSetColor(dead);
        
        
        ofDrawCircle(pos.x, pos.y, size/2);
       
    }
}

void virusCell::aging()
{
    
    int curTime = ofGetElapsedTimef();
    age = curTime - birth;
   
    state *= 0.9;
    if (state <=0.4) {
        state = 0;
    }
}

void virusCell::feed()
{
    state = 1;
}