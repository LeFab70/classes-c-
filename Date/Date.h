/*****************************************************************
     Programmer: Fabrice Kouonang
     Date:       17/09/2025
     But:        Devoir 1 - Classe Date
     version:    1.0
     Entete de la classe Date
******************************************************************/

#pragma once // eviter inclusion /appel multiple
#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;
class Date
{
private:
    int jour;  // Jour
    int mois;  // mois
    int annee; // année
    // Recupérer la date courante du système dd/mm/yyyy
    int getCurrentDayValue();
    int getCurrentMonthValue();
    int getCurrentYearValue();

public:
    // constructeur par defaut
    Date();
    // constructeur surcharge
    Date(int, int, int);
    // destructeur
    ~Date();

    // Setters
    bool setJour(int);
    bool setMois(int);
    bool setAnnee(int);

    // Getters
    int getJour(void);
    int getMois(void);
    int getAnnee(void);

    // methode d'affichage
    void afficher(void);
};