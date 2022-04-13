 #pragma once
#include "position.h"
#include "color.h"
#include <qpushbutton.h>


class Square : public QPushButton
{
Q_OBJECT
public:

	Square(Position pos, QWidget* parent);
	Square();
	virtual ~Square();

	Position getPosition();
	bool isSquareOccupied();


private:
	Position position_;
	bool occupied_;
	Color squareColor;
};