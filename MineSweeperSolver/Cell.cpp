#include "Cell.h"
#include "Pos.h"
std::ostream& operator<< (std::ostream& out, const Cell& c) {
	out <<"[" << c.position->getRow()+1 << "," << c.position->getColumn()+1<<"]";
	return out;
}

bool Cell::operator==(const Cell& rhs) const {
	return position->getRow() == rhs.position->getRow() &&
		position->getColumn() == rhs.position->getColumn();
}

bool Cell::operator!=(const Cell& rhs) const{
	return !(*this == rhs);
}

bool Cell::operator<(const Cell& rhs) const
{
	if(getPos().getRow() != rhs.getPos().getRow()) {
		return getPos().getRow() < rhs.getPos().getRow();

	}
	else {
		return getPos().getColumn() < rhs.getPos().getColumn();
	}
	
}

int Cell::getRow()
{
	return position->getRow();
}

int Cell::getCol()
{
	return position->getColumn();
}

void Cell::incMines()
{

	neighbourMines = neighbourMines + 1;

}

bool Cell::decMines()
{
	neighbourMines = neighbourMines - 1;
	if(neighbourMines<0){
		return false;
	}
	return true;
}

Cell::Cell(int x,int y) {
	
	Pos* p = new Pos(x, y);
	setPos(p);
	currentStatus= Status::COVERED;
	neighbourMines = 9;


}
Pos Cell::getPos() const{
	return *position;

}
Status Cell::getStatus() {
	return currentStatus;
}
int Cell::getNeighbourMines() {
	return neighbourMines;
}
void Cell::setPos(Pos* ppos)  {
	position = ppos;
}
void Cell::setStatus(Status pstatus) {
	currentStatus = pstatus;
}
void Cell::setNeighbourMines(int pneighbourMines) {
	neighbourMines = pneighbourMines;
}