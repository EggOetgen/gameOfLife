//
//  GOL.hpp
//  gameOfLife
//
//  Created by Edmund Oetgen on 11/11/2016.
//
//

#pragma once

#include "ofApp.h"

class GOL {
    
public:
    //METHOD;
    void setup();
    void init();
    void generate();
    void display();
    
    //VARIABLES
    int cols;
    int rows;
    float width;
  
    
    GOL(float width_);
    
};
