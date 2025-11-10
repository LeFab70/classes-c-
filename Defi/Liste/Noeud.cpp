#include "Noeud.h"


Noeud::Noeud(void)
{
	suivant = NULL;
	
}


Noeud::~Noeud(void)
{
}


Noeud::Noeud(const Point& p)
{
	donnee = p;
	suivant = NULL;
}
	
void Noeud::setDonnee(const Point& p)
{
	donnee = p;

}
Point Noeud::getDonnee() const
{
	return donnee;
}

void Noeud::setSuivant( Noeud* suivant)
{
	this->suivant = suivant;
}

Noeud* Noeud::getSuivant()const
{
	return suivant;
}