//
//  virusBody.cpp
//  gameOfLife
//
//  Created by Edmund Oetgen on 13/12/2016.
//
//

#include "virusBody.hpp"

void virusBody::setup(ofVec2f initPos, int spaces_)
    {
        spaces = spaces_;
        cellSize = 10;
        initID = 0;
        addCell(initPos);
    }

void virusBody::addCell(ofVec2f pos)
    {
        
        virusCell * newPart = new virusCell();
        newPart->setup(pos, cellSize, 1, initID);
        parts.push_back(newPart);
        positions.push_back(pos);
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
        bool empty = true;
        
   
        ofVec2f newPos = calculateNewPos(parts[length-1]->pos);
        
       /* for (int i = 0; i < positions.size(); i++) {
            if (newPos == positions[i]) {
                empty = false;
            }
        }*/
      //  if (empty) {
            
        addCell( newPos);
      //  }
    }

ofVec2f virusBody::calculateNewPos( const ofVec2f & prevPos)
    {
        int newX = prevPos.x + ((int)ofRandom(-2, 2) * cellSize);
        int newY = prevPos.y + ((int)ofRandom(-2, 2) * cellSize);

        newX = (newX+600)%600;
        newY = (newY+600)%600;
        
        ofVec2f newPos(newX, newY);
        return newPos;
    }






