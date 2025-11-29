#include "Employe.h"
#include "EmployePermanent.h"
#include "EmployeContrat.h"

#include <iostream>
using namespace std;
int main()
{
    try
    {
        EmployePermanent emp1("John Doe", "123-45-6789", 0.0, 1500.0);
        emp1.printCheck();

        EmployeContrat emp2("Jane Smith", "987-65-4321", 0.0, 20.0, 80.0);
        emp2.printCheck();
    }
    catch (const exception &e)
    {
        cerr << "Erreur: " << e.what() << endl;
    }

    return 0;
}