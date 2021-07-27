#pragma once
#include "ProcessEngine.h"
#include <unordered_map>
#include <string>

class MyHashFunction {
public:
    std::size_t operator()(const Cell& c) const
    {
        return std::stoi(std::to_string(c.getPos().getRow()) + std::to_string(c.getPos().getColumn()));
    }
};
class ProcessByProbablities :
    public ProcessEngine
{
public:
    std::vector<std::pair<Cell*, float>> ShowNextCell(Grid*);
private:
    std::unordered_map<Cell, std::vector<float>, MyHashFunction> probabilityMap;
private:
    //std::vector<Cell*> identifyBoundaryCells(Grid*);
    void processBoundaryCells(std::vector<Cell*> & , Grid*);
    float pValCalculator(int noOfScells,int noOfMines);
    //std::vector<Cell*> filterUncoveredCells(std::vector<Cell*>&);
    int flaggedMineCells(std::vector<Cell*>&);
    int MarkMines(Grid*);
    void printMap();
    void clearProbablities();
    void printConsolidated();
};

