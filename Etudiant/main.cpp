/***************************************************************** 
     Programmer: Fabrice Kouonang
     Date:       08/09/2025
     But:        gestion des etudiants en poo en C++
     version:    1.0
******************************************************************/
#include <iostream>
#include "Etudiant.h"

using namespace std;
/******************** Prototypes des fonctions ****************/

/******************** Programme principal ****************/
int main(void)
{ 
    // Etudiant* etudiant1=new Etudiant(); 
    // etudiant1->setNom("Kouonang Fabrice fddfjkfdkjfkdjjkfdjkfdjkjkfdjkfdjkjkfdjkfdjkkjfdkjfdjkkjjkfdfddffdfdddfdfdffdfdfdfdfvbdffdbbfd");
    // etudiant1->setNumero(12345);
    // etudiant1->afficher();
    // delete etudiant1; //liberer la memoire et appel du destructeur
    // Etudiant etudiant2; // instanciation statique
    // //ici ya un constructeur par defaut qui initialise numero a 0 et nom a chaine vide
    // etudiant2.afficher();
    // etudiant2.init(67890,"Doe John");
    // etudiant2.afficher();
Etudiant etudiant2(67890,"Doe John"); // instanciation statique avec constructeur surcharge
    // //instanciation dynamique avec constructeur surcharge
    // Etudiant* etudiant3=new Etudiant(13579,"Jane Doe");
    // etudiant3->afficher();
    // etudiant3->~Etudiant(); //appel explicite du destructeur ou avec delete
    
    //Manipulations des objets dans un array
    Etudiant* listeEtudiants=new Etudiant[15]; // tableau de pointeurs vers des objets Etudiant
    //le constructeur par defaut est appelé pour chaque objet du tableau soit 15 fois ici
    listeEtudiants[0].afficher();
    delete[] listeEtudiants; //liberer la memoire et appel du destructeur pour chaque objet du tableau
    //ou listeEtudiants->~Etudiant(); //appel explicite du destructeur une seule fois
   
   Etudiant groupeEtudiants[15]; // tableau statique de 15 objets Etudiant
   //le constructeur par defaut est appelé pour chaque objet du tableau soit 15 fois ici
   
    cout << endl
         << endl
         << "Fermeture du programme, \n pressez surla touche entrée,pour quitter le programme"
         << endl
         << endl;
    return 0;
}
