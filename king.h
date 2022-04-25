#pragma once
#include "piece.h"
#include <cassert>


class InvalidKingInstanciationException : public std::logic_error {
public:
    using std::logic_error::logic_error;
};

class King : public piece::PieceAbs {
public:
    King(Color color, Position coordo);
    virtual ~King();
    static inline int getCounter();
    const virtual std::string getPiece() override;
    
private:
    bool acceptedMovement(Position coordo) override; 
    static int counter_;
};

