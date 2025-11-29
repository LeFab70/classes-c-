#pragma once // eviter inclusion /appel multiple
#include <iostream>
#include <cstring>
#include "Employe.h"
// #include <string.h>
// #include <stdio.h>
using namespace std;
class EmployeContrat : public Employe
{
    private :
        double wageRate;
        double hours;
    public:
        EmployeContrat();
        EmployeContrat(const string &nom, const string &ssn, double netPay, double wageRate, double hours);
        ~EmployeContrat();
        //getters
        double getWageRate() const;
        double getHours() const;
        //setters
        void setWageRate(double wageRate);
        void setHours(double hours);
        //afficher salaire
        void printCheck() const;
};