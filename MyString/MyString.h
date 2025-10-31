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
    MyString(const MyString &original); // constructeur de copie deep copie /copie en pronfondeur
   
    ~MyString();               // destructeur
    int getLength() const;     // methode pour obtenir la longueur de la chaine
    char getChar(int position) const;     // methode retourne un caractere a une position donnee
    void afficher() const;     // methode pour afficher la chaine de caracteres

 //retourne une adresse  constante vers le buffer pour empecher la modification directe
    const char* getBuffer() const; // methode pour obtenir le buffer de la chaine
     //const le premier const le second 
     //le premier const indique que la methode ne modifie pas l'objet MyString, le type de retour est un pointeur vers un caractere constant
     // le second c pour des valeurs constantes
    void setBuffer(const char* str); // methode pour definir le buffer de la chaine


    //Redefion de l'operateur d'affectation, //retourne une reference vers l'objet courant pour permettre les affectations en chaine
    //copie en shallow /copie en surface, juste les valeurs des attributs sont copiees
    MyString& operator=(const MyString& other);
    void append(const char* other); //methode pour concatener une autre chaine a la fin de la chaine courante
};