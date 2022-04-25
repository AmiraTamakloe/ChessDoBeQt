#pragma once
#include <string.h>
#include <string>
#include <cmath>
#include "position.h"
#include "color.h"


namespace piece {

 class PieceAbs {
 
public :

    PieceAbs(Color color, Position position);
    virtual ~PieceAbs();
    Color getPieceColor();
    Position getPosition() const;
    void setPosition(Position coordo);
    const virtual std::string getPiece() = 0 ;
    bool isMovementAccepted(Position coordo);

private :
    virtual bool acceptedMovement(Position coordo) =0;
    Color pieceColor_;
    Position piecePosition_;
};
   
}

