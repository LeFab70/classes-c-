/*****************************************************************
     Programmer: Fabrice Kouonang
     Fraction:       08/09/2025
     But:        gestion d'une liste en C++
     version:    1.0
******************************************************************/
#include <iostream>
#include "List.h"
#include <iomanip>
using namespace std;
// const unsigned short SIZE = 10;
/******************** Prototypes des fonctions ****************/

int main(void)
{
     cout << endl
          << endl
          << "Programme d'une liste  en POO en C++"
          << endl
          << endl;
     List *liste = new List(); // creer une liste vide
     // seed pour random
     srand((unsigned)time(NULL));
     int size = rand() % 20 + 5; // taille aleatoire entre 5 et 25
     // ajouter des points a la liste
     for (int i = 0; i < size; i++)
     {
          // avec random
          Point *p = new Point(rand() % 100, rand() % 100); // creer un point dynamique avec coordonnees aleatoires
          liste->ajouterFin(*p);                            // ajouter le point a la fin de la liste
          delete p;                                         // liberation de la memoire occupee par le point
     }

     // afficher les elements de la liste
     cout << "La liste contient " << liste->getQuantiteNodes() << " points:" << endl;
     liste->afficher(); // afficher les points de la liste

     delete liste; // liberation de la memoire occupee par la liste
     cout << endl
          << endl
          << "Fermeture du programme, \n pressez surla touche entrée,pour quitter le programme"
          << endl
          << endl;
     return 0;
}
/******************** Definitions des fonctions ****************/
