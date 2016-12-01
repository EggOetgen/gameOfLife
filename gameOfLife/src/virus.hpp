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

class virus : public Cell
    {
    public:
        virtual void setup();
        virtual void display();
        
        ofColor dead;
        
        vector <int> history;
        
        bool contaminated;
    };