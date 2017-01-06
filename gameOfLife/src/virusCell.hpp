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
        void setup(ofVec2f pos_, float size_, int state_, int id);
        void display();
        void calculate();
        void aging();
        void feed();
      //  void checkState(int neighbors, int hunters);
        
        ofFloatColor dead;
        
        ofVec2f pos;
        
        int size;
        float state;
        int id;
        
        int birth;
        int age;
        
    };