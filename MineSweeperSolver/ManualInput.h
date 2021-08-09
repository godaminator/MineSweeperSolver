#pragma once
#include "Grid.h"
#include <vector>
class ManualInput :
    public Grid
{
public:
    ManualInput(int,int);
    int getHeight();
    int getWidth();
    void buildGrid();
    void updateGrid(std::vector<std::pair<Cell*, float>> );
    Cell& getCell(int, int);

private:
    std::vector<std::vector<Cell*>> grid;
    int height;
    int width;
};

