#pragma once
#include<vector>
#include "Cell.h"
#include "Output.h"
class ConsoleOutput :
    public Output
{
public:
    void show(std::vector<std::pair<Cell*, float>>);

};

