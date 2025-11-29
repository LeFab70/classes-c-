#include "Etudiant.h"

Etudiant::Etudiant()
{
    this->numero = 0;
    strcpy(this->nom, "");
}

//constructeur surchargé
Etudiant::Etudiant(int numero, const char* nom)
{
    setNumero(numero);
    setNom(nom);
}

Etudiant::~Etudiant()
{
//vide
    cout << "Destructeur de l'objet Etudiant appelé pour " << this->nom << endl;
}

void Etudiant::setNumero(int numero)
{
    // if(numero%10==0){
    //  this->numero = numero;
    // }
    // else{
    //        this->numero = 0; 
    // }
    this->numero = (numero % 10 == 0) ? numero : 0;
}
void Etudiant::setNom(const char* nom){
   if(strlen(nom)>30){
    cout<<"Erreur: le nom est trop long, il doit contenir au plus 30 caracteres."<<endl;
    return;
   }
    this->nom[29] = '\0'; 
    strncpy(this->nom, nom, 29); 

    //strcpy_s(this->nom,nom,29);
}
int Etudiant::getNumero(void){
    return this->numero;
}
const char* Etudiant::getNom(void){
    return this->nom;
}
void Etudiant::afficher(void){
    cout<<"----------------------------"<<endl;
    cout << "Numero: " << this->getNumero() 
    << ", Nom: " << this->getNom() << endl;
}

void Etudiant::init(int numero, const char *nom)
{
    //appel des setters
    this->setNumero(numero);
    this->setNom(nom);
}
