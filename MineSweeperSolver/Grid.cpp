#include "Grid.h"

//#include "Cell.h"
//#include "Pos.h"
Grid::Grid() {

}
std::vector<Cell*> Grid::getNeighbours(Cell x) {
	int currCellPosrow = x.getPos().getRow();
	int currCellPosColumn= x.getPos().getColumn();
	int h=getHeight();
	int w=getWidth();
	std::vector<Cell *> result;
	for (int i = currCellPosrow - 1; i< currCellPosrow + 1; i++) {
		for (int j = currCellPosColumn - 1; i < currCellPosColumn + 1; i++) {

			if (i == currCellPosrow && j == currCellPosColumn) {
				continue;
			}

			if (i > 0 && i <= h && j>0 && j <= w) {
				result.push_back(&getCell(i,j));
			}
		}

	}
	return result;

}





