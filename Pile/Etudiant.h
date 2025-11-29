#pragma once // eviter inclusion /appel multiple
#include <iostream>
#include <cstring>
// #include <string.h>
// #include <stdio.h>
using namespace std;
class Etudiant
{
private:
int numero;
char nom[30];
 public:
 //constructeur par defaut
 Etudiant();
 //constructeurs surcharge
 //sil est defini il remplace celui par defaut, donc faut redefini celui par defaut si des objet avec constructeur par defaut
 Etudiant(int numero, const char* nom);

 //destructeur il ya un seul ou celui par defaut quand objet est static
 ~Etudiant();
 void setNumero(int numero);
 void setNom(const char* nom);
 int getNumero(void);
 const char* getNom(void);
 void afficher(void);
 void init(int numero, const char* nom);

};