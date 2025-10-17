#pragma once // eviter inclusion /appel multiple
#include <iostream>
using namespace std;
class MyFirstClass
{
private:
    // declarer des propriétés privées
    int a;
    int b;

// Access public
// public:
//  int c;  // propriété public pas autorisé ici car pas bonne pratique respecte pas encapsulation


// les membres publics qui sont des méthodes permetteront d'accéder aux propriétés privées de la classe
// respecter le principe d'encapsulation
public:
    // declarer des méthodes publiques getters et setters
    void setA(int valA);
    
    void setB(int valB);
    //getter pour lire les valeurs des propriétés privées
    int getA(void);
    int getB(void);

    // methode pour afficher les valeurs des propriétés privées
    void display(void);
};
