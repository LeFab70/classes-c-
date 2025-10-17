/*****************************************************************
     Programmer: Fabrice Kouonang
     Fraction:       08/09/2025
     But:        gestion des fractions en poo en C++
     version:    1.0
******************************************************************/
#include <iostream>
#include "Point.h"
#include <iomanip>
using namespace std;
const unsigned short SIZE = 10;
/******************** Prototypes des fonctions ****************/

int main(void)
{
     cout << endl
          << endl
          << "Programme de gestion des points en POO en C++"
          << endl
          << endl;

     Point A(2, 3);
     Point B(5, 7);
     A.afficher();
     B.afficher();
     cout << "Distance entre A et B: " << fixed << setprecision(2) << A.distance(B) << endl;
     cout << "Distance entre A et (0,0): " << fixed << setprecision(2) << A.distance(0, 0) << endl;
     A.move(1, 1);
     A.afficher();
     if (A.isOrigin())
          cout << "A est a l'origine" << endl;
     else
          cout << "A n'est pas a l'origine" << endl;
     A.move(B);
     A.afficher();
     A.setLocation(0, 0);
     if (A.isOrigin())
          cout << "A est a l'origine" << endl;
     else
          cout << "A n'est pas a l'origine" << endl;

     if (A.isEqual(B))
          cout << "A est egal a B" << endl;
     else
          cout << "A n'est pas egal a B" << endl;
     // Point tab[SIZE]; // tableau de point
     //  int x, y;
     //  for (unsigned short i = 0; i < SIZE; i++)
     //  {
     //       cout << "Entrer les coordonnees du point " << i + 1 << " (x y): ";
     //       cin >> x >> y;
     //       tab[i].setLocation(x, y);
     //  }

//destructeur automatique pour les objets statiques
// destructeur pour tableaux d'objets dynamique
// delete[] tab;
     cout << endl
          << endl
          << "Fermeture du programme, \n pressez surla touche entrée,pour quitter le programme"
          << endl
          << endl;
     return 0;
}
/******************** Definitions des fonctions ****************/
