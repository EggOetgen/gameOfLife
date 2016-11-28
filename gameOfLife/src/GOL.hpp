//
//  GOL.hpp
//  gameOfLife
//
//  Created by Edmund Oetgen on 11/11/2016.
//
//

#pragma once

#include "ofMain.h"
#include "Cell.hpp"

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
    
   
 
    vector<vector<Cell*>> grid;
    

    
    GOL(float width_);
private:
    
};
