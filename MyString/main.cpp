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
     cout << "Le caractere a la position 7 de la chaine 2 est : " << chaine2->getChar(7) << endl;

     // Maj chaine1
     chaine1->setBuffer("Ceci est une nouvelle chaine pour chaine1");
     chaine1->afficher();

     // Creation d'une chaine avec le constructeur a deux parametres
     MyString chaine3(10, '*');
     cout << "Chaine 3 (chaine avec constructeur a deux parametres): ";
     chaine3.afficher();

     MyString chaine4(15);
     cout << "Chaine 4 (chaine avec constructeur a deux parametres et parametre par defaut): ";
     chaine4.afficher();

     // strcpy(chaine4.getBuffer(),"Hello World!");// modification directe du buffer impossible car getBuffer retourne un pointeur constant

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
