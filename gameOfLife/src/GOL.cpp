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
        
        startPos.set(300,300);
        
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
         virus.setup(width, cols, rows, 0);
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
        virus.grow();
        virus.findPostions();
        
               if(virus.positions.size() >=20000)
            alive = 1;
        else if(virus.positions.size() <9000)
            alive = 0;
        if (alive !=1) {
          
        
        for (int i = 0; i < virus.positions.size(); i++){
            
          
            for(int j = -1; j <=1; j++)
        {
                for(int k = -1; k <=1; k++)
            {
            int x = ((int)virus.positions[i]->x + j + cols)% cols;
            int y = ((int)virus.positions[i]->y + k + rows)% rows;
                float r = ofRandom(1);
                if( cellGrid[x][y]->state == 1){
                    cellGrid[x][y]->state == 0;
                 //   if (r >=0.9)
                    virus.addCell(x, y);
                    
                }else if( cellGrid[x][y]->state == 2){
                     //if (r >=0.9)
                 //   virus.kill(virus.positions[i]);
                   // else
                        virus.addCell(x, y);
                    cellGrid[x][y]->state == 0;
                }
 
        }
        
    }
        }
        }
        

        cout << virus.positions.size() << endl;
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
        virus.findPostions();
       // cout << virus.positions.size() << endl;

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















