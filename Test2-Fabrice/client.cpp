/*****************************************************************
	Programmer: Fabrice Kouonang
	 Date:       10/11/2025
	 But:        Test2 - Classe LocalCCNB
	 version:    1.0
	Testing de la classe LocalCCNB
******************************************************************/

#include <iostream>
#include "LocalCCNB.h"
using namespace std;

/****************  Prototypes de fonctions *****************************/

/**************** Programme principal *******************************/
int main(void)
{
	cout << endl
		 << endl
		 << "Programme de gestion des Locuax CCNB en POO en C++"
		 << endl
		 << endl;
	cout << endl
		 << "--------------------------------------------" << endl;

	// Creation de 3 locaux
	LocalCCNB local1;				   // constructeur par defaut
	local1.setLocal("P201", 25, true); // utilisation du mutateur

	LocalCCNB local2("P101", 30, true);
	LocalCCNB *local3 = new LocalCCNB("N302", 50, false); // Doit generer une erreur
	// Affichage du nombre d'instances
	LocalCCNB::showCount();
	// Affichage des locaux
	cout << endl
		 << "Affichage des locaux crees: " << endl
		 << endl;
	cout << "Local 1: " << endl;
	cout << "Num Local: " << local1.getNumLocal() << endl;
	cout << "Nbre Occupants: " << local1.getNbreOccupants() << endl;
	cout << "Acces Projecteur: " << (local1.getAccesProjecteur() ? "Oui" : "Non") << endl
		 << endl;

	// affichage de local 3 qui a une erreur
	cout << "Local 3: " << endl;
	cout << "Num Local: " << local3->getNumLocal() << endl;
	cout << "Nbre Occupants: " << local3->getNbreOccupants() << endl;
	cout << "Acces Projecteur: " << (local3->getAccesProjecteur() ? "Oui" : "Non") << endl
		 << endl;
	// constructeur par copie pour un nouveau local
	LocalCCNB local4(local2);
	cout << "Local 4 (copie de Local 2): " << endl;
	cout << "Num Local: " << local4.getNumLocal() << endl;
	cout << "Nbre Occupants: " << local4.getNbreOccupants() << endl;
	// Affichage du nombre d'instances
	LocalCCNB::showCount();

	// Maj des proprietés de local4 avec des erreurs
	local4.setNumLocal("B404");
	local4.setNbreOccupants(150);
	local4.changerAccProj();
	cout << endl
		 << "Local 4 apres modification: " << endl;
	cout << "Num Local: " << local4.getNumLocal() << endl;
	cout << "Nbre Occupants: " << local4.getNbreOccupants() << endl;
	cout << "Acces Projecteur: " << (local4.getAccesProjecteur() ? "Oui" : "Non") << endl;

	// destruction du local3
	delete local3;
	cout << endl
		 << "Local 3 detruit." << endl;
	// Affichage du nombre d'instances
	LocalCCNB::showCount();

	cout << endl
		 << "--------------------------------------------"
		 << endl
		 << endl
		 << "Fermeture du programme, \n pressez surla touche entrée,pour quitter le programme"
		 << endl
		 << endl;

	return 0;
}