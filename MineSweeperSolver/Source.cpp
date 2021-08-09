#include "ManualInput.h"
#include "Cell.h"
#include "Grid.h"
#include "Pos.h"
#include "ProcessByProbablities.h"
#include "BranchAndBound.h"
#include "ConsoleOutput.h"
#include "Output.h"
#include <iostream>
#include "GuiInput.h"
#include "GUIOutput.h"

using namespace std;
void printgrid(Grid * mygrid1) {
	for (int i = 0; i < mygrid1->getHeight(); i++) {
	cout << endl;
	for (int j = 0; j < mygrid1->getWidth(); j++) {
		cout << int(mygrid1->getCell(i, j).getStatus());
	}
}
cout << endl;
for (int i = 0; i < mygrid1->getHeight(); i++) {
	cout << endl;
	for (int j = 0; j < mygrid1->getWidth(); j++) {
		cout << int(mygrid1->getCell(i, j).getNeighbourMines());
	}
}
}
int main() {
	int myheight,mywidth;
	cout << "Enter the height of the grid:";
	cin >> myheight;
	cout << "\nEnter the width of the grid:";
	cin >> mywidth;
	cout.rdbuf(0);
	//ManualInput mygrid=ManualInput(9, 9);
	//GuiInput mygrid(9, 9);
	//std::cout << "created inside main\n";
	//checking virtual function
	//Grid* mygrid1 = &mygrid;
	//mygrid1->buildGrid();
	//try printing the grid

	//check getneighbour operator
	//for (Cell* i: mygrid1->getNeighbours(mygrid1->getCell(2, 2)) ) {
		//cout << endl;
		//cout << *i;
	//}
	//Check equality operator
	//cout << endl;
	//cout << (mygrid1->getCell(8, 1) != mygrid1->getCell(0, 4));

	//print probabilities
	//ProcessByProbablities myprocess = ProcessByProbablities();
	//myprocess.ShowNextCell(mygrid1);

	//cout << endl;
	//cout << int(mygrid1->getCell(0, 4).getStatus());

	//print covered boundaries
	//auto x = myprocess.identifyCoveredBoundaryCells(mygrid1);
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
	GuiInput mygrid(myheight, mywidth);
	std::cout << "created inside main\n";
	//checking virtual function
	Grid* mygrid1 = &mygrid;
	mygrid1->buildGrid();
	//new bb process
	
	Output* outputobj = new GUIOutput(&mygrid);
	Output* outputobjcon = new ConsoleOutput();

	while (true) {
		BranchAndBound bbprocess = BranchAndBound();
		auto result = bbprocess.ShowNextCell(mygrid1);
		outputobj->show(result);
		outputobjcon->show(result);
		mygrid1->buildGrid();
		printgrid(&mygrid);
	}

	mygrid.t1.join();
	
	
	return 0;
}
