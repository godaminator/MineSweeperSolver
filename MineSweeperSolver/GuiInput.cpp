#include "GuiInput.h"


GuiInput::GuiInput()
{
	Cleangui_window GUIObj;
	height = 10;
	width = 10;
	std::cout << "thread before"<<sizeof(height);
	//setting up staus flags
	gridstatusptrptr = &gridstatusptr;
	gridptrptr = &gridptr;
	flagptrptr = &flagptr;
	height_bridge_variable_ptr_ptr = &height_bridge_variable_ptr;
	width_bridge_variable_ptr_ptr = &width_bridge_variable_ptr;
	t1= std::thread(&Cleangui_window::startWidget, GUIObj, height_bridge_variable_ptr_ptr, width_bridge_variable_ptr_ptr, flagptrptr, gridstatusptrptr, gridptrptr);
	std::cout << "thread\n";
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
void GuiInput::changeGridSize(int h,int w) {
	height = h;
	width = w;
	grid.clear();
	for (int i = 0; i < height; i++) {
		grid.push_back({});
		for (int j = 0; j < width; j++) {

			grid[i].push_back(new Cell(i, j));
		}
	}


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
			if (height!= *height_bridge_variable_ptr &&width!= *width_bridge_variable_ptr) {
				changeGridSize(*height_bridge_variable_ptr, *width_bridge_variable_ptr);
			}
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
