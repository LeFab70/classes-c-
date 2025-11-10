#pragma once
#include "Noeud.h"
#include <iostream>
using namespace std;

class Liste
{
private:
	Noeud* premier;
	int quantiteNoeuds;
public:
	Liste(void);
	//ajout construecteur de copie
	Liste(const Liste& autre);
	~Liste(void);
	Noeud* getPremier() const;
	int getQuantiteNoeuds() const;
	void ajouterFin(const Point&);
	void enleverFin();
	void enleverDebut();
	void ajouterDebut(const Point&);
	void inverserListe();
	void afficherInverse() const;
	void afficher() const;
};

