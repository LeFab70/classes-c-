#pragma once // eviter inclusion /appel multiple
#include <iostream>
#include <cstring>
#include "Point.h"
using namespace std;
class Node
{
private:
    Point donnee;
    Node *suivant;

public:
    Node(Point p); // constructeur
    ~Node();       // destructeur
    void setDonnee(Point p);
    void setSuivant(Node *n);
    Point getDonnee() const;
    Node *getSuivant() const;
};