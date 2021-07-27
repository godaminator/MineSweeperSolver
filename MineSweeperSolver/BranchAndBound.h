#pragma once
#include "ProcessEngine.h"
#include<unordered_map>
#include<map>
#include<vector>
#include<set>
#include<cmath>
using namespace std;
class BranchAndBound :
    public ProcessEngine
{
public:
    virtual std::vector<pair<Cell*, float>> ShowNextCell(Grid*);
    



private:
    unordered_map<Cell*,vector<Cell*>> Cstate_CoveredtoUncovered;
    unordered_map<Cell*, vector<Cell*>> Cstate_UncoveredtoCovered;
    vector<Cell*> Cstate_OrderedUcCells;

    vector<vector<bool>> final_matrix;
    vector<vector<bool>> temp_final_matrix;

    long int progress=0;

    unordered_map<Cell*, bool> processed_Cstate_OrderedUcCells;

private:
    void InitCstateVariables(Grid* grid);
    void printCstates(unordered_map<Cell*, vector<Cell*>> c_state);

    void print1();

    void increment_mines(Cell*);
    bool decrement_mines(Cell*);

    bool checkConstraintSatisfied();
    bool check_UCtoC_Constraint(int curr_cell);
    void branchandbound(int curr_cell,vector<bool> curr_mines);

    vector<pair<Cell*, float>> consolidate_final_matrix();


};

