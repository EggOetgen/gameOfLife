//
//  Cell.cpp
//  gameOfLife
//
//  Created by Edmund Oetgen on 11/11/2016.
//
//

#include "Cell.hpp"

Cell::Cell(){
    
}

void Cell::setup(float x_, float y_, float size_, int state_)
    {
        x        = x_;
        y        = y_;
        size     = size_;
        state    = state_;
        previous = state;
        
        alive = (255);
        dead.r=255;
        dead.g = 0;
        dead.b=1;
        
    }

void Cell::display()
    {
        if      (state == 0)
                    ofSetColor(50);
        else if (state ==1)
                    ofSetColor(0);
        
        else if (state ==2){
            
            dead.r *= 0.9999999;
           // if(dead.b < 255)
           dead.b = (dead.b *= 10)%255;
             ofSetColor(dead);
        }
       
        
        ofDrawRectangle(x, y, size, size);                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
    }

void Cell::savePrevious()
    {
        previous = state;
       
    }

void Cell::checkState(int neighbours, int hunters)
    {
        
        
        float chance = ofRandom(1);
             if (state == 1 && neighbours < 2)
             {
                     state = 0;
             }
        else if (state == 1 && neighbours > 3)
                state = 0;
        else if (state == 1 && hunters > 0)
            state = 2;
        else if (state == 0 && neighbours == 3)
                state = 1;
        
        else if (state == 2 && neighbours == 3)
            state = 1;
       
        else if(chance <=0.0000001)
                state = 2;
        else
            state = previous;
        
    }
void Cell::god(int mouseX, int mouseY)
    {
        if (mouseX > x && mouseX < x + size
            && mouseY > y && mouseY < y + size)
        {
            state = 2;
            previous = 2;
        }
    }








