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

class ChessBoard : public QMainWindow {
	Q_OBJECT

public:
	ChessBoard(QWidget* parent = nullptr);
	~ChessBoard() override = default;
	void reset();
	// void InitialisePawn();

public slots:
	//ChessBoard* buttonPressed(); //QAbstractButton* bouton);  // Pour la version setProperty.
	Position buttonSelected(int x, int y, QPushButton* button);

private:
	template <typename T = decltype(nullptr)>
	QPushButton* newButton(int i, int j);
	Position position_;
	ChessBoardSet chessBoard;  // Le Modèle (pourrait être un pointeur mais pas nécessaire dans ce cas).
	QLabel* affichage_;  // Pour la version QButtonGroup.
	QPushButton* previousClickedSquared = nullptr;
	int clickBoutonPiece = 0;
	int clickBoutonCase = 0;
	QString label;

};
