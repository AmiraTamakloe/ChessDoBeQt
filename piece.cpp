#include <iostream>
#include <cmath>
#include "piece.h"

piece::PieceAbs::PieceAbs(Color color, Position position) 
{
    pieceColor_ = color;
    piecePosition_ = position;
}

piece::PieceAbs::~PieceAbs() {
}

Color piece::PieceAbs::getPieceColor() {
    return pieceColor_;
}

Position piece::PieceAbs::getPosition() const {
    return piecePosition_;
}

bool piece::PieceAbs::isMovementAccepted(Position coordo) {
        return acceptedMovement(coordo);
}

void piece::PieceAbs::setPosition(Position coordo)
{
    piecePosition_ = coordo;
    
}