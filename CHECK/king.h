#pragma once
#include "piece.h"

class King : public Piece {
public:
    King(Color color, Position coordo);
    virtual ~King();
    
    bool acceptedMovement(Position coordo) override; //demander ecq modifie ma fonction originale 
    void printPiece() const override;
    
};

