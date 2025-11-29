#pragma once
#include <iostream>

// erreur: using namespace std; manquant
using namespace std;
template <class T>

class Pile
{
private:
	T valeurs[4];
	// max doit etre en majuscule par convention
	const int MAX;
	int sommet;
	// erreur: les methodes estPleine et estVide doivent etre const
	bool estPleine() const;
	bool estVide() const;

public:
	Pile(void);
	~Pile(void);
	// erreur: le type de parametre doit etre int au lieu de double
	void push(T);
	T pop();
	// erreur: le nom de la methode doit etre affichePile au lieu de afficherPile
	// erreur: la methode doit etre const
	void afficherPile() const;
};

// Implementation des methodes de la classe Pile dans le fichier entete

// erreur: max doit etre initialise dans la liste d'initialisation du constructeur car c'est une constante
template <class T>
Pile<T>::Pile(void) : MAX(4)
{
	sommet = 0;
	cout << "Constructeur de la pile" << endl;
}

template <class T>
Pile<T>::~Pile(void)
{
	cout << "Destructeur de la pile" << endl;
}

template <class T>
void Pile<T>::push(T data)
{
	if (estPleine())
		cout << "Stack overflow!" << endl;
	else
	{
		// sommet++;
		valeurs[sommet++] = data;
	}
}

template <class T>
T Pile<T>::pop()
{
	if (estVide())
	{
		cout << "Stack underflow..." << endl;
		return 0;
	}
	else
	{
		// sommet--;
		return valeurs[--sommet];
	}
}

template <class T>
void Pile<T>::afficherPile() const
{
	int index = sommet - 1;

	for (; index >= 0; index--)
		cout << valeurs[index] << endl;
}

template <class T>
bool Pile<T>::estPleine() const
{
	return sommet == MAX;
}
template <class T>
bool Pile<T>::estVide() const
{
	return sommet == 0;
}