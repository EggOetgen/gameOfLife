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
    void setup(int width_);
    void init();
    void generate();
    void display();
    void addCell(int x, int y);
    
    //VARIABLES
    int cols;
    int rows;
    int width;
   

    
    
   
 
    vector<vector<Cell>> grid;
    

    
    GOL();
private:
    
};
