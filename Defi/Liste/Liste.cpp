#include "Liste.h"


Liste::Liste(void): premier(NULL), quantiteNoeuds(0)
{
	// premier = NULL;
	// quantiteNoeuds = 0;
}

//ajout du constructeur de copie
Liste::Liste(const Liste& autre)
{
	premier = NULL;
	quantiteNoeuds = 0;

	Noeud* enCours = autre.premier;

	while(enCours)
	{
		ajouterFin(enCours->getDonnee());
		enCours = enCours->getSuivant();
	}
}

Liste::~Liste(void)
{
	Noeud* enCours = premier;
	
	
	while(enCours)
	{
		enCours = enCours->getSuivant();
		delete premier;
		premier = enCours;
	}
		
}


Noeud* Liste::getPremier() const
{
	return premier;
}

int Liste::getQuantiteNoeuds() const
{
	return quantiteNoeuds;
}

void Liste::ajouterFin(const Point& p)
{
	//Noeud* nouveau = creerNoeud();
	Noeud* nouveau = new Noeud(p);

	Noeud* enCours = NULL;

	if(premier == NULL)
		premier = nouveau;
	else
	{
		//Se rendre au dernier noeud de la liste
		for(enCours = premier;enCours->getSuivant(); enCours = enCours->getSuivant())
			;
		enCours->setSuivant(nouveau);
	}

	quantiteNoeuds++;
}


void Liste::enleverFin()
{

	Noeud* enCours = premier;
	Noeud* precedant = NULL;
	if(premier == NULL)
		cout << "La liste est vide" << endl;
	else
	{
		//avancer enCours sur le dernier noeud et precedant 
		// sur l'avant-dernier
		while(enCours->getSuivant())
		{
			precedant = enCours;
			enCours = enCours->getSuivant();
		}

		if(enCours == premier)
			premier = NULL;
		else
			precedant->setSuivant(NULL);
		
		quantiteNoeuds--;
		delete enCours;
	}
}

void Liste::enleverDebut()
{
	Noeud* aDeleter = NULL;
	if(premier)
	{
		aDeleter = premier;
		premier = premier->getSuivant();
		delete aDeleter;
		quantiteNoeuds--;
	}
	else
	{
		cout << "La liste est vide" << endl;
	}

}

void Liste::ajouterDebut(const Point& p)
{
	Noeud* enCours = premier;
	premier = new Noeud(p);
	premier->setSuivant(enCours);
	quantiteNoeuds++;
}

void Liste::inverserListe() 
{
	Noeud* precedant = NULL;
	Noeud* enCours = NULL;
	Noeud* prochain = NULL;

	if(premier == NULL)
		cout << "La liste est vide" << endl;
	else if(premier->getSuivant() == NULL)
		cout << "Seulement un noeud dans la liste" << endl;
	else
	{
		//positionne les pointeurs
		precedant = premier;
		enCours = premier->getSuivant();
		prochain = enCours->getSuivant();

		//boucle qui fait le travail
		while(enCours->getSuivant())
		{
			enCours->setSuivant( precedant);
			precedant = enCours;
			enCours = prochain;
			prochain = prochain->getSuivant();

		}

		//les derniers ajustements
		enCours->setSuivant(precedant);
		premier->setSuivant( NULL);
		premier = enCours;

	}


}

void Liste::afficherInverse() const
{
	Noeud* last = NULL;
	Noeud* traverse = premier;
	if(!premier)
		cout << "La liste est vide" << endl;
	else
	{
		while(premier != last)
		{
			while(traverse->getSuivant() != last)
			{
				traverse = traverse->getSuivant();
			}

			traverse->getDonnee().afficher();
			cout << endl;

			last = traverse;
			traverse = premier;
		}
	}

}
void Liste::afficher() const
{
	

	cout << "***Affichage***" << endl;
	if(premier)
	{
		Noeud* traverse = premier;

		while(traverse)
		{
			traverse->getDonnee().afficher();
			cout << endl;
			traverse = traverse->getSuivant();
		}

	}
	else
		cout << "La liste est vide" << endl;

	cout << "***************" << endl;

}
