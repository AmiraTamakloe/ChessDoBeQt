#pragma once
#include "piece.h"
#include "color.h"
#include "position.h"

using namespace piece;

class Square {
public :
    Square(Color color, Position coordo);
    Square() {};
    virtual ~Square();
    Position getPosition() const;
    void setPieceSquare(PieceAbs* piece);
    piece::PieceAbs* getPieceSquare();
    void unoccupiedSquare();
    Color getColor() ;

private :
    PieceAbs* piece_;
    Position position_;
    bool isOccupied_ = false;
    Color color_;
};