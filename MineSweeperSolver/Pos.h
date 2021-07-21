#pragma once
enum class Status
{
	COVERED,
	UNCOVERED,
	MINE,
	FLAG
};

class Pos
{
public:
	Pos(int,int);
	Pos(const Pos& p1);
	int getRow();
	int getColumn();
	void setRow(int);
	void setColumn(int);
private:
	int row;
	int column;
};

