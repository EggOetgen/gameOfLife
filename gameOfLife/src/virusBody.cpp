//
//  virusBody.cpp
//  gameOfLife
//
//  Created by Edmund Oetgen on 13/12/2016.
//
//

#include "virusBody.hpp"

void virusBody::setup( int cellSize_,int cols_,int rows_, int id)
    {
        
       // spaces = spaces_;
        cellSize = cellSize_;
        cols = cols_;
        rows = rows_;
        initID = 0;
       // for (int i = 0; i < 360; i ++){
         //   int x = sin(ofDegToRad(i)) * 20+300;
           // int y = cos(ofDegToRad(i)) * 20+300;
            //ofVec2f p(x,y);
        //addCell(initPos);
        
      //  }
        infected = false;
        init();
        
    }

void virusBody::init(){
    
    parts.resize(rows);
    for(int i = 0; i < rows; i ++)
    {
        parts[i].resize(cols);
        
    }
    
    for(int i = 0; i < parts.size(); i ++)
    {
        for (int j = 0; j < parts[i].size(); j++)
        {
            
            int state = 0;
            virusCell * newVirusCell = new virusCell;
            newVirusCell->setup(ofVec2f(i * cellSize, j *  cellSize), cellSize, state, 0);
            parts[i][j] = newVirusCell;
            
            
            
            
        }
    }
    for (int i = 0; i < 360; i ++){
        int x = sin(ofDegToRad(i)) * 20+300;
        int y = cos(ofDegToRad(i)) * 20+300;
        
        parts[x][y]->state = 1;
    }

    

}

void virusBody::addCell(int x, int y)
    {
        
        parts[x][y]->state = 1;
        /*virusCell * newPart = new virusCell();
        newPart->setup(pos, cellSize, 1, id);
        parts.push_back(newPart);
        positions.push_back(pos);
        initID++;*/
        
    }

void virusBody::display()
    {
        for (int i = 0; i < parts.size(); i++) {
            for (int j = 0; j < parts[i].size(); j++) {

            parts[i][j]->display();
            }
        }
    }

void virusBody::grow( )
    {
        length = parts.size();
        bool empty = true;
        for (int i = 0; i < positions.size(); i++) {
          

            parts[positions[i]->x][positions[i]->y]->aging();
        
            }
     vector< vector<virusCell *> >::iterator row;
        vector<virusCell *>::iterator col;
        for (row = parts.begin(); row != parts.end(); row++) {
            for (col = row->begin(); col != row->end(); ) {
                if( (*col)->state ==0.1 ){
                    delete * col;
                    col = row->erase(col);
                }
                else {
                    ++col;
                }

            }
        }
    //   eat(cellGrid);
        vector<ofVec2f *>::iterator it;
        for ( it = positions.begin(); it != positions.end(); )
            if( parts[(*it)->x][(*it)->y]->state ==0 ){
                delete * it;
                it = positions.erase(it);
        }
        else {
                ++it;
                }
        //calculateNewPos();
   
       // ofVec2f newPos = calculateNewPos();
       // int select = ofRandom(positions.size());
     //   addCell( calculateNewPos(positions[select]));
     
        
        //for(int i = 0; i < 90; i++){
            int select = ofRandom( parts.size());
          // addCell( calculateNewPos(cell));
        //}
        
        
    }


ofVec2f virusBody::calculateNewPos(Cell * cell  )
{
    newPositions.clear();
      bool empty;
    float state;
  
   /* for(int i = -1; i <=1; i++)
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
        }*/
    
      //int select = ofRandom(newPositions.size());
    if(cell->state ==1){
        ofVec2f newCell(cell->x, cell->y);
         return newCell;
    }
    cout << parts.size() << endl;
       return ofVec2f(id,id);
     newPositions.clear();
   
    }



void virusBody::eat( Cell * cell )
{
    /* for (int i = 0; i < parts.size(); i++) {
         int x =parts[i]->pos.x;
         int y =parts[i]->pos.y;

         if (cell->state ==1 ) {
             float r = ofRandom(1);
            
             parts[i]->feed();
           //   if( r < 0.1){
         //    addCell( calculateNewPos(x, y));
          //   }
         }//else if (cellGrid[x][y]->state ==2 ) {
            // hunt(x,y,cellGrid);
            // parts[i]->feed();

         //}
     }*/
}

void virusBody::hunt(int x, int y,vector<vector<Cell *> > cellGrid){


    for(int i = -1; i <=1; i++)
    {
        for(int j = -1; j <=1; j++)
        {
         //   for(int p = 0; p < parts.size(); p++){
            if(cellGrid[(x+i+cols)%cols][(y+j+rows)%rows]->state ==2 ){
         //       addCell(ofVec2f((x+i+cols)%cols,(y+j+rows)%rows));
                
                cout << "hunted";
         //   }
            }



}
    }
}

vector <ofVec2f*> virusBody::findPostions()
{
    positions.clear();
    for (int i = 0; i < parts.size(); i++) {
        for (int j = 0; j < parts[i].size(); j++) {
            
            if (parts[i][j]->state >= 0.1){
                ofVec2f * position = new ofVec2f(i,j);
                positions.push_back(position);
            }
        }
    }
    return positions;
    positions.clear();
}


void virusBody::kill(ofVec2f * pos){

    parts[pos->x][pos->y]->state = 0.0;
}


