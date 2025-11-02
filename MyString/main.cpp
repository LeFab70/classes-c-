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

     // constructeur par casting
     // le moot cle explicit empêche les conversions implicites
     // MyString jour = "C'est halloween aujourd'hui!";
     //  cout << "Constructeur par casting: "<< endl;
     //  jour.afficher();
     //  MyString separator = 20;
     //  separator.afficher();

     // MyString *chaine1 = new MyString();                   // chaine vide
     // MyString *chaine2 = new MyString("Bonjour le monde"); // chaine avec initialisation
     // cout << "Chaine 1 (chaine vide): ";
     // chaine1->afficher();                                                 // afficher chaine1
     // cout << "Longueur de la chaine 1: " << chaine1->getLength() << endl; // afficher longueur chaine1
     // cout << "Chaine 2 (chaine initialisee): ";
     // chaine2->afficher();                                                 // afficher chaine2
     // cout << "Longueur de la chaine 2: " << chaine2->getLength() << endl; // afficher longueur chaine2
     // cout << "Le caractere a la position 7 de la chaine 2 est : " << chaine2->getChar(7) << endl;

     // // Maj chaine1
     // chaine1->setBuffer("Ceci est une nouvelle chaine pour chaine1");
     // chaine1->afficher();

     // // Creation d'une chaine avec le constructeur a deux parametres
     // MyString chaine3(10, '*');
     // cout << "Chaine 3 (chaine avec constructeur a deux parametres): ";
     // chaine3.afficher();

     // MyString chaine4(15);
     // cout << "Chaine 4 (chaine avec constructeur a deux parametres et parametre par defaut): ";
     // chaine4.afficher();

     // // strcpy(chaine4.getBuffer(),"Hello World!");// modification directe du buffer impossible car getBuffer retourne un pointeur constant

     // // liberation de la memoire

     // delete chaine1;
     // delete chaine2;

     // MyString *chaine5 = new MyString("Hello ");
     // chaine5->append("World!"); // concatener une autre chaine
     // cout << "Chaine 5 apres concatenation: ";
     // chaine5->afficher();

     // delete chaine5;
     // // Test others
     // cout << "Test autres methodes: " << endl;

     // MyString *nom = new MyString("Fabrice");
     // MyString *nom2 = new MyString();
     // nom2 = nom; // affectation de l'adresse de nom a nom2
     // MyString *nom3 = new MyString();
     // *nom3 = *nom; // copie du contenu de nom dans nom3
     // cout << "Nom 1: ";
     // nom->afficher();
     // cout << "Nom 2: ";
     // nom2->afficher();
     // MyString *copie = new MyString(*nom); // appel du constructeur de copie

     // delete nom3;  // ceci genere une erreur car nom3 pointe vers une adresse deja liberee
     // delete copie; // ceci genere une erreur car copie pointe vers une adresse deja liberee
     // // pour eviter ceci il faut implement soit meme le constructeur de copie et l'operateur d'affectation
     // // copie en profondeur et copie superficielle

     // delete nom; // libere la memoire de nom
     // delete nom2;

     cout << endl
          << endl
          << "Fermeture du programme, \n pressez surla touche entrée,pour quitter le programme"
          << endl
          << endl;
     return 0;
}
/******************** Definitions des fonctions ****************/
