#include <iostream>
#include "bishop.h"

using namespace std;

Bishop::Bishop(Color color, Position coordo) : Piece(color) {
    this->piecePosition_ = coordo;
    this->pieceType_ = "Bishop";
    printPiece();
}

Bishop::~Bishop() {
}

// void Bishop::printPiece() {

    
//     if (pieceColor_ == Color::White) {
//         QString pathImage = ":/ressources/w.bishop.jpeg";
//         QPixmap pixmap(pathImage);
//         ui->imageFrame->setPixmap(pixmap);
//         ui->imageFrame->repaint();
//     }
        
//     else{
//         QString pathImage = ":/ressources/b.bishop.jpeg";
//         QPixmap pixmap(pathImage);
//         ui->imageFrame->setPixmap(pixmap);
//         ui->imageFrame->repaint();
//     } 
// }

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