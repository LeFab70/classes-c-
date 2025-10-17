#include "MyFirstClass.h"

//Definition des methodes de la classe MyFirstClass avec le symbole :: operateur de resolution de portée
void MyFirstClass::setA(int value) {
    a = value;
}

void MyFirstClass::setB(int value) {
    b = value;
}

int MyFirstClass::getA() {
    return a;
}

int MyFirstClass::getB() {
    return b;
}
void MyFirstClass::display() {
    // afficher les valeurs des propriétés privées
    cout << "La valeur de A est : " << this->getA() << endl; // this est optionnel pointeur sur l'objet courant
    cout << "La valeur de B est : " << getB() << endl;
}