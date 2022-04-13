#pragma once
#include <string.h>
#include <string>
#include "position.h"
#include "color.h"
using namespace std;


class Piece {
 
public :

    Piece(Color color);
    virtual ~Piece();

    void setPosition(Position coordo);
    Position getPosition();
    virtual bool acceptedMovement(Position coordo) = 0;
    virtual void printPiece() const = 0;
    bool isPieceDead();
    Color getPieceColor() const;

protected :

    Color pieceColor_;
    Position piecePosition_;
    bool lifeStatus_ = true;
    std::string pieceType_ ;

};
