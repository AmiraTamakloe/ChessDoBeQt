#pragma once

#include "piece.h"

class Rook : public piece::PieceAbs {
public:
    Rook(Color color, Position coordo);
    ~Rook();

private:
    const virtual std::string getPiece() override;
    bool acceptedMovement(Position coordo) override;
    
};

