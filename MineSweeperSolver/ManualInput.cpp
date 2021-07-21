#include "ManualInput.h"

ManualInput::ManualInput(int h, int w):height(h),width(w) {
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			
			grid[i][j]= new Cell(i,j);
		}
	}
	
}

int ManualInput::getHeight() {
	return height;
}

int ManualInput::getColumn() {
	return width;
}

void ManualInput::buildGrid() {

	std::vector<std::vector<int>> imatrix = {};


}