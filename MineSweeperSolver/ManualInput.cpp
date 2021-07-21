#include "ManualInput.h"
#include <iostream>
ManualInput::ManualInput(int h, int w):height(h),width(w) {
	
	for (int i = 0; i < h; i++) {
		grid.push_back({});
		for (int j = 0; j < w; j++) {
			
			grid[i].push_back(new Cell(i,j));
		}
	}
	
}

int ManualInput::getHeight() {
	return height;
}

int ManualInput::getWidth() {
	return width;
}

Cell& ManualInput::getCell(int h, int w) {
	return *grid[h][w];

}

void ManualInput::buildGrid() {
	std::vector<std::vector<int>> imatrix = 
	{
		{9,9,9,  9,9,9,  9,9,9},
		{9,9,9,  9,9,9,  9,9,9},
		{9,9,9,  9,9,1,  1,2,9},

		{9,9,1,  1,1,1,  0,1,1},
		{9,2,1,  0,0,0,  0,0,0},
		{9,1,0,  0,0,0,  0,0,0},

		{9,1,1,  0,1,1,  1,0,0},
		{9,9,2,  1,2,9,  2,2,2},
		{9,9,9,  9,9,9,  9,9,9}
	};

	
	for (int i = 0; i < getHeight(); i++) {
		for (int j = 0; j < getWidth(); j++) {
			
			if (imatrix[i][j] == 9) {
				continue;
			}
			grid[i][j]->setStatus(Status::UNCOVERED);
			grid[i][j]->setNeighbourMines(imatrix[i][j]);


		}
	}


}

void ManualInput::updateGrid() {
	for (int i = 0; i < getHeight(); i++) {
		for (int j = 0; j < getWidth(); j++) {
			std::cout <<"["
				<<i
				<<"]["
				<<j
				<<"]:";
			
		}
	}

}