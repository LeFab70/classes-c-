/*****************************************************************
     Programmer: Fabrice Kouonang
     Date:       17/09/2025
     But:        Devoir 1 - Classe Date
     version:    1.0
******************************************************************/
#include <iostream>
#include "Date.h"

using namespace std;
/******************** Prototypes des fonctions ****************/

/******************** Programme principal ****************/
int main(void)
{
     cout << endl
          << endl
          << "Programme de gestion des dates en POO en C++"
          << endl
          << endl;
     cout << endl
          << "--------------------------------------------" << endl;
     Date dateDuJour; // appel du constructeur par defaut
     cout << "Date du jour (constructeur par defaut): ";
     dateDuJour.afficher();
     cout << endl
          << "--------------------------------------------" << endl;

     // Date dateNoel(25, 12, 2026); // appel du constructeur surcharge
     Date *dateNoel = new Date(25, 12, 2026);
     cout << endl
          << "Date de Noel (constructeur surcharge): ";
     dateNoel->afficher();
     cout << endl
          << "--------------------------------------------" << endl;

     // test des setters
     cout << endl
          << endl
          << "Test des setters avec des valeurs invalides"
          << endl
          << endl;
     if (!dateNoel->setJour(32))
          cout << "Echec de la modification du jour" << endl;
     if (!dateNoel->setMois(13))
          cout << "Echec de la modification du mois" << endl;
     if (!dateNoel->setAnnee(2051))
     {
          cout << endl
               << "Nouvelle date de noel avec annee changee: ";
          dateNoel->afficher(); // année modifiée à l'année courante
     }
     cout << endl
          << "--------------------------------------------" << endl;

     // test des getters
     cout << endl
          << "Test des getters pour date de noel"
          << endl
          << endl;
     cout << "Jour: " << dateNoel->getJour() << endl;
     cout << "Mois: " << dateNoel->getMois() << endl;
     cout << "Annee: " << dateNoel->getAnnee() << endl;
     // Appel du comnstructeur avec des valeurs invalides
     cout << endl
          << "--------------------------------------------" << endl;

     Date *dateInvalid = new Date(42, 12, 2580);
     cout << endl
          << "Date avec des valeurs invalides (42,14,2580): ";
     dateInvalid->afficher();
     // setter dateInvalid avec des valeurs valides
     cout << endl
          << "Modification de la date (42,14,2580)-> avec des valeurs valides (24,12,2024): ";
     dateInvalid->setJour(24);
     dateInvalid->setMois(12);
     dateInvalid->setAnnee(2024);
     dateInvalid->afficher();

     // appel du destructeur
     delete dateNoel;
     delete dateInvalid;
     // liberation de la memoire
     cout << endl
          << "--------------------------------------------"
          << endl
          << endl
          << "Fermeture du programme, \n pressez surla touche entrée,pour quitter le programme"
          << endl
          << endl;
     return 0;
}
