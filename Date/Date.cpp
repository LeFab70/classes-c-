/*****************************************************************
     Programmer: Fabrice Kouonang
     Date:       17/09/2025
     But:        Devoir 1 - Classe Date
     Definition de la classe Date
******************************************************************/

#include "Date.h"

Date::Date()
{ // initialisation avec la date courante
    this->jour = this->getCurrentDayValue();
    this->mois = this->getCurrentMonthValue();
    this->annee = this->getCurrentYearValue();
}

// getters pour la date courante du systeme
int Date::getCurrentDayValue()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    return ltm->tm_mday;
}
int Date::getCurrentMonthValue()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    return 1 + ltm->tm_mon;
}
int Date::getCurrentYearValue()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    return 1900 + ltm->tm_year;
}

// constructeur surchargé
Date::Date(int day, int month, int year)
{
    (day > 0 && day < 32) ? this->jour = day : this->jour = getCurrentDayValue();
    (month > 0 && month < 13) ? this->mois = month : this->mois = getCurrentMonthValue();
    (year > 1950 && year < 2050) ? this->annee = year : this->annee = getCurrentYearValue();
}

// destructeur
Date::~Date()
{
    // cout << "Destructeur appele, objet detruit" << endl;
}

// Setters
bool Date::setMois(int month)
{
    if (month < 1 || month > 12)
    {
        cout << "Erreur: le mois doit etre compris entre 1 et 12" << endl;
        return false;
    }
    this->mois = month;
    return true;
}
bool Date::setAnnee(int year)
{
    if (year < 1950 || year > 2050)
    {
        cout << "Erreur: l'annee doit etre comprise entre 1950 et 2050, elle est mise a l'annee courante par defaut." << endl;
        this->annee = getCurrentYearValue();
        return false;
    }
    this->annee = year;
    return true;
}
bool Date::setJour(int day)
{
    if (day < 1 || day > 31)
    {
        cout << "Erreur: le jour doit etre compris entre 1 et 31" << endl;
        return false;
    }
    this->jour = day;
    return true;
}

// Getters
int Date::getJour(void)
{
    return this->jour;
}
int Date::getMois(void)
{
    return this->mois;
}
int Date::getAnnee(void)
{
    return this->annee;
}

// methode d'affichage
void Date::afficher(void)
{
    cout << this->getJour()
         << "/" << this->getMois() << "/" << this->getAnnee();
}
