// La vue-Controlleur pour calculatrice simple.
// Par Francois-R.Boyer@PolyMtl.ca
#include "ChessBoardWindow.hpp"
#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QGridLayout>
#include <QPushButton>
#include <QButtonGroup>
#include <QLabel>
#include <QString>
#include <QVariant>
#pragma pop()
#include <iostream>
#include <type_traits>
#include <cppitertools/range.hpp>
#include <QPixmap>
#include <QIcon>
#include <QtGui>
#include <QString>
#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QtGui>

using iter::range;

template <typename T>
QPushButton* vue::ChessBoard::newButton(int i, int j)
{
	auto button = new QPushButton(this);
	button->setFixedSize(100, 100);

	if constexpr (!is_same_v<T, decltype(nullptr)>)
		QObject::connect(button, &QPushButton::clicked, &chessBoard, [this, i, j, button]() {buttonSelected(i, j, button);});
	return button;
}

vue::ChessBoard::ChessBoard(QWidget* parent) :
	QMainWindow(parent)
	//ui(new Ui::ChessBoard)
{
	// Si on objet n'a pas encore de parent on lui met "this" comme parent en attendant, si possible, pour s'assurer que tous les pointeurs sont gérés par un delete automatique en tout temps sans utiliser de unique_ptr.

	auto widgetPrincipal = new QWidget(this);
	auto layoutPrincipal = new QVBoxLayout(widgetPrincipal);  // Donner un parent à un layout est comme un setLayout.

	// Version avec setProperty:
	{
		auto layout = new QGridLayout();
		layoutPrincipal->addLayout(layout);


		for (int i = 0 ; i < 8 ; i++) 
		{
			for (int j = 0 ; j < 8 ; j++) 
			{
				auto button = newButton(i, j);
				// On donne un nom à la propriété, et on lui donne une valeur QVariant (comme dans les notes de cours) d'un type quelconque (doit enregistrer le type avec Q_DECLARE_METATYPE(LeType) si ce n'est pas un type déjà connu de Qt).
				if((i+j)% 2 == 0) {
					button->setStyleSheet("background-color:white");

				}
				else {
					button->setStyleSheet("background-color:pink");
				}
				QObject::connect(button, &QPushButton::clicked,this, [this, i, j, button]() {buttonSelected(i, j, button); });
				layout->addWidget(button, i, j);
			}
			
		}

	QHBoxLayout* whitePieceLayout = new QHBoxLayout;
	QHBoxLayout* blackPieceLayout = new QHBoxLayout;

	auto whiteBishop = new QPushButton();
	whiteBishop->setIcon(whiteBishopPng);
	whiteBishop->setIconSize(QSize(80,80));
	whiteBishop->setFixedSize(100,100);
	connect(whiteBishop, &QPushButton::clicked, this, [this, whiteBishop]() {pieceSelected(whiteBishop); });
	auto whiteRook = new QPushButton();
	//whiteRook->setText("White Rook");
	whiteRook->setIcon(whiteRookPng);
	whiteRook->setIconSize(QSize(80,80));
	whiteRook->setFixedSize(100,100);
	connect(whiteRook, &QPushButton::clicked, this, [this, whiteRook]() {pieceSelected(whiteRook); });
	auto whiteKing = new QPushButton();
	//whiteKing->setText("White King");
	whiteKing->setIcon(whiteKingPng);
	whiteKing->setIconSize(QSize(100,80));
	whiteKing->setFixedSize(100,100);
	connect(whiteKing, &QPushButton::clicked, this, [this, whiteKing]() {pieceSelected(whiteKing); });

	whitePieceLayout->addWidget(whiteBishop);
	whitePieceLayout->addWidget(whiteRook);
	whitePieceLayout->addWidget(whiteKing);

	auto blackBishop = new QPushButton();
	blackBishop->setIcon(blackBishopPng);
	blackBishop->setIconSize(QSize(80,80));
	blackBishop->setFixedSize(100,100);
	//blackBishop->setText("Black Bishop");
	connect(blackBishop, &QPushButton::clicked, this, [this, blackBishop]() {pieceSelected(blackBishop); });
	
	auto blackRook = new QPushButton();
	//blackRook->setText("Black Rook");
	blackRook->setIcon(blackRookPng);
	blackRook->setIconSize(QSize(80,80));
	blackRook->setFixedSize(100,100);
	connect(blackRook, &QPushButton::clicked, this, [this, blackRook]() {pieceSelected(blackRook); });
	auto blackKing = new QPushButton();
	//blackKing->setText("Black Rook");
	blackKing->setIcon(blackKingPng);
	blackKing->setIconSize(QSize(80,80));
	blackKing->setFixedSize(100,100);
	//blackKing->setText("Black King");
	connect(blackKing, &QPushButton::clicked, this, [this, blackKing]() {pieceSelected(blackKing); });

	blackPieceLayout->addWidget(blackBishop);
	blackPieceLayout->addWidget(blackRook);
	blackPieceLayout->addWidget(blackKing);

	layoutPrincipal->addLayout(layout);
	layoutPrincipal->addLayout(whitePieceLayout);
	layoutPrincipal->addLayout(blackPieceLayout);

	layoutPrincipal->setSpacing(5);
	
	widgetPrincipal->setLayout(layoutPrincipal);
	widgetPrincipal->setFixedSize(850, 950);

	//chessBoard[7][4] =  blackKing;
	setCentralWidget(widgetPrincipal);
	setWindowTitle("Echiquier");

	// On crée un bouton 'Exit'
	QAction* exit = new QAction(tr("E&xit"), this);
	// On connecte le clic sur ce bouton avec l'action de clore le programme
	connect(exit, SIGNAL(triggered()), this, SLOT(close()));

	// On crée un nouveau menu 'File'
	QMenu* menuMenu = menuBar()->addMenu(tr("&Menu"));
	// Dans lequel on ajoute notre bouton 'Exit'
	menuMenu->addAction(exit);
	}

	setCentralWidget(widgetPrincipal);
	setWindowTitle("Amira's Checkers");
}


Position vue::ChessBoard::buttonSelected(int x_, int y_, QPushButton* button) {
	Position pos;
	pos.x = x_;
	pos.y = y_;
	
	std::cout << pos.x << pos.y << std::endl;
	clickBoutonCase++;
	if (clickBoutonCase == 1 && clickBoutonPiece == 1) {
		button->setIcon(icone_);
		button->setIconSize(QSize(80,80));
		clickBoutonCase = 0;
		clickBoutonPiece = 0;
	}
	else if (clickBoutonCase == 1) {

		if (button->text() == "") {
			clickBoutonCase = 0;
		}
		else {
			icone_ = button->icon();
			previousClickedSquared = button;
		}
	}
	else if (clickBoutonCase == 2) {

		if (previousClickedSquared != button) {
			button->setIcon(icone_);
			previousClickedSquared->setIcon(QIcon());
		}

		clickBoutonCase = 0;
		previousClickedSquared = nullptr;
	}
	return pos;
}

void vue::ChessBoard::pieceSelected(QPushButton* button) {
	clickBoutonPiece = 1;
	clickBoutonCase = 0;
	icone_ = button->icon();
	//return button;
}