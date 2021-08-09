#include "GuiInput.h"


GuiInput::GuiInput(int h, int w)
{
	CleanGUI GUIObj;
	height = h;
	width = w;

	//setting up staus flags
	gridstatusptrptr = &gridstatusptr;
	gridptrptr = &gridptr;
	flagptrptr = &flagptr;
	t1= std::thread(&CleanGUI::startWidget, GUIObj, height, width, flagptrptr, gridstatusptrptr, gridptrptr);
	std::chrono::milliseconds timespan(5000);
	std::this_thread::sleep_for(timespan);
	std::cout << "created inside guiobj\n";
	
	for (int i = 0; i < height; i++) {
		grid.push_back({});
		for (int j = 0; j < width; j++) {

			grid[i].push_back(new Cell(i, j));
		}
	}
	std::cout << "exiting guiobj constructor\n";
}

int GuiInput::getHeight()
{
	return height;
}

int GuiInput::getWidth()
{
	return width;
}

void GuiInput::buildGrid()
{
	std::cout << "created inside buildgrid\n";
	std::mutex mtx;
	
	
	while (true) {
		std::chrono::milliseconds timespan2(300);
		std::this_thread::sleep_for(timespan2);

		if (**flagptrptr) {
			mtx.lock();
			
			for (int i = 0; i < getHeight(); i++) {
				for (int j = 0; j < getWidth(); j++) {

					int tempint = (*gridptr)[i][j].first;
					grid[i][j]->setStatus((Status)tempint);
					

					
					grid[i][j]->setNeighbourMines((*gridptr)[i][j].second);


				}
			}

			**flagptrptr = false;
			mtx.unlock();
			break;
		}

	}
	
}

void GuiInput::updateGrid(std::vector<std::pair<Cell*, float>> result)
{
	int count = 0;
	for (auto i: result) {
		Cell* temp = i.first;
		if(i.second==1) {
			count++;
			(*gridptr)[temp->getRow()][temp->getCol()].first = 2;
			(*gridptr)[temp->getRow()][temp->getCol()].second = 0;
		}
		if (i.second == 0) {
			count++;
			(*gridptr)[temp->getRow()][temp->getCol()].first=1;
			(*gridptr)[temp->getRow()][temp->getCol()].second = 0;
		}

	}
	*gridstatusptr = true;
	if (count==0){
		auto i=result.begin();
		float val;
		do {
			 val= i->second;
			(*gridptr)[i->first->getRow()][i->first->getCol()].first = 3;
			(*gridptr)[i->first->getRow()][i->first->getCol()].second = 0;
			i++;
		} while (val == i->second);
	}

}



Cell& GuiInput::getCell(int h, int w) {
	if (h >= getHeight() || w >= getWidth()) {
		throw;
	}
	return *grid[h][w];

}
