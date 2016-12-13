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
        
     

        cellGrid.resize(rows);
        for(int i = 0; i < rows; i ++)
        {
            cellGrid[i].resize(cols);
        }
        
        for(int i = 0; i < cellGrid.size(); i ++)
        {
            for (int j = 0; j < cellGrid[i].size(); j++)
            {
                
                 int state = (int)ofRandom(2);
                Cell * newCell = new Cell;
                newCell->setup(i * width, j * width, width, state);
                cellGrid[i][j] = newCell;
                
                
            }
        }
        test.setup(300,300);
    }

    

void GOL::generate()
    {
        for(int x = 0; x < cellGrid.size(); x++)
        {
            for(int y = 0; y < cellGrid[x].size(); y++)
            {
                cellGrid[x][y]->savePrevious();
                
                int neighbors = 0;
                int hunters = 0;
                for(int i = -1; i <=1; i++)
                {
                    for(int j = -1; j <=1; j++)
                    {
                        if( cellGrid[(x+i+cols)%cols][(y+j+rows)%rows]->previous <= 1)
                        {
                            neighbors += cellGrid[(x+i+cols)%cols][(y+j+rows)%rows]->previous;
                        }else {
                            hunters += cellGrid[(x+i+cols)%cols][(y+j+rows)%rows]->previous;
                        }
                    }
                }
                
                neighbors -= cellGrid[x][y]->previous;
                
                cellGrid[x][y]->checkState(neighbors, hunters);
            }
        }
          test.grow();
    }

void GOL::display()
    {
        
        for(int i = 0; i < cellGrid.size(); i++)
        {
            for(int j = 0; j < cellGrid[i].size(); j++)
            {
                cellGrid[i][j]->display();
            }
        }
        test.display();

    }





void GOL::addCell(int mouseX, int mouseY)
    {
        for(int i = 0; i < cellGrid.size(); i++)
        {
            for(int j = 0; j < cellGrid[i].size(); j++)
        {
            cellGrid[i][j]->god(mouseX, mouseY);
        }
    }
    
}

void GOL::cycle()
    {

    }















