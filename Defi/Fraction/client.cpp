#include <iostream>
#include "Fraction.h"
#include <ctime>
using namespace std;



int main()
{

	//Problème #4
	Fraction f1(1,2);
	Fraction f2(2,3);
	Fraction f3(3,4);

	f3 =Fraction::additionner(Fraction::additionner(f1,f2),f3);
	f3.afficher();
	// affichera 46/24


	//Problème #5
	Fraction f4(1,2);
	Fraction f5(1,4);

	
	f4.ajouter(f5).ajouter(f5);

	cout << "resultat" << endl;
	f4.afficher();// 32/32


	return 0;

}

