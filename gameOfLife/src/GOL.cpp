//
//  GOL.cpp
//  gameOfLife
//
//  Created by Edmund Oetgen on 11/11/2016.
//
//

/*
*/

#include "GOL.hpp"

GOL::GOL()
    {
       
    }

void GOL::setup(int width_, float virusStrength_, float lifeRate_)
{
             
            //work out number of rows and columns of 2d vector
        cols = ofGetWidth()/width_;
        rows = ofGetWidth()/width_;
        width = width_;
        
        virusStrength = virusStrength_;
        lifeRate = lifeRate_;
        startPos.set(300,300);
        
        init();
        
        drawNorm = false;
       
    
}

void GOL::init()
{
        
     
            //set the cell grid vector size, not really necessary but just helps keep things in order
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
                newCell->setup(i * width, j * width, width, state, lifeRate);
                cellGrid[i][j] = newCell;
                cellGrid[i][j]->drawNorm = drawNorm;
             
               

            }
        }
         virus.setup(width, cols, rows);
}

    
//Where all the magic happens
void GOL::generate()
{
        virus.grow();
        virus.findPostions();
       
            //For every living part of the virus check if either a red squgily or normal cell is in adjacent space, if so eat it
            for (int i = 0; i < virus.positions.size(); i++)
            {
                for(int j = -1; j <=1; j++)
                {
                    for(int k = -1; k <=1; k++)
                    {
                        int x = ((int)virus.positions[i]->x + j + cols)% cols;
                        int y = ((int)virus.positions[i]->y + k + rows)% rows;
                        float r = ofRandom(1);
                        if( cellGrid[x][y]->state == 1)
                        {
                            if (r >=virusStrength)
                            {
                                virus.addCell(x, y);
                            }
                            
                        } else if( cellGrid[x][y]->state == 2)
                        {
                            virus.addCell(x, y);
                            
                            cellGrid[x][y]->previous = 1;
                            cellGrid[x][y]->state = 1;
                        }
                    }
                }
            }
        
        
        
        //based on Daniel Shifman's Game of Life implementation from The Nature of Code, counts each cells adjacent negihbors
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
        virus.display();
}

void GOL::clear()
{
    //delete everything
    vector< vector<Cell *> >::iterator row;
    vector<Cell *>::iterator col;
    for (row = cellGrid.begin(); row != cellGrid.end(); row++)
    {
        for (col = row->begin(); col != row->end(); )
        {
                delete * col;
                col = row->erase(col);
        }
    }
    virus.clear();
}


















