#include <iostream>
#include "piece.h"

Piece::Piece(Color color) {
    pieceColor_ = color;
}

Piece::~Piece() {
}

void Piece::setPosition(Position coordo) {
    if (Piece::acceptedMovement(coordo)) {
        this->piecePosition_ = coordo;
    } else {
        std::cout << "mouvement invalide" <<std::endl;
    }
}

Position Piece::getPosition() {
    return piecePosition_;
}

bool Piece::isPieceDead() {
    if(lifeStatus_) 
        return false;
    else 
        return true;
}

Color Piece::getPieceColor() const {
    return pieceColor_;
}