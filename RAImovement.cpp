// #include "RAImovement.h"
// #include "board.h"
// #include "king.h"
// #include <iostream>
// using namespace std;

// Movement::Movement(PieceAbs& piece, std::unique_ptr<Square>& destination) : piece_(piece), destination_(destination)
// {
//     cout << "l'objet est créé" << endl;
// }
	
// Movement::~Movement()
// {
// 	piece_.isDead_= true;
//     destination_->piece_ = nullptr;
//     cout << "L'objet est détruit" << endl;
// }

// //Décommenter le main ici et commenté le fichier main pour tester la RAII et le compteur d'instance
// int main () {
//     auto giGame = new Board();
//     Position pos1;
//     pos1.x = 5;
//     pos1.y = 6;
//     std::cout << King::getCounter() << std::endl;
//     King king1 = King(Color::Black, pos1);
    
//     std::cout << King::getCounter() << std::endl;
//     Position pos2;
//     pos2.x = 3;
//     pos2.y = 6;
//     auto king2 =new  King(Color::White, pos2);
//     std::cout << king2->getPiece() << std::endl;
    
//     std::cout << "Utilisation de la classe RAII" << std::endl;
//     auto squares = giGame->getSquare(pos1);
//     auto tryKing = new Movement(king1, *squares);
//     std::cout << King::getCounter() << std::endl;
//     try {
//         Position pos3;
//         pos3.x = 3;
//         pos3.y = 6;
//         auto king3 = King(Color::Black, pos3);
//         std::cout << king3.getPiece() << std::endl;

//     } catch(InvalidKingInstanciationException& erreur) {
//         std::cout << erreur.what() << std::endl;
//     }
    
//     return 0;
// }