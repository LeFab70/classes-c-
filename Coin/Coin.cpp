/*****************************************************************
     Programmer: Fabrice Kouonang
     Date:       29/09/2025
     But:        Test1 - Classe coin
     version:    1.0
   Définition de la classe coin
******************************************************************/

#include "Coin.h"

// valeurs des proprietes statiques
const bool Coin::HEADS = true;
const bool Coin::TAILS = false;

// constructeur par defaut
Coin::Coin()
{

    // initialiser la graine pour le generateur de nombres aleatoires
    srand(static_cast<unsigned int>(time(0)));
    // lancer le premier flip
    flip();
}
// destructeur
Coin::~Coin()
{
}
// getters
bool Coin::getFace(void) const
{
    return face;
}
// methode pour lancer le coin
void Coin::flip(void)
{
    // generer un nombre aleatoire entre 0 et 1
    int randomValue = rand() % 2;             // 0 ou 1
    face = (randomValue == 0) ? false : true; // false pour pile, true pour face
}
// methode pour afficher le resultat du lancer
void Coin::afficher(void) const
{
    face ? cout << "Heads" : cout << "Tails";
}
// methode pour verifier si le coin est face
bool Coin::isHeads(void) const
{
    return face;
}

// utiliser le generateur de nombres aleatoires Mersenne Twister
void Coin::flipMt(void)
{
    //face = (randMT.randInt(1) == 0) ? false : true;
    face=randMT.randInt(1);
}

Coin &Coin::operator++()
{
    this->flipMt();
    return *this;
}
Coin &Coin::operator++(int)
{
    this->flipMt();
    return *this;
}

ostream &operator<<(ostream &out, const Coin &obj)
{
    out << ((obj.face == Coin::HEADS) ? "Heads" : "Tails");
    return out;
}
