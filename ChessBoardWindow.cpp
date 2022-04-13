// La Vue-Controlleur pour calculatrice simple.
// Par Francois-R.Boyer@PolyMtl.ca
#include "square.h"
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

using iter::range;

template <typename T>
QPushButton* ChessBoard::newButton(int i, int j)
{
	auto button = new QPushButton(this);
	button->setFixedSize(100, 100);

	if constexpr (!is_same_v<T, decltype(nullptr)>)
		QObject::connect(button, &QPushButton::clicked, &chessBoard, [this, i, j, button]() {buttonSelected(i, j, button);});
	return button;
}

ChessBoard::ChessBoard(QWidget* parent) :
	QMainWindow(parent)
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

		// On ne met pas un autre affichage, on en a déjà deux versions différentes.
	}

	
	setCentralWidget(widgetPrincipal);
	setWindowTitle("Amira's Checkers");
}


// Pour la version setProperty.
// ChessBoard* ChessBoard::buttonPressed()
// {
	
// 	// QObject::sender() est l'objet d'où vient le signal connecté à ce slot; attention qu'il sera nullptr si le slot est appelé directement au lieu de passer par un signal.
// 	chessBoard.ajouterChiffre(QObject::sender()->property("chiffre").value<int>());
// }

Position ChessBoard::buttonSelected(int x_, int y_, QPushButton* button) {
	Position pos;
	pos.x = x_;
	pos.y = y_;
	clickBoutonCase++;
	if (clickBoutonCase == 1 && clickBoutonPiece == 1) {
		button->setText(label);
		clickBoutonCase = 0;
		clickBoutonPiece = 0;
	}
	else if (clickBoutonCase == 1) {

		if (button->text() == "") {
			clickBoutonCase = 0;
		}
		else {
			label = button->text();
			previousClickedSquared = button;
		}
	}
	else if (clickBoutonCase == 2) {

		if (previousClickedSquared != button) {
			button->setText(label);
			previousClickedSquared->setText("");
		}

		clickBoutonCase = 0;
		previousClickedSquared = nullptr;
	}
	std::cout << pos.x << pos.y << std::endl;
	return pos;
}

