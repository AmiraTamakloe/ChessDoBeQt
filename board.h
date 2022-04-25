#pragma once
#include "square.h"
#include "position.h"
#include "piece.h"

class Board {

public:
    Board();
    virtual ~Board() = default;
    bool isMovementAccepted(Position initial, Position destination);
    piece::PieceAbs* getPiece(Position pieceLocationBoard);
    std::unique_ptr<Square>* getSquare(Position pos);

private:
    
    static const int dimension = 8; //doit il etre static
    std::unique_ptr<Square> board[8][8];

};