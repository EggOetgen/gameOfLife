//
//  virusBody.cpp
//  gameOfLife
//
//  Created by Edmund Oetgen on 13/12/2016.
//
//

#include "virusBody.hpp"

void virusBody::setup(ofVec2f initPos, int spaces_, int cellSize_,int cols_,int rows_)
    {
        spaces = spaces_;
        cellSize = cellSize_;
        cols = cols_;
        rows = rows_;
        initID = 0;
        for (int i = 0; i < 360; i ++){
            int x = sin(ofDegToRad(i)) * 20+300;
            int y = cos(ofDegToRad(i)) * 20+300;
            ofVec2f p(x,y);
        addCell(p);
        
        }
        
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
        for (int i = 0; i < parts.size(); i++) {
            parts[i]->aging();
          //  if (parts[i]->state ==0){
            //    delete parts[i];
       //        parts.erase;
            //}
        }
        
        vector<virusCell *>::iterator it;
        for ( it = parts.begin(); it != parts.end(); )
            if( (*it)->state ==0 ){
                delete * it;
                it = parts.erase(it);
        }
        else {
                ++it;
                }
        //calculateNewPos();
   
       // ofVec2f newPos = calculateNewPos();
       // int select = ofRandom(positions.size());
     //   addCell( calculateNewPos(positions[select]));
        for(int i = 0; i < 180; i++){
            int select = ofRandom(positions.size());
            addCell( calculateNewPos(positions[select]));
        }
        
        
    }


/*ofVec2f virusBody::calculateNewPos( const ofVec2f & prevPos)
    {
        int newX = prevPos.x + ((int)ofRandom(-2, 2) * cellSize);
        int newY = prevPos.y + ((int)ofRandom(-2, 2) * cellSize);

        newX = (newX+600)%600;
        newY = (newY+600)%600;
        
        ofVec2f newPos(newX, newY);
        return newPos;
    }
*/
ofVec2f virusBody::calculateNewPos(ofVec2f oldPos)
{
    newPositions.clear();
      bool empty;
   // int memory = (int)positions.size()/2;
 //  for (int k = 0; k < positions.size(); k+=10) {
    for(int i = -1; i <=1; i++)
        {
            for(int j = -1; j <=1; j++)
                {
                    int newX = ((int)oldPos.x + i);// + cols)%cols;
                    int newY = ((int)oldPos.y + j);// + rows)%rows;
                    cout << newX << " " << newY << endl;
                     for (int l = 0; l < positions.size(); l++) {
                    if(newX == positions[l].x && newY == positions[l].y)
                         empty = false;
                      else
                         empty = true;
                     }
                         if (empty == true){
                            ofVec2f newPos(newX, newY);
                            newPositions.push_back(newPos);
                                                                 }
                }
        }
  // }
   
    
   // newPositions.push_back(potPos);
    int select = ofRandom(newPositions.size());
    
       return newPositions[select];
     newPositions.clear();
   
    }






