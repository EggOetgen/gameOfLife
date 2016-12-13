//
//  virus.hpp
//  gameOfLife
//
//  Created by Edmund Oetgen on 01/12/2016.
//
//

#pragma once

#include "ofMain.h"
#include "Cell.hpp"

class virusCell
    {
    public:
        void setup(float x_, float y_, float size_, int state_, int id);
        void display();
        void calculate();
      //  void checkState(int neighbors, int hunters);
        
        ofColor dead;
        
        float x;
        float y;
        int size;
        float state;
        int id;
        
       
        
        
    };