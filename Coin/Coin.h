/*****************************************************************
     Programmer: Fabrice Kouonang
     Date:       29/09/2025
     But:        coin
     version:    1.0
     Entete de la classe coin
******************************************************************/

#pragma once // eviter inclusion /appel multiple
#include <iostream>
#include <cstring>
#include <ctime>
#include "MersenneTwister.h"
using namespace std;
class Coin
{
private:
    bool face;
    MTRand randMT; // instance du generateur de nombres aleatoires

public:
    // constructeur surcharge
    Coin();
    ~Coin();
    // Getters
    bool getFace(void) const;
    void flip(void);
    void afficher(void) const;
    bool isHeads(void) const;

    // les prorpietes statiques de la classe sont accessible à exterieur
    // leurs valeurs sont definies dans le fichier cpp
    static const bool HEADS;
    static const bool TAILS;

    void flipMt(void);
};