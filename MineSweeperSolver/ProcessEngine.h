#pragma once
#include "Cell.h"
#include <vector>
#include "Grid.h"
#include<unordered_set>
#include <utility>
#include<map>
#include<set>
class ProcessEngine
{
public:

	virtual std::vector<std::pair<Cell*, float>> ShowNextCell(Grid*)=0;
	//virtual std::vector<Cell*> identifyBoundaryCells(Grid* grid) = 0;
	//
	std::vector<Cell*> identifyBoundaryCells(Grid* grid) {
		std::vector<Cell*> result;
		for (int i = 0; i < grid->getHeight(); i++) {
			for (int j = 0; j < grid->getWidth(); j++) {
				Cell& temp = grid->getCell(i, j);
				//filter uncovered cells
				if (temp.getStatus() == Status::UNCOVERED && temp.getNeighbourMines() != 0) {
					
					
					
						result.push_back(&temp);
					
				}

			}
		}
		std::unordered_set<Cell*> uc_cells(result.begin(), result.end());
		std::vector<Cell*> result2(uc_cells.begin(), uc_cells.end());
		return result2;

	}

	std::vector<Cell*> filterUncoveredCells(std::vector<Cell*>& neighbourCells) {
		std::vector<Cell*> temp;
		for (Cell* j : neighbourCells) {
			if (j->getStatus() == Status::COVERED) {
				temp.push_back(j);
			}
			
		}
		return temp;

	}

	std::unordered_set<Cell*> identifyCoveredBoundaryCells(Grid* grid) {
		//get uncovered boundary cells
		std::vector<Cell*> temp = identifyBoundaryCells(grid);
		
		//neighbour cells to boundary cells
		std::vector<Cell*> temp2;
		for (auto i : temp) {
			for (auto j : grid->getNeighbours(*i)) {
				temp2.push_back(j);
				std::cout << *j << std::endl;
			}
	}
		temp2 = filterUncoveredCells(temp2);

		std::unordered_set<Cell*> temp_set(temp2.begin(),temp2.end());
		
		

		return temp_set;

	}
};

