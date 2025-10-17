/*****************************************************************
     Programmer: Fabrice Kouonang
     Date:       29/09/2025
     But:        Test1 - Classe Produit
     version:    1.0
     Entete de la classe Produit
******************************************************************/

#pragma once // eviter inclusion /appel multiple
#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;
class Produit
{
private:
    string nom;
    double prix;
    int quantite;

public:
    // constructeur surcharge
    Produit(string, double, int);
    // destructeur
    ~Produit();

    // Setters
    void setNom(string);
    void setPrix(double);
    void setQuantite(int);

    // Getters
    string getNom(void) const;
    double getPrix(void) const;
    int getQuantite(void) const;

    // methode de calcul de la valeur du stock
    double calculerValeurStock(void) const;


    //Methode affiche des informations du produit
    void displayInfo(void) const;
};