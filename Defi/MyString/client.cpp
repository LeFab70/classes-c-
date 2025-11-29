/**************************************************************************************************
 *
 *  Auteur : Ghislain Duguay
 *  Date : Novembre
 *
 *  Description :
 *
 ***********************************************************************************************************/

#include <iostream>
#include "MyString.h"
using namespace std;

/****************  Prototypes de fonctions *****************************/

/**************** Programme principal *******************************/
int main(void)
{
	// //Probl�me #2
	// MyString str1("Ghislain");
	// MyString str2(" Duguay");
	// MyString str3;
	// str1.append(str2); // (Erreur)
	// str1.afficher();
	// str3.setBuffer(str1); // (Erreur)
	// str3.afficher();

	// //Probl�me #3
	// MyString str = 'g';
	// str.afficher(); //affichera g

	// return 0;

	MyString str1("Ghislain");

	// #1: VÈrification: MyString == const char*
	if (str1 == "ghislain")
		cout << "TRUE" << endl;
	else
		cout << "FALSE" << endl;

	// #2: VÈrification: const char* == MyString
	("Ghislain" == str1) ? cout << "TRUE" << endl : cout << "FALSE" << endl;

	// #3: Concatenation avec + entre deux objets.
	MyString str2(" Duguay");
	MyString str3 = str1 + str2;
	str3.afficher();

	// #4: Concatenation avec += entre un objet et une chaine.
	str3 += " - CCNB Bathurst";
	str3.afficher();

	// #5: VÈrification: const char* >= MyString
	("Ghislain" >= str3) ? cout << "TRUE" << endl : cout << "FALSE" << endl;

	// #6: Utilisation du << pour affichage.
	cout << str3 << endl;

	// #7: Utilisation du >> pour initialiser la chaine.
	cout << "Saisir une chaine: ";
	cin >> str3;
	cout << "La nouvelle chaine est: " << str3 << endl;
	cout << "Est-ce que la chaine est vide? : " << str3 << ((!str3) ? " oui" : " non") << endl;

	// #8: Utilisation de ! pour voir si la chaine est vide.
	MyString str4;
	cout << "Est-ce que la chaine est vide? : " << ((!str4) ? "oui" : "non") << endl;

	return 0;
}