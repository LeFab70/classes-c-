#pragma once
#include "Point.h"
#include <iostream>
using namespace std;

class Noeud
{
private:
	Point donnee;
	Noeud* suivant;
public:
	Noeud(void);
	Noeud(const Point&);
	~Noeud(void);
	void setDonnee(const Point&);
	Point getDonnee() const;
	void setSuivant(Noeud*);
	Noeud* getSuivant() const;

};

