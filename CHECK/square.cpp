#include "square.h"


Square::~Square(){
}

Square::Square(Color color, Position coordo)

{
    color_ = color;
    position_ = coordo;
}

Position Square::getPosition() const 
{
    return position_;
}

void Square::setPieceSquare(Piece* piece) 
{
    this->piece_ = piece;
    isOccupied_ = true;
};
Piece* Square::getPieceSquare()
{
    return piece_;
};

void Square::unoccupiedSquare() 
{
    this->piece_ = nullptr;
    isOccupied_ = false;
}
