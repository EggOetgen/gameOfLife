//
//  virusBody.cpp
//  gameOfLife
//
//  Created by Edmund Oetgen on 13/12/2016.
//
//

#include "virusBody.hpp"

void virusBody::setup(int initX, int initY)
    {
        addCell(initX, initY);
    }

void virusBody::addCell(int x, int y)
    {
        
        virusCell * newPart = new virusCell();
        newPart->setup(x, y, cellSize, 1, initID);
        parts.push_back(newPart);
        initID++;
        
    }

void virusBody::display()
    {
        for (int i = 0; i < parts.size(); i++) {
            parts[i]->display();
        }
    }

void virusBody::grow()
    {
        length = parts.size();
       
          int newX = parts[length - 1]->x + ((int)ofRandom(-2, 2) * 10);
          int newY = parts[length - 1]->y +((int)ofRandom(-2,2) * 10);
        cout << newX << " " << newY << endl;
        addCell( newX, newY);
        
        for ( int i = 0; i < length; i ++){
            parts[i]->state = ofMap(initID, 0, parts.size(), 0, 1);
        }
        
    }