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

void Square::setPieceSquare(PieceAbs* piece) 
{
    this->piece_ = piece;
    isOccupied_ = true;
    piece->setPosition(this->getPosition());
};
PieceAbs* Square::getPieceSquare()
{
    return piece_;
};

void Square::setUnoccupiedSquare() 
{
    this->piece_ = nullptr;
    isOccupied_ = false;
}
