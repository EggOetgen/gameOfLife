//
//  virusBody.cpp
//  gameOfLife
//
//  Created by Edmund Oetgen on 13/12/2016.
//
//

#include "virusBody.hpp"

void virusBody::setup( int cellSize_,int cols_,int rows_)
    {
        
       
        cellSize = cellSize_;
        cols = cols_;
        rows = rows_;
       
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
            newVirusCell->setup(ofVec2f(i * cellSize, j *  cellSize), cellSize, state);
            parts[i][j] = newVirusCell;
            
            
            
            
        }
    }
    int rx =(int)ofRandom(20,380);
    int ry =(int)ofRandom(20,380);
    for (int i = 0; i < 360; i ++){
      
        int x = sin(ofDegToRad(i)) * 10+rx;
        int y = cos(ofDegToRad(i)) * 10+ry;
        
        parts[x][y]->state = 1;
    }

    

}

void virusBody::addCell(int x, int y)
    {
        
        parts[x][y]->state = 1;
        
        
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
            //check if storing positions for any dead cells, and if so delete
        vector<ofVec2f *>::iterator it;
        for ( it = positions.begin(); it != positions.end(); )
            if( parts[(*it)->x][(*it)->y]->state ==0 ){
                delete * it;
                it = positions.erase(it);
            }
            else {
                ++it;
            }

            //for every cell that's alive age it
        for (int i = 0; i < positions.size(); i++) {
            parts[positions[i]->x][positions[i]->y]->aging();
        
            }
        /* this was meant to delete dead cells but would alter size of vector, left it in as could make things look cool but not very useful/efficient
              
     vector< vector<virusCell *> >::iterator row;
        vector<virusCell *>::iterator col;
        for (row = parts.begin(); row != parts.end(); row++) {
            for (col = row->begin(); col != row->end(); ) {
                if( (*col)->state ==0.1f){
                    delete * col;
                    col = row->erase(col);
                    cout << "ping";
                }
                else {
                    ++col;
                }

            }
        }*/
   
        
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


void virusBody::clear()
{
    vector< vector<virusCell *> >::iterator row;
    vector<virusCell *>::iterator col;
    for (row = parts.begin(); row != parts.end(); row++) {
        for (col = row->begin(); col != row->end(); ) {
                            delete * col;
                col = row->erase(col);
            }
           }
    vector<ofVec2f *>::iterator it;
    for ( it = positions.begin(); it != positions.end(); ){
        
            delete * it;
            it = positions.erase(it);
    }
    
    }

