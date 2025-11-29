#include "EmployePermanent.h"
EmployePermanent::EmployePermanent() : Employe(), salary(0.0)
{
}
EmployePermanent::EmployePermanent(const string &nom, const string &ssn, double netPay, double salary)
    : Employe(nom, ssn, netPay)
{
    setSalary(salary);
}
EmployePermanent::~EmployePermanent()
{
}
// getter
double EmployePermanent::getSalary() const
{
    return salary;
}
// setter
void EmployePermanent::setSalary(double salary)
{
    if (salary < 0)
    {
        throw invalid_argument("Le salaire ne peut pas etre negatif.");
    }
    this->salary = salary;
}
// afficher salaire
void EmployePermanent::printCheck() const
{
    cout << "Employe permanent: " << endl;
    cout << "Paye a l'ordre de : " << getNom() << endl;
    cout << "Montant cheque: " << salary << " $" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Talon de cheque non-negociable " << endl;
    cout << "SSN employe: " << getSsn() << endl;
    cout << "Paie " << salary << " $" << endl;
    cout << "----------------------------------------" << endl;
}