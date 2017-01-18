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
        void setup(ofVec2f pos_, float size_, int state_);
        void display();
        void calculate();
        void aging();
        void feed();
     
        
        ofFloatColor dead;
        
        ofVec2f pos;
        
        float size;
        float state;
      
       
        
        int birth;
        int age;
        
    };