#include "ProcessByProbablities.h"
#include "Cell.h"
#include <iterator>
float ProcessByProbablities::pValCalculator(int noOfScells, int noOfMines) {
	return static_cast<float>(noOfMines) / noOfScells;
}
#include <numeric>


int ProcessByProbablities::flaggedMineCells(std::vector<Cell*>& neighbourCells) {
	int sum = 0;
	for (Cell* j : neighbourCells) {
		if (j->getStatus() == Status::MINE) {
			sum=sum+1;
		}
	}
	return sum;
}

void ProcessByProbablities::processBoundaryCells(std::vector<Cell*>& boundaryCells, Grid* grid) {

	for (Cell* i : boundaryCells) {
		
		std::vector<Cell*> temp = grid->getNeighbours(*i);
		int noofminesfound=i->getNeighbourMines() - flaggedMineCells(temp);
		temp = filterUncoveredCells(temp);
		
		float vprob = pValCalculator(temp.size(), noofminesfound);
		
		for (Cell* j : temp) {
			
			probabilityMap[(*j)].push_back(vprob);
		}
	}
}



int ProcessByProbablities::MarkMines(Grid* grid) {
	std::cout << "Marking Mines:---------" << std::endl;
	std::vector<Cell> mines;
	//collect mines
	for (auto i : probabilityMap) {
		for (auto j : i.second) {
			if (j == float(1.00)) {
				std::cout<<i.first<<" mine" << std::endl;
				mines.push_back(i.first);
				break;
			}
		}
	}
	//remove mines from the probablity list and mark them in grid
	for (auto i : mines) {
		probabilityMap.erase(i);
		grid->getCell(i.getPos().getRow(), i.getPos().getColumn()).setStatus(Status::MINE);
	}
	return mines.size();
}

void ProcessByProbablities::printMap() {
	
	for (auto i : probabilityMap) {
		std::cout << i.first << " ";
		for (auto j : i.second) {
			std::cout << j << " ";
		}
		std::cout << std::endl;
	}
}
void ProcessByProbablities::clearProbablities() {
	for (auto i : probabilityMap){
		probabilityMap[i.first] = {};
	}
}
void ProcessByProbablities::printConsolidated() {
	for (auto i : probabilityMap) {
		for (auto j : i.second) {
			if (j == 0.0) {
				std::cout << i.first <<"x0"<<std::endl;
				probabilityMap[i.first] = { 0.0 };
				break;
			}
		}
		probabilityMap[i.first] = { float(std::accumulate(i.second.begin(), i.second.end(), 0.0) )/ i.second.size() };
	}

}

//need to modify
std::vector<std::pair<Cell*, float>> ProcessByProbablities::ShowNextCell(Grid* grid) {
	std::vector<Cell*> temp;
	std::vector<std::pair<Cell*, float>> temp2;
	int flag = 1;
	while (flag) {
		clearProbablities();
		temp = identifyBoundaryCells(grid);
		processBoundaryCells(temp, grid);
		flag=MarkMines(grid);
		printMap();		
	}
	printConsolidated();
	printMap();

	for (auto i: temp) {
		temp2.push_back(std::make_pair(i,0.0));
	}

	return temp2;
}


	


