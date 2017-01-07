//
//  virus.cpp
//  gameOfLife
//
//  Created by Edmund Oetgen on 01/12/2016.
//
//

#include "virusCell.hpp"

void virusCell::setup(ofVec2f pos_, float size_, int state_, int id_)
{
    pos     = pos_;
    size    = size_;
    state   = state_;
    id = id_;
    
    dead.g=1;
    dead.r = 0;
    dead.b=0;
    birth = ofGetElapsedTimef();
    
}


void virusCell::display()
{
    if (state > 0.1){
        dead.g = state;//ofMap(state, 0, 1, 0, 0.5);
       // dead.b = ofMap(state, 0, 1, 255, 0);
    
        
      //  dead.b = (dead.b *= 10)%255;
        ofSetColor(dead);

    
    
        ofDrawRectangle(pos.x, pos.y, size, size);
    
    }
}

void virusCell::aging()
{
    
    int curTime = ofGetElapsedTimef();
    
    age = curTime - birth;
   // if (age >= 50){
   
    state *= 0.9;
    if (state <=0.1) {
        state = 0;
    }
}

void virusCell::feed()
{
    state = 1;
}