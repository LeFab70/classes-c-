/*****************************************************************
     Programmer: Fabrice Kouonang
     Date:       29/09/2025
     But:        Test1 - Classe Produit
     version:    1.0
   Définition de la classe Produit
******************************************************************/

#include "Produit.h"

// setters
void Produit::setNom(string nom)
{
    this->nom = nom;
}
void Produit::setPrix(double prix)
{
    prix < 0.99 ? this->prix = 0.99 : this->prix = prix;
}

void Produit::setQuantite(int quantite)
{
    if (quantite < 0)
        this->quantite = 0;
    else if (quantite > 150)
        this->quantite = 150;
    else
        this->quantite = quantite;
}

// Getters
string Produit::getNom(void) const
{
    return this->nom;
}

double Produit::getPrix(void) const
{
    return this->prix;
}

int Produit::getQuantite(void) const
{
    return this->quantite;
}

// Methode de calcul de la valeur du stock
double Produit::calculerValeurStock(void) const
{
    double valeurStock = this->prix * this->quantite;
    return valeurStock;
}

// constructeur surcharge
Produit::Produit(string nom, double prix, int quantite)
{
    // initialisation des attributs avec les setters
    setNom(nom);
    setPrix(prix);
    setQuantite(quantite);
}

// destructeur
Produit::~Produit()
{
}

void Produit::displayInfo(void) const
{
    cout << "Nom du produit: " << this->getNom() << "   Quantite en stock: " << this->getQuantite() << "  Prix: " << this->getPrix() << endl
         << " Valeur du stock: " << this->calculerValeurStock() << endl;
}
