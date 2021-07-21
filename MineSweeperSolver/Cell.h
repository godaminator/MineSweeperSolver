#pragma once
#include "Pos.h"
class Cell
{
public:
	Cell(int,int);
	Pos getPos();
	Status getStatus();
	int getNeighbourMines();
	void setPos(Pos*);
	void setStatus(Status);
	void setNeighbourMines(int);
private:
	Pos* position;
	Status currentStatus;
	int neighbourMines;

};

