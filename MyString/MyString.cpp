#include "MyString.h"

//utilisation de la liste d'initialisation sur le constructeur par defaut

MyString::MyString():buf(new char[1]{'\0'}), len(0)
{
   // this->buf = new char[1]; // allouer de la memoire pour une chaine vide
   // this->buf[0] = '\0';     // initialiser la chaine vide
   //this->len = 0;           // longueur initiale est 0
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
MyString::MyString(int nbreCaractere, const char str)
{
    // if (str == nullptr)
    // {
    //     MyString(); // appeler le constructeur par defaut si str est null
    // }
    // else
    //{
        this->len = nbreCaractere;             // definir la longueur de la chaine
        this->buf = new char[this->len + 1]; // allouer de la memoire pour la chaine
        for (int i = 0; i < this->len; i++)
        {
            this->buf[i] = str; // remplir la chaine avec le caractere donne
        }
        this->buf[this->len] = '\0'; // ajouter le caractere de fin de chaine
   // }
}

MyString::~MyString()
{
    delete[] this->buf; // liberer la memoire allouee pour la chaine
}
int MyString::getLength() const
{
    return this->len; // retourner la longueur de la chaine
}
char MyString::getChar(int position) const
{
    if (position < 0 || position >= this->len)
    {
        cout << ("Position hors limites"); // lancer une exception si la position est invalide
        return '\0';
    }
    return this->buf[position]; // retourner le caractere a la position donnee
}
void MyString::afficher() const
{
    cout << this->buf << endl; // afficher la chaine de caracteres
}

char *MyString::getBuffer() const
{
    return this->buf; // retourner le buffer de la chaine
}

void MyString::setBuffer(const char *str)
{
    delete[] this->buf; // liberer l'ancien buffer
    if (str == nullptr)
    {
       MyString(); // appeler le constructeur par defaut si str est null
    }
    else
    {
        this->len = strlen(str);             // obtenir la longueur de la chaine
        this->buf = new char[this->len + 1]; // allouer de la memoire pour la nouvelle chaine
        strcpy(this->buf, str);              // copier la nouvelle chaine dans le buffer
    }
}
