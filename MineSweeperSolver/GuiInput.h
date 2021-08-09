#pragma once
#include "Grid.h"
#include "CleanGUI.h"
#include<thread>
#include <mutex>
#include <chrono>
class GuiInput :
    public Grid
{
public:
	GuiInput(int,int);
	int getHeight();
	int getWidth();
	void buildGrid();
	void updateGrid(std::vector<std::pair<Cell*, float>>);
	Cell& getCell(int, int);
	std::thread t1;
	//std::vector<Cell*> getNeighbours(Cell&);

private:
	std::vector<std::vector<Cell*>> grid;
	int height;
	int width;
	//int interpreteFromGUI();


private:
	//flags to intract with gui/QT
	bool** flagptrptr;
	bool* flagptr;
	bool** gridstatusptrptr;
	bool* gridstatusptr;
	std::vector<std::vector<std::pair<int, int>>>** gridptrptr;
	std::vector<std::vector<std::pair<int, int>>>* gridptr;
};

