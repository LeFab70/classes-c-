/*****************************************************************
     Programmer: Fabrice Kouonang
     MyArray:      03/11/2025
     But:        Devoir 2 - Classe MyArray  en C++
     version:    1.0
******************************************************************/

#pragma once // eviter inclusion /appel multiple
#include <iostream>
#include <cstring>

using namespace std;
class MyArray
{
private:
    int *tableau;
    unsigned int taille;

public:
    MyArray();
    MyArray(const MyArray& original);
    ~MyArray();
    void add(const int element); // ajouter element à la fin du tableau
    void remove();
    unsigned int getSize() const;
    void removeAll();                  // supprimer tous les elements du tableau
    int find(const int element) const; // trouver l'index d'un element dans le tableau, retourne -1 si non trouve
    int getAt(const int index) const;  // obtenir l'element a un index donne
    int *begin() const;                // retourne un pointeur vers le premier element du tableau
    int *back() const;                 // retourne un pointeur vers la fin du tableau
};