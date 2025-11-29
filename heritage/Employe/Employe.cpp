#include "Employe.h"
Employe::Employe() : nom(""), ssn(""), netPay(0.0)
{
}
Employe::Employe(const string &nom, const string &ssn, double netPay)
{
    setNom(nom);
    setSsn(ssn);
    setNetPay(netPay);
}

Employe::~Employe()
{
}
// getters
string Employe::getNom() const
{
    return nom;
}
string Employe::getSsn() const
{
    return ssn;
}
double Employe::getNetPay() const
{
    return netPay;
}
// setters
void Employe::setNom(const string &nom)
{
    if (nom.empty() || nom.length() > 50 || nom == " ")
    {
        throw invalid_argument("Nom invalide.");
    }

    this->nom = nom;
}
void Employe::setSsn(const string &ssn)
{
    if (ssn.empty() || ssn.length() > 50 || ssn == " ")
    {
        throw invalid_argument("ssn invalide.");
    }
    this->ssn = ssn;
}
void Employe::setNetPay(double netPay)
{
    if (netPay < 0)
    {
        throw invalid_argument("Le salaire ne peut pas etre negatif.");
    }
    this->netPay = netPay;
}
// afficher salaire
void Employe::printCheck() const
{
    cerr << "Erreur ! Methode printCheck() appelee pour un employe non-categorise.\n";
}