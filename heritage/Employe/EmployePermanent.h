#pragma once // eviter inclusion /appel multiple
#include <iostream>
#include <cstring>
#include "Employe.h"
// #include <string.h>
// #include <stdio.h>
using namespace std;
class EmployePermanent : public Employe
{
private:
    double salary; //weekly salary
public:
    EmployePermanent();
    EmployePermanent(const string &nom, const string &ssn, double netPay, double salary);
    ~EmployePermanent();
    //getter
    double getSalary() const;
    //setter
    void setSalary(double salary);
    //afficher salaire
    void printCheck() const;
};