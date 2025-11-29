#pragma once // eviter inclusion /appel multiple
#include <iostream>
#include <cstring>
// #include <string.h>
// #include <stdio.h>
using namespace std;
class Employe
{
private:
    string nom;
    string ssn;
    double netPay;

public:
    Employe(); 
    Employe(const string &nom, const string &ssn, double netPay);
    ~Employe();            
    // getters
    string getNom() const;
    string getSsn() const;
    double getNetPay() const;
    //setters
    void setNom(const string &nom);
    void setSsn(const string &ssn);
    void setNetPay(double netPay);
    //afficher salaire
    void printCheck() const;
};
