/************************************************
 *
 *  Auteur : Ghislain Duguay
 *  Date : 12 Novembre 2025
 *
 *  Description : Corrigez les erreurs du programme suivant (PILE)
 *
 *************************************************/

#include <iostream>
#include "Pile.h"
#include "Etudiant.h"
using namespace std;

/****************  Prototypes de fonctions ****************/

/******************* Programme principal *******************/
int main(void)
{
	// traitement des int
	Pile<int> unePile;

	unePile.push(1);

	unePile.push(2);

	unePile.push(3);

	unePile.push(4);

	unePile.push(5);

	unePile.afficherPile();

	int info = unePile.pop();
	cout << "**" << info << "**" << endl;

	unePile.afficherPile();

	// traitement des chars

	Pile<char> unePileChar;

	unePileChar.push('A');

	unePileChar.push('B');

	unePileChar.push('C');

	unePileChar.push('D');

	unePileChar.push('E');

	unePileChar.afficherPile();

	char infochar = unePileChar.pop();
	cout << "**" << infochar << "**" << endl;

	unePile.afficherPile();

	//pile d'étudiant

	Pile<Etudiant> unePileStudent;

	unePileStudent.push(Etudiant(123,"Fabrice"));

	unePileStudent.push(Etudiant(12,"Orgrick"));

	//unePileChar.afficherPile();

	Etudiant infoStudent = unePileStudent.pop();
	 //infoStudent.afficher();

	//unePile.afficherPile();
	return 0;
}
