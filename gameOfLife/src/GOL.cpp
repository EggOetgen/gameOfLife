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

GOL::GOL()
    {
       
    }

void GOL::setup(int width_)
    {
             
        
        cols = ofGetWidth()/width_;
        rows = ofGetWidth()/width_;
        width = width_;
        init();
    }

void GOL::init()
    {
        
      /*  for (int i = 0; i < rows; rows++)
        {
            vector<Cell>  tempRow;
            tempRow.assign(cols, Cell());
            grid.push_back(tempRow);
        }*/
        
       /* for(int i = 0; i < grid.size(); i ++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                
                int state = (int)ofRandom(2);
                Cell newCell;
                newCell.setup(j * width, i * width, width, state);
                grid[i][j]=newCell;
                
                
            }*/

        grid.resize(rows);
        for(int i = 0; i < rows; i ++)
        {
            grid[i].resize(cols);
        }
        
        for(int i = 0; i < grid.size(); i ++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                
                 int state = (int)ofRandom(2);
                Cell newCell;
                newCell.setup(i * width, j * width, width, state);
                grid[i][j] = newCell;
                
                
            }
        }
    }

    

void GOL::generate()
    {
        for(int x = 0; x < grid.size(); x++)
        {
            for(int y = 0; y < grid[x].size(); y++)
            {
                grid[x][y].savePrevious();
                
                int neighbors = 0;
                for(int i = -1; i <=1; i++)
                {
                    for(int j = -1; j <=1; j++)
                    {
                        neighbors += grid[(x+i+cols)%cols][(y+j+rows)%rows].previous;
                    }
                }
                
                neighbors -= grid[x][y].previous;
                
                grid[x][y].checkState(neighbors);
            }
        }
    }

void GOL::display()
    {
        
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                grid[i][j].display();
            }
        }

    }




















