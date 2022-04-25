#pragma once
#include "board.h"
#include "king.h"
#include "position.h"

class Movement
{
public:
	Movement(PieceAbs& piece, Square& destination);
    ~Movement();
private:
	PieceAbs& piece_;
    Square& destination_;
};