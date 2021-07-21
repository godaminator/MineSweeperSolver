#include "Cell.h"
#include "Pos.h"

Cell::Cell(int x,int y) {
	
	Pos* p = new Pos(x, y);
	setPos(p);

}
Pos Cell::getPos() {
	return *position;

}
Status Cell::getStatus() {
	return currentStatus;
}
int Cell::getNeighbourMines() {
	return neighbourMines;
}
void Cell::setPos(Pos* ppos) {
	position = ppos;
}
void Cell::setStatus(Status pstatus) {
	currentStatus = pstatus;
}
void Cell::setNeighbourMines(int pneighbourMines) {
	neighbourMines = pneighbourMines;
}