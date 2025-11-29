#include "EmployeContrat.h"
EmployeContrat::EmployeContrat() : Employe(), wageRate(0.0), hours(0.0)
{
}
EmployeContrat::EmployeContrat(const string &nom, const string &ssn, double netPay, double wageRate, double hours)
    : Employe(nom, ssn, netPay)
{
    setWageRate(wageRate);
    setHours(hours);
}
EmployeContrat::~EmployeContrat()
{
}
// getters
double EmployeContrat::getWageRate() const
{
    return wageRate;
}
double EmployeContrat::getHours() const
{
    return hours;
}
// setters
void EmployeContrat::setWageRate(double wageRate)
{
    if (wageRate < 0)
    {
        throw invalid_argument("Le taux horaire ne peut pas etre negatif.");
    }
    this->wageRate = wageRate;
}
void EmployeContrat::setHours(double hours)
{
    if (hours < 0)
    {
        throw invalid_argument("Le nombre d'heures ne peut pas etre negatif.");
    }
    this->hours = hours;
}
// afficher salaire
void EmployeContrat::printCheck() const
{
    double grossPay = wageRate * hours;
    cout << "Employe a contrat: " << endl;
    cout << "Paye a l'ordre de : " << getNom() << endl;
    cout << "Montant cheque: " << grossPay << " $" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Talon de cheque non-negociable " << endl;
    cout << "SSN employe: " << getSsn() << endl;
    cout << "Nombre d'heures: " << hours << endl;
    cout << " Taux horaire: $" << wageRate << " par heure." << endl;
    cout << "Paie " << grossPay << " $" << endl;
    cout << "----------------------------------------" << endl;
}