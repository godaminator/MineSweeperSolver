#pragma once
#include<vector>
#include "Cell.h"
class Output
{
public:
	virtual void show(std::vector<std::pair<Cell*, float>>)=0;
};

