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
#include "virusCell.hpp"
#include "virusBody.hpp"
#include "math.h"

class GOL {
    
public:
    //METHOD;
    void setup(int width_, float virusStrength_, float lifeRate_);
    void init();
    void generate();
    void display();
    void clear();
       //VARIABLES
    int cols;
    int rows;
    float width;
    
    float virusStrength;
    float lifeRate;
    
    
   
    ofVec2f startPos;
 
    vector<vector<Cell*>> cellGrid;
    virusBody virus;
    
    bool drawNorm;

    
    GOL();
private:
    
};
