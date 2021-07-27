#include "ManualInput.h"
#include "Cell.h"
#include "Grid.h"
#include "Pos.h"
#include "ProcessByProbablities.h"
#include "BranchAndBound.h"
#include "ConsoleOutput.h"
#include "Output.h"
#include<iostream>

using namespace std;
int main() {
	ManualInput mygrid=ManualInput(9, 9);
	//checking virtual function
	Grid* mygrid1 = &mygrid;
	mygrid1->buildGrid();
	//try printing the grid
	for (int i = 0; i < mygrid1->getHeight(); i++) {
		cout << endl;
		for (int j = 0; j < mygrid1->getWidth(); j++) {
			cout << int(mygrid1->getCell(i,j).getStatus());
		}
	}
	cout << endl;
	for (int i = 0; i < mygrid1->getHeight(); i++) {
		cout << endl;
		for (int j = 0; j < mygrid1->getWidth(); j++) {
			cout << int(mygrid1->getCell(i, j).getNeighbourMines());
		}
	}
	//check getneighbour operator
	//for (Cell* i: mygrid1->getNeighbours(mygrid1->getCell(2, 2)) ) {
		//cout << endl;
		//cout << *i;
	//}
	//Check equality operator
	cout << endl;
	//cout << (mygrid1->getCell(8, 1) != mygrid1->getCell(0, 4));

	//print probabilities
	ProcessByProbablities myprocess=ProcessByProbablities();
	//myprocess.ShowNextCell(mygrid1);
	
	cout << endl;
	//cout << int(mygrid1->getCell(0, 4).getStatus());

	//print covered boundaries
	auto x = myprocess.identifyCoveredBoundaryCells(mygrid1);
	//for(auto i:x) {
	//	cout << *i;
	//}
	//cout << endl;
	//for (auto i : x) {
	//	cout << i<<"\n";
	//}

	//print uncovered cells as grid
	//for (auto i : x) {
	//	cout << *i;
	//}
	//for (int i = 0; i < mygrid1->getHeight(); i++) {
	//	cout << endl;
	//	for (int j = 0; j < mygrid1->getWidth(); j++) {
	//		if (x.find(&(mygrid1->getCell(i, j)))!=x.end()) {
	//			cout << int(1);
	//		}
	//		else {
	//			cout << int(0);
	//		}
	//	}
	//}
	//new bb process
	BranchAndBound bbprocess = BranchAndBound();
	auto result=bbprocess.ShowNextCell(mygrid1);
	Output * outputobj=new ConsoleOutput();
	outputobj->show(result);
	return 0;
}
