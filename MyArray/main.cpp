/*****************************************************************
     Programmer: Fabrice Kouonang
     MyArray:      03/11/2025
     But:        Devoir 2 - Classe MyArray en C++
     version:    1.0
******************************************************************/
#include <iostream>
#include "MyArray.h"
#include <iomanip>
using namespace std;
/******************** Prototypes des fonctions ****************/

int main(void)
{
     cout << endl
          << endl
          << "Programme des Array  en POO en C++"
          << endl
          << endl;

     MyArray *array1 = new MyArray();
     array1->add(10);
     array1->add(20);
     array1->add(30);
     cout << "Taille du tableau apres ajout de 3 elements: " << array1->getSize() << endl;
     cout << "Elements du tableau: ";
     for (unsigned int i = 0; i < array1->getSize(); i++)
     {
          cout << array1->getAt(i) << " ";
     }

     cout << endl;
     // recherche d'un element
     int index = array1->find(20);
     if (index != -1)
     {
          cout << "Element 20 trouve a l'index: " << index << endl;
     }
     else
     {
          cout << "Element 20 non trouve dans le tableau." << endl;
     }

     // suppression du dernier element
     array1->remove();
     cout << "Taille du tableau apres suppression du dernier element: " << array1->getSize() << endl;
     cout << "Elements du tableau: ";
     for (unsigned int i = 0; i < array1->getSize(); i++)
     {
          cout << array1->getAt(i) << " ";
     }

     cout << endl;

     // construceur avec parametre

     MyArray *copie = new MyArray(*array1);

     cout << "Taille du tableau copie: " << copie->getSize() << endl;
     // affichage des elements du tableau copie
     cout << "Elements du tableau copie: ";
     for (unsigned int i = 0; i < copie->getSize(); i++)
     {
          cout << copie->getAt(i) << " ";
     }
     cout << endl;
     // ajout d'elements au tableau copie
     copie->add(100);
     copie->add(200);
     cout << "Taille du tableau copie apres ajout d'elements: " << copie->getSize() << endl;
     cout << "Elements du tableau copie apres ajout d'elements: ";
     for (unsigned int i = 0; i < copie->getSize(); i++)
     {
          cout << copie->getAt(i) << " ";
     }
     cout << endl;
     // utilisation des iterateurs begin() et back()
     cout << "Premier element du tableau copie (begin): " << *(copie->begin()) << endl;
     cout << "Dernier element du tableau copie (back): " << *(copie->back()) << endl;

     // suppression de tous les elements
     array1->removeAll();
     cout << "Taille du tableau apres suppression de tous les elements: " << array1->getSize() << endl;
     // taill de copie apres suppression de tous les elements de array1
     cout << "Taille du tableau copie apres suppression de tous les elements de array1: " << copie->getSize() << endl;
     // liberation de la memoire
     delete array1;
     delete copie;
     cout << endl
          << endl
          << "Fermeture du programme, \n pressez surla touche entrée,pour quitter le programme"
          << endl
          << endl;
     return 0;
}
/******************** Definitions des fonctions ****************/
