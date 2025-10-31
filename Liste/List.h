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
    void ajouterFin(const Point &p);
    void afficher() const;
    void enleverFin();
    void enleverDebut();
    void ajouterDebut(const Point &p);
    void inverserListe();
    void viderListe();
};