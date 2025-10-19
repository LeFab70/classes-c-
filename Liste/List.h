#pragma once // eviter inclusion /appel multiple
#include <iostream>
#include <cstring>
#include "Point.h"
#include "Node.h"
using namespace std;
class List
{
private:
    Node *premier;
    int qunatiteNodes;

public:
    List();
    ~List();
    Node *getPremier() const;
    int getQuantiteNodes() const;
    void ajouterFin(Point p);
    void afficher() const;
};