#include <iostream>
#include "bishop.h"

Bishop::Bishop(Color color, Position coordo) : PieceAbs(color, coordo) {
}

Bishop::~Bishop() {
}

const std::string Bishop::getPiece() {
    return "Bishop";
}

bool Bishop::acceptedMovement(Position coordo) {
    if ((0 <= coordo.x && coordo.x < 8) && (0 <=coordo.y && coordo.y < 8)) 
        {
            if (abs(coordo.x - getPosition().x ) == abs(coordo.y - getPosition().y) ) 
            {
                return true;
            } 
            else 
                return false;
        }
    else 
        return false;
}