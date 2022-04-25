#pragma once
#include "piece.h"

class Bishop : public piece::PieceAbs {

public:
    Bishop(Color color, Position coordo);
    ~Bishop();

private :
    const virtual std::string getPiece() override;
    bool acceptedMovement(Position coordo) override;
};