#include <iostream>
#include "square.h"

using namespace std;


Square::Square(Position pos, QWidget* parent) : QPushButton(parent)
{
	this->position_ = pos;
}

Square::~Square() {}

Position Square::getPosition()
{
	return position_;
}

bool Square::isSquareOccupied()
{
	if (occupied_)
	{
		return true;
	}
	return false;
}
