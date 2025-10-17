/*****************************************************************
      Programmer: Fabrice Kouonang
     Date:       29/09/2025
     But:        Test1 - Classe Produit
     version:    1.0
    Testing de la classe Produit
******************************************************************/
#include <iostream>
#include "Produit.h"

using namespace std;
/******************** Prototypes des fonctions ****************/

/******************** Programme principal ****************/
int main(void)
{
     cout << endl
          << endl
          << "Programme de gestion des Produits en POO en C++"
          << endl
          << endl;
     cout << endl
          << "--------------------------------------------" << endl;

     Produit p1("Stylo", 2.5, 100);
     Produit *p2 = new Produit("Cahier", 5.0, 200);
     // valeurs de la quantité  hors des limites
     p1.displayInfo();
     p1.setNom("Crayon");
     p1.setPrix(0.5);     // prix inferieur à 0,99
     p1.setQuantite(500); // quantité superieur à 150
     cout << endl
          << "Apres modification test des valeurs dans setters" << endl;
     p1.displayInfo();

     p2->displayInfo();
     p2->setQuantite(-20); // quantité inferieur à 0
     p2->setPrix(0.99);    // prix egale à 0,99
     p2->displayInfo();

     p2->setQuantite(50); // quantité dans les limites
     p2->displayInfo();
     // Destruction de objet dynamique
     delete p2;
     cout << endl
          << "--------------------------------------------"
          << endl
          << endl
          << "Fermeture du programme, \n pressez surla touche entrée,pour quitter le programme"
          << endl
          << endl;
     return 0;
}
