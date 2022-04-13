#include "board.h"
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




Board::Board() {
    Color squareColor = Color::White;
    for(int i = 0; i < dimension ; i++)
    {
        for(int j = 0; i < dimension ; j++) 
        {
            Position pos;
            pos.x = i;
            pos.y = j;
            board[i][j] = make_shared<Square>(squareColor, pos); //je veux que ce soit des shared_ptr comment
            if(squareColor == Color::White) {
                squareColor = Color::Black;
            } else 
                squareColor = Color::White;
        }
    }
}

// void Board::displayBoad() { //est ce que je met ma fonction du haut dans display 
//     for(int i = 0; i < dimension ; i++)
//     {
//         for(int j = 0; i < dimension ; j++) 
//         {
//             const piece = board[i][j]->getPieceSquare();
//             if(Piece) 
//             {
//                 QIcon icon = board[i][j]->getPieceSquare()
//                 gridLayout[i][j]->setIcon(icon)
//             }
//             else {
//                 gridLayout[i][j]->setIcon()
//             }
//         }
//     }
// }

shared_ptr<Square> * Board::getSquare(Position pos) {
    return &board[pos.x][pos.y];
}

Piece* Board::getPiece(Position pieceLocationBoard) {
    return board[pieceLocationBoard.x][pieceLocationBoard.y]->getPieceSquare();
}

bool Board::isMovementAccepted(Position initial, Position destination) {
    Piece* pieceMoving = getPiece(initial);
    Piece* pieceDestination = getPiece(destination);

    if ( pieceDestination->acceptedMovement(destination) && (pieceDestination->getPieceColor() != pieceMoving->getPieceColor() || pieceDestination == nullptr)) {
        pieceMoving->setPosition(destination);
        return true;
    }
    else
        return false;
}