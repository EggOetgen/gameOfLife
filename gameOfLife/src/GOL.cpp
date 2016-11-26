//
//  GOL.cpp
//  gameOfLife
//
//  Created by Edmund Oetgen on 11/11/2016.
//
//

#include "GOL.hpp"

GOL::GOL(float width_):width(width_)
    {

    }

void GOL::setup()
    {
        cols = rows = ofGetWidth()/width;
        
    }