#pragma once
#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QObject>
#include <QPushButton>
#pragma pop()
#include <functional>

using namespace std; // Dans ce cours on accepte le using namespace std dans le .hpp .

class ChessBoardSet : public QPushButton {
	Q_OBJECT
public:
	ChessBoardSet() = default;

	int obtenirValeur() { return valeur_; }

public slots:
	void changerValeur(int valeur);
	void effacer();
	void ajouterChiffre(int chiffre);
	void changerOperation(const function<int(int,int)>& operation);
	void operationPlus();
	void operationMoins();
	void operationEgal();
	void effectuerOperation();
	
signals:
	void valeurChangee(int valeur);

private:
	static int plus (int x, int y);
	static int moins(int x, int y);
	static int egal (int  , int y);

	bool estResultat_ = true;
	int valeur_ = 0;
	int resultatPrecedent_ = 0;
	function<int(int,int)> operation_ = egal;
};
