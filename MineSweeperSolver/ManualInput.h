#pragma once
#include "Grid.h"
#include <vector>
class ManualInput :
    public Grid
{
public:
    ManualInput(int,int);
    int getHeight();
    int getColumn();
    void buildGrid();
    void updateGrid();

private:
    std::vector<std::vector<Cell*>> grid;
    int height;
    int width;
};

