#pragma once
#include "Cell.h"
#include <vector>

class Grid
{


	public:

		Grid();
		virtual int getHeight()=0;
		virtual int getWidth()=0;
		virtual void buildGrid()=0;
		virtual void updateGrid()=0;
		virtual Cell& getCell(int,int)=0;
		std::vector<Cell*> getNeighbours(Cell&);
		
};

