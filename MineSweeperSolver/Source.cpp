#include "ManualInput.h"
#include "Cell.h"
#include "Grid.h"
#include "Pos.h"
#include<iostream>
using namespace std;
int main() {
	ManualInput mygrid=ManualInput(9, 9);
	Grid* mygrid1 = &mygrid;
	mygrid.buildGrid();
	for (int i = 0; i < mygrid.getHeight(); i++) {
		cout << endl;
		for (int j = 0; j < mygrid.getWidth(); j++) {
			cout << int(mygrid.getCell(i,j).getStatus());
		}
	}
	cout << endl;
	for (int i = 0; i < mygrid.getHeight(); i++) {
		cout << endl;
		for (int j = 0; j < mygrid.getWidth(); j++) {
			cout << int(mygrid.getCell(i, j).getNeighbourMines());
		}
	}
	return 0;
}
