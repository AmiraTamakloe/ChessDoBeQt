#include "RAImovement.h"
using namespace std;

Movement::Movement(PieceAbs& piece, Square& destination) : piece_(piece), destination_(destination){}
	
Movement::~Movement()
{
	piece_.isDead_= true;
    destination_.piece_ = nullptr;
}

int main () {

    Position pos1;
    pos1.x = 5;
    pos1.y = 6;
    auto king1 = King(Color::Black, pos1);

    try {
        Position pos2;
        pos2.x = 3;
        pos2.y = 6;
        auto king2 = King(Color::White, pos2);
        std::cout << king2.getPiece() << std::endl;
        Position pos3;
        pos3.x = 3;
        pos3.y = 6;
        auto king3 = King(Color::Black, pos3);
        std::cout << king3.getPiece() << std::endl;
        std::cout << "hello world" << std::endl;

    } catch(InvalidKingInstanciationException& erreur) {
        std::cout << erreur.what() << std::endl;
    }
    return 0;
}