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

void Cell::setup(float x_, float y_, float size_, int state_, float lifeRate_)
    {
        x        = x_;
        y        = y_;
        size     = size_;
        state    = state_;
        previous = state;
        lifeRate = lifeRate_;
        
        drawNorm = false;
        
        dead.r=80;
        dead.g = 0;
        dead.b=1;
        
    }

void Cell::display()
    {
      if (state ==1)
      {
          if(drawNorm){
        ofSetColor(0);
        
        ofDrawRectangle(x, y, size, size);
          }
      }
        else if (state ==2){
            
            if(dead.r > 20)
            dead.r *= 0.999999999999;
           
           dead.b = (dead.b *= 10)%255;
             ofSetColor(dead);
            
            ofDrawCircle(x, y, size/2);
        }
       
      
       
    }

void Cell::savePrevious()
    {
        previous = state;
       
    }


void Cell::checkState(int neighbours, int hunters)
    {
        //Normal rules for game of life but with added rules for red squigly
        
        float chance = ofRandom(1);
             if ((state == 1 && neighbours < 2 )|| (state == 1 && neighbours > 3))
             {
                     state = 0;
             }
        else if (state == 1 && neighbours > 3)
                state = 0;
        else if (state == 1 && hunters > 0){
                if (chance > 0.6) {
            state = 2;
            } 
        }
        else if (state == 0 && neighbours == 3)
                state = 1;
        
   
       
        else if(chance <=lifeRate)
                state = 2;
        else
            state = previous;
        
    }









