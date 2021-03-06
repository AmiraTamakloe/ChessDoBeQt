#include "board.h"
#include "king.h"
#include <string>
#include <iostream>
#include <memory>
#include <functional>
#include <cassert>
#include <iterator>
#include "gsl/span"
#include <vector>
#include <list>
using gsl::span;

using namespace piece;

Board::Board() {
    
    for (int i = 0 ; i < dimension ; i++) 
		{
			for (int j = 0 ; j < dimension ; j++) 
			{
				Position pos;
                pos.x = i;
                pos.y = j;
                
				if((i+j)% 2 == 0) {
					board[i][j] = std::make_unique<Square>(Square(Color::White, pos));
				}
				else {
					board[i][j] = std::make_unique<Square>(Square(Color::Black, pos));
				}
			}
			
		}
}

std::unique_ptr<Square>* Board::getSquare(Position pos) {
    return &board[pos.x][pos.y];
}

PieceAbs* Board::getPiece(Position pieceLocationBoard) {
    return board[pieceLocationBoard.x][pieceLocationBoard.y]->getPieceSquare();
}

bool Board::isMovementAccepted(Position initial, Position destination) {
    PieceAbs* pieceMoving = getPiece(initial);
    PieceAbs* pieceDestination = getPiece(destination);

    if ( pieceDestination->isMovementAccepted(destination) && (pieceDestination->getPieceColor() != pieceMoving->getPieceColor() || pieceDestination == nullptr)) {
        pieceMoving->setPosition(destination);
        return true;
    }
    else
        return false;
}