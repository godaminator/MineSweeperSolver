#include "Pos.h"

Pos::Pos(int prow, int pcol) {
	setRow(prow);
	setColumn(pcol);
}
Pos::Pos(const Pos& p1) {
	column = p1.column;
	row = p1.row;

}
int Pos::getRow() {
	return row;
}

int Pos::getColumn() {
	return column;
}

void Pos::setRow(int prow) {
	row=prow;
}

void Pos::setColumn(int pcol) {
	column=pcol;
}