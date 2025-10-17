/*****************************************************************
     Programmer: Fabrice Kouonang
     Fraction:       08/09/2025
     But:        gestion des noeuds dune liste en C++
     version:    1.0
******************************************************************/
#include <iostream>
#include "Node.h"
#include <iomanip>
using namespace std;
const unsigned short SIZE = 10;
/******************** Prototypes des fonctions ****************/

int main(void)
{
     cout << endl
          << endl
          << "Programme des noeuds d'une liste  en POO en C++"
          << endl
          << endl;
     Point p1(2, 3);
     Node *node1 = new Node(p1); // tete de la liste
     Point p2(4, 5);
     Node *node2 = new Node(p2);
     // lier avec adresse de node2

     node1->setSuivant(node2); // lier node1 a node2
     Point p3(6, 7);
     Node *node3 = new Node(p3);
     node2->setSuivant(node3); // lier node2 a node3

     Node *node4 = new Node(Point(8, 9));

     //    Node* node5(new Point(8,9)); //erreur ici

     node3->setSuivant(node4); // lier node3 a node4, node4 est dynamique donc adresse sans &

     // si node statique il faut le & pour adresse

     Node node5(Point(10, 11));
     node4->setSuivant(&node5); // lier node4 a node5 // ici node5 est statique donc on passe son adresse

     // afficher les elements de la liste
     Node *current = node1; // commencer par la tete de la liste

     //  Point p = current->getDonnee();
     //           cout << "Node "  << ": (" << p.getX() << ", " << p.getY() << ")" << endl;

     for (int i = 0; i < SIZE; i++)
     {
          if (current != nullptr)
          {
               //Point p = current->getDonnee();
               //cout << "Node " << i + 1 << ": (" << p.getX() << ", " << p.getY() << ")" << endl;

               current->getDonnee().afficher(); //getDonnee() accede à afficher() car retourne un Point
               current = current->getSuivant(); // passer au noeud suivant
          }
          else
          {
               break; // sortir de la boucle si on a atteint la fin de la liste
          }
     }

     while (current)
     {
          current->getDonnee().afficher(); //getDonnee() accede à afficher() car retourne un Point
          current = current->getSuivant();
     }

     // liberation de la memoire

     delete node3;
     delete node2;
     delete node1;
     delete node4;
     cout << endl
          << endl
          << "Fermeture du programme, \n pressez surla touche entrée,pour quitter le programme"
          << endl
          << endl;
     return 0;
}
/******************** Definitions des fonctions ****************/
