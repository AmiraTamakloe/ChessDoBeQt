#include "board.h"
#include <iostream>
#include "rook.h"

Rook::Rook(Color color, Position coordo) : PieceAbs(color, coordo) {
}

Rook::~Rook() {
}

const std::string Rook::getPiece() {
    return "Rook";
}


bool Rook::acceptedMovement(Position coordo) 
{
    if ((0 <= coordo.x && coordo.x< 8) && (0<= coordo.y && coordo.y < 8))
        {
            if (coordo.x != getPosition().x && coordo.y != getPosition().y) 
            {
                return false;
            } 
            else 
                return true;
        }
    else 
        return false;
}