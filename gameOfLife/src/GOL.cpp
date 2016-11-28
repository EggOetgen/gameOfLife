//
//  GOL.cpp
//  gameOfLife
//
//  Created by Edmund Oetgen on 11/11/2016.
//
//

/*
 http://www.cplusplus.com/forum/general/107678/
 
 http://www.gamedev.net/blog/844/entry-2249737-another-cellular-automaton-video/
*/

#include "GOL.hpp"

GOL::GOL(float width_):width(width_)
    {
       
    }

void GOL::setup()
    {
        cols = rows = ofGetWidth()/width;
        
        init();
    }

void GOL::init()
    {
        for(int i = 0; i < rows; i ++)
        {
            for (int j = 0; j < cols; j++)
            {
                
                 int state = (int)ofRandom(2);
                Cell *newCell;
                grid[i].push_back(newCell);
                
                
            }
        }
    }

void GOL::generate()
    {
        for(int x = 0; x < cols; x++)
        {
            for(int y = 0; y < rows; y++)
            {
                grid[x][y]->savePrevious();
                
                int neighbors = 0;
                for(int i = -1; i <=1; i++)
                {
                    for(int j = -1; j <=1; j++)
                    {
                        neighbors += grid[(x+i+cols)%cols][(y+j+rows)%rows]->previous;
                    }
                }
                
                neighbors -= grid[x][y]->previous;
                
                grid[x][y]->checkState(neighbors);
            }
        }
    }

void GOL::display()
    {
        for(int i = 0; i < cols; i++)
        {
            for(int j = 0; j < rows; j++)
            {
                grid[i][j]->display();
            }
        }

    }




















