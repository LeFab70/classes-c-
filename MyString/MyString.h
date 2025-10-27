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
    MyString(int nbreCaractere,const char str='-'); // constructeur avec parametre et parametre par defaut de remplissage

    ~MyString();               // destructeur
    int getLength() const;     // methode pour obtenir la longueur de la chaine
    char getChar(int position) const;     // methode retourne un caractere a une position donnee
    void afficher() const;     // methode pour afficher la chaine de caracteres

    char* getBuffer() const; // methode pour obtenir le buffer de la chaine
    void setBuffer(const char* str); // methode pour definir le buffer de la chaine
};