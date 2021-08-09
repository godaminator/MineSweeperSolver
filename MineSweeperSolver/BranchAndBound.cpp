#include "BranchAndBound.h"
#include <algorithm>


std::vector<pair<Cell*, float>> BranchAndBound::ShowNextCell(Grid* grid)
{
	InitCstateVariables(grid);
	branchandbound(0, {});
	
	return consolidate_final_matrix();
}

void BranchAndBound::InitCstateVariables(Grid* grid)
{
	unordered_set<Cell*> c_cells=identifyCoveredBoundaryCells(grid);
	vector<Cell*> tuc_cells=identifyBoundaryCells(grid);
	unordered_set<Cell*> uc_cells(tuc_cells.begin(), tuc_cells.end());
	//unordered_set<Cell*> c_cells;
	//filterMines() /consider marked mines
	for (Cell* i : uc_cells) {
		cout << "x" << *i;
		for (Cell* j : grid->getNeighbours(*i)) {
			if (j->getStatus() == Status::MINE) {
				cout << "+";
				i->decMines();
			}
		}
		cout << endl;
	}
		
		

	
	printgrid(grid);
	cout<<endl<<"covered cells" << endl;
	for (auto i : c_cells) {
		cout << *i << endl;
	}
	cout << endl <<"uncovered Cells" << endl;
	for (auto i : uc_cells)
	{
		cout << *i << endl;
	}
	
	//init covered cells
	for (auto i:c_cells) {
		Cstate_CoveredtoUncovered[i] = {};
	}
	//init uncovered cells
	for (auto i : uc_cells) {
		Cstate_UncoveredtoCovered[i]={};
	}

	//mapp the values

	for (auto i : Cstate_CoveredtoUncovered) {
		Cell& tempc = *(i.first);
		for(auto j: grid->getNeighbours(tempc)){
			
			if (uc_cells.find(j) != uc_cells.end()) {
				//cout << j;
				Cstate_CoveredtoUncovered[i.first].push_back(j);
				
		}
		}
	}

	for (auto i : Cstate_UncoveredtoCovered) {
		Cell& tempc = *(i.first);
		for (auto j : grid->getNeighbours(tempc)) {
			
			if (c_cells.find(j) != c_cells.end()) {
				//cout << j;
				Cstate_UncoveredtoCovered[i.first].push_back(j);
				

			}
		}
	}


	//get an order list of uncovered cells
	for (auto i : c_cells) {
		Cstate_OrderedUcCells.push_back(i);
	}

	std::sort(std::begin(Cstate_OrderedUcCells), std::end(Cstate_OrderedUcCells), [this](Cell* a,Cell* b) {
		int m1 = 9;
		int m2 = 9;
		for (auto i:this->Cstate_CoveredtoUncovered[a]) {
			if (i->getNeighbourMines() < m1) {
				m1 = i->getNeighbourMines();
			}
		}
		for(auto i :this->Cstate_CoveredtoUncovered[b]) {
			if (i->getNeighbourMines() < m2) {
				m2 = i->getNeighbourMines();
			}
			}
		return m1 > m2;
		}
	);

}


void BranchAndBound::printCstates(unordered_map<Cell*, vector<Cell*>> c_state)
{
	
	for (auto i:c_state) {
		cout << endl;
		cout << *(i.first)<<"--"<<i.second.size();
		for (auto j : i.second) {
			
			cout << *j<< "-"<<j->getNeighbourMines() << " ";
		}
	}

}

void BranchAndBound::print1()
{

	printCstates(Cstate_CoveredtoUncovered);
	cout << "-------------------------\n";
	cout << "-------------------------\n";
	cout << "-------------------------\n";
	
	cout << endl;
	//for (auto i : Cstate_OrderedUcCells) {
	//	cout << *i <<" - " ;
	//	for (auto j : Cstate_CoveredtoUncovered[i]) {
	//		cout << j->getNeighbourMines()<<" ";
	//	}
	//	cout << endl;
	//}
	long long int sum=1;
	for (int i = 0; i < Cstate_OrderedUcCells.size(); i++) {
		
		sum = sum * 2;
	}
	cout << endl<<"total cells :" << Cstate_OrderedUcCells.size() << "    total combinations:" << sum<<endl;
	
	
	
	
	cout << "possible combinations : " << final_matrix.size() << endl;
	/*for (int i = 0; i < Cstate_OrderedUcCells.size();i++) {
		cout << *Cstate_OrderedUcCells[i]<<"--";
		for (int j = 0; j < final_matrix.size();j++) {
			cout << final_matrix[j][i];

		}
		cout << endl;

	}*/
	
}

void BranchAndBound::increment_mines(Cell* i)
{
	for (auto j : Cstate_CoveredtoUncovered[i]) {
		j->incMines();
	}
}

bool BranchAndBound::decrement_mines(Cell* i)
{
	bool flag = true; //determine if decrement operation is valid or not
	for (auto j : Cstate_CoveredtoUncovered[i]) {
		if (!(j->decMines())) {
			flag = false;
		}
	}
	//if decrement operation is invalid , return to original state by incrementing
	if (!flag) {
		increment_mines(i);
	}
	//return flag to check if operation faild or succeeded 
	return flag;

}

bool BranchAndBound::checkConstraintSatisfied()
{
	 
	for (auto i : Cstate_CoveredtoUncovered) {
		for (auto j : Cstate_CoveredtoUncovered[i.first]) {
			if (j->getNeighbourMines() != 0) {
				return false;
			}
		}
	}
	return true;
}

bool BranchAndBound::check_UCtoC_Constraint(int curr_cell) 
{
	Cell* curr_cell_ptr = Cstate_OrderedUcCells[curr_cell];
	for (Cell* i : Cstate_CoveredtoUncovered[curr_cell_ptr])
	{
		int count = 0;
		for (Cell* j : Cstate_UncoveredtoCovered[i]) 
		{
			if (processed_Cstate_OrderedUcCells[j] == false) {
				count = count + 1;
			}


		}
		if (count <= i->getNeighbourMines()) {
			return false;
		}
	}
	return true;

}

//initial call with (0,{})
void BranchAndBound::branchandbound(int curr_cell,vector<bool> curr_mines)
{
	
	if (curr_cell == Cstate_OrderedUcCells.size()) {
		//check if all the mines are zero.
		//temp_final_matrix.push_back(curr_mines);
		
		if (checkConstraintSatisfied()) {
		/*	for (auto i : curr_mines) {
				cout << i;
			}
			cout << endl;*/
			final_matrix.push_back(curr_mines);
		}
		return;
	}

	
	//decrement the mines
	Cell* curr_cell_ptr = Cstate_OrderedUcCells[curr_cell];
	if(decrement_mines(curr_cell_ptr)){

		curr_mines.push_back(true);
		processed_Cstate_OrderedUcCells[curr_cell_ptr] = true;
		branchandbound(curr_cell + 1, curr_mines);
		curr_mines.pop_back();
		processed_Cstate_OrderedUcCells[curr_cell_ptr] = false;
		increment_mines(curr_cell_ptr);

	}
	
	//check uncovered to covered constraint
	if (check_UCtoC_Constraint(curr_cell)) {
		curr_mines.push_back(false);
		processed_Cstate_OrderedUcCells[curr_cell_ptr] = true;

		branchandbound(curr_cell + 1, curr_mines);
		processed_Cstate_OrderedUcCells[curr_cell_ptr] = false;
	}
	


	
}

vector<pair<Cell*, float>> BranchAndBound::consolidate_final_matrix()
{
	vector<pair<Cell*, float>> result;
	int size = final_matrix.size();
	for (int i = 0; i < Cstate_OrderedUcCells.size(); i++) {
		//cout << *Cstate_OrderedUcCells[i] << "--";
		int count = 0;
		for (int j = 0; j < size; j++) {
			
			count = count + (int)final_matrix[j][i];
		}

		result.push_back(make_pair(Cstate_OrderedUcCells[i], float(count)/size));
	}
	//sort result
	sort(std::begin(result), std::end(result), [](pair<Cell*, float> a, pair<Cell*, float> b) {
		return a.second < b.second;

		}
		);
	//print result
	
	
	return result;
}


void BranchAndBound::printgrid(Grid* mygrid1) {
	cout << "xxxx";
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