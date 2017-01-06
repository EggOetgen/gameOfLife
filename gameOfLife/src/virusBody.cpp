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
       // for (int i = 0; i < 360; i ++){
         //   int x = sin(ofDegToRad(i)) * 20+300;
           // int y = cos(ofDegToRad(i)) * 20+300;
            //ofVec2f p(x,y);
        addCell(initPos);
        
      //  }
        
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

void virusBody::grow( vector<vector<Cell*>> cellGrid)
    {
        length = parts.size();
        bool empty = true;
        for (int i = 0; i < parts.size(); i++) {
            parts[i]->aging();
                 }
       eat(cellGrid);
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
     
        
      /*  for(int i = 0; i < 90; i++){
            int select = ofRandom( parts.size());
           addCell( calculateNewPos(parts[select]->pos.x, parts[select]->pos.y));
        }
        
        */
    }


ofVec2f virusBody::calculateNewPos(int x, int y  )
{
    newPositions.clear();
      bool empty;
    float state;
  
    for(int i = -1; i <=1; i++)
        {
            for(int j = -1; j <=1; j++)
                {
                    int newX = (x + i + cols)%cols;
                    int newY = (y + j + rows)%rows;
                                       for (int l = 0; l < parts.size(); l++) {
                    if( newX == parts[l]->pos.x && newY == parts[l]->pos.y )
                         empty = false;
                    else{
                         empty = true;
                       
                                                             }
                     }
                         if (empty == true  ){
                            ofVec2f newPos(newX, newY);
                            newPositions.push_back(newPos);
                             
                             
                }
        }
        }
    ofVec2f g(0,0);
    int slect = 0;
    float distance ;
    float gDist = 0;
    float sDist = 0;
    for (int i = 0; i < newPositions.size(); i ++){
        distance = 0;
        for (int l = 0; l < parts.size(); l ++) {
            distance += newPositions[i].distance(g);
        }
      //  if(parts.size() >=1200){
        if(distance < gDist ){
            gDist = distance;
            slect = i;
       // }
        }
      //  else{
        //    slect = ofRandom(newPositions.size());
        //}
        }
    
      //int select = ofRandom(newPositions.size());
    cout << parts.size() << endl;
       return newPositions[slect];
     newPositions.clear();
   
    }



void virusBody::eat( vector<vector<Cell*>> cellGrid )
{
     for (int i = 0; i < parts.size(); i++) {
         int x =parts[i]->pos.x;
         int y =parts[i]->pos.y;

         if (cellGrid[x][y]->state ==1 ) {
             float r = ofRandom(1);
            
             parts[i]->feed();
           //   if( r < 0.1){
         //    addCell( calculateNewPos(x, y));
          //   }
         }else if (cellGrid[x][y]->state ==2 ) {
            // hunt(x,y,cellGrid);
             parts[i]->feed();

         }
     }
}

void virusBody::hunt(int x, int y,vector<vector<Cell *> > cellGrid){


    for(int i = -1; i <=1; i++)
    {
        for(int j = -1; j <=1; j++)
        {
         //   for(int p = 0; p < parts.size(); p++){
            if(cellGrid[(x+i+cols)%cols][(y+j+rows)%rows]->state ==2 ){
                addCell(ofVec2f((x+i+cols)%cols,(y+j+rows)%rows));
                
                cout << "hunted";
         //   }
            }



}
    }
}







