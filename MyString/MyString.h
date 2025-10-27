#pragma once // eviter inclusion /appel multiple
#include <iostream>
#include <cstring>

using namespace std;
class MyString
{
private:
    char *buf; // pointeur vers la chaine de caracteres
    int len;   // longueur de la chaine de caracteres

public:
    MyString();                // constructeur par defaut
    MyString(const char *str); // constructeur avec parametre
    ~MyString();               // destructeur
    int getLength() const;     // methode pour obtenir la longueur de la chaine
    char *getChar() const;     // methode pour obtenir la chaine de caracteres
    void afficher() const;     // methode pour afficher la chaine de caracteres
};