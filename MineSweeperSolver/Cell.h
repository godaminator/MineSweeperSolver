#pragma once
#include "Pos.h"
#include<iostream>
class Cell
{
public:
	Cell(int,int);
	Pos getPos() const;
	Status getStatus();
	int getNeighbourMines();
	void setPos(Pos*);
	void setStatus(Status);
	void setNeighbourMines(int);
	bool operator==(const Cell& rhs) const;
	bool operator!=(const Cell& rhs) const;
	friend std::ostream& operator << (std::ostream& out, const Cell& c);
	bool operator<(const Cell& rhs) const;
	int getRow();
	int getCol();
	void incMines();
	bool decMines();
private:
	Pos* position;
	Status currentStatus;
	int neighbourMines;

};

