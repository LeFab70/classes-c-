/***************************************************************** 
     Programmer: Fabrice Kouonang
     Date:       05/09/2025
     But:        Initialiser un programme en POO en C++
     version:    1.0
******************************************************************/
#include <iostream>
#include "MyFirstClass.h"

using namespace std;
/******************** Prototypes des fonctions ****************/

/******************** Programme principal ****************/
int main(void)
{
     //creer un objet de la classe MyFirstClass
     MyFirstClass obj1; // instanciation de la classe de facon statique
     cout<<"getA() avant initialisation : "<<obj1.getA()<<endl; // valeur indéfinie ou garbage
     cout << "Initialisation du programme en POO en C++" << endl;
     //utilisation des methodes de l'objet obj1
     obj1.setA(10);
     obj1.setB(20);
     obj1.display();
     cout<<"Taille de objet en memoire"<<sizeof(obj1)<<endl; // taille de l'objet en octets dependant du systeme 32 ou 64 bits de tous les attributs
     //obj1.c = 30; // propriété public
     // cout << "La valeur de A est : " << obj1.getA() << endl;
     // cout << "La valeur de B est : " << obj1.getB() << endl;
     //cout << "La valeur de C est public : " << obj1.c << endl;

    MyFirstClass* obj2 = new MyFirstClass(); // instanciation de la classe de facon dynamique
     obj2->setA(100); //access à la méthode avec l'opérateur flèche -> et non . comme en statique
     obj2->setB(200);
     obj2->display();
     cout<<"Taille de objet dynamique en memoire "<<sizeof(obj2)<<endl;

//faut detruire l'objet dynamique pour liberer la memoire
     delete obj2;
     cout << endl
         << endl
         << "Fermeture du programme, \n pressez surla touche entrée,pour quitter le programme"
         << endl
         << endl;
    return 0;
}
