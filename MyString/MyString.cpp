#include "MyString.h"

MyString::MyString()
{
    this->buf = new char[1]; // allouer de la memoire pour une chaine vide
    this->buf[0] = '\0';     // initialiser la chaine vide
    this->len = 0;           // longueur initiale est 0
}
MyString::MyString(const char *str)
{
    if (str == nullptr)
    {
        MyString(); // appeler le constructeur par defaut si str est null
    }
    else
    {
        this->len = strlen(str);             // obtenir la longueur de la chaine
        this->buf = new char[this->len + 1]; // allouer de la memoire pour la chaine
        strcpy(this->buf, str);              // copier la chaine dans le buffer
    }
}
MyString::~MyString()
{
    delete[] this->buf; // liberer la memoire allouee pour la chaine
}
int MyString::getLength() const
{
    return this->len; // retourner la longueur de la chaine
}
char *MyString::getChar() const
{
    return this->buf; // retourner le pointeur vers la chaine de caracteres
}
void MyString::afficher() const
{
    cout << this->buf << endl; // afficher la chaine de caracteres
}