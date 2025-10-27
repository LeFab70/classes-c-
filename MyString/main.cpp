/*****************************************************************
     Programmer: Fabrice Kouonang
     Fraction:       08/09/2025
     But:        class string en C++
     version:    1.0
******************************************************************/
#include <iostream>
#include "MyString.h"
#include <iomanip>
using namespace std;
/******************** Prototypes des fonctions ****************/

int main(void)
{
     cout << endl
          << endl
          << "Programme des string  en POO en C++"
          << endl
          << endl;
     MyString *chaine1 = new MyString();                   // chaine vide
     MyString *chaine2 = new MyString("Bonjour le monde"); // chaine avec initialisation
     cout << "Chaine 1 (chaine vide): ";
     chaine1->afficher();                                                 // afficher chaine1
     cout << "Longueur de la chaine 1: " << chaine1->getLength() << endl; // afficher longueur chaine1
     cout << "Chaine 2 (chaine initialisee): ";
     chaine2->afficher();                                                 // afficher chaine2
     cout << "Longueur de la chaine 2: " << chaine2->getLength() << endl; // afficher longueur chaine2

     // liberation de la memoire

     delete chaine1;
     delete chaine2;
     cout << endl
          << endl
          << "Fermeture du programme, \n pressez surla touche entrée,pour quitter le programme"
          << endl
          << endl;
     return 0;
}
/******************** Definitions des fonctions ****************/
