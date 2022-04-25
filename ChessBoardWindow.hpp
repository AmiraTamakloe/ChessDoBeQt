#pragma once
// La Vue-Controlleur pour calculatrice simple.
// Par Francois-R.Boyer@PolyMtl.ca

#include "ChessBoardSet.hpp"
#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QMainWindow>
#include <QPushButton>
#include <QString>
#include <QLabel>
#include "position.h"
#pragma pop()

namespace vue {
	class ChessBoard : public QMainWindow {
	Q_OBJECT

public:
	ChessBoard(QWidget* parent = nullptr);
	~ChessBoard() override = default;

public slots:

	Position buttonSelected(int x, int y, QPushButton* button);
	void pieceSelected(QPushButton* button);

private:
	template <typename T = decltype(nullptr)>
	QPushButton* newButton(int i, int j);
	// QPushButton* getButton(int i, int j) {
	// 	return chessBoard[i][j];
	// }
	// pour la position d'un bouton 
	Position position_;
	ChessBoardSet chessBoard[8][8];  // Le Modèle (pourrait être un pointeur mais pas nécessaire dans ce cas).
	QPushButton* previousClickedSquared = nullptr;
	QIcon icone_;
	int clickBoutonPiece = 0;
	int clickBoutonCase = 0;
	
	QString label;
	

	// ce sont les pionsRepresentation visuelle
	const QIcon whiteRookPng = QIcon("./ressources/white/rook.png");
	const QIcon whiteKingPng = QIcon("./ressources/white/king.png");
	const QIcon whiteBishopPng = QIcon("./ressources/white/bishop.png");
	const QIcon blackRookPng = QIcon("./ressources/black/rook.png");
	const QIcon blackKingPng = QIcon("./ressources/black/king.png");
	const QIcon blackBishopPng = QIcon("./ressources/black/bishop.png");
};

}
