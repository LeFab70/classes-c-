/*****************************************************************
     Programmer: Fabrice Kouonang
     Fraction:      03/10/2025
     But:        class Array en C++
     version:    1.0
******************************************************************/

#include "MyArray.h"

MyArray::MyArray() : tableau(nullptr), taille(0)
{
    // tableau = nullptr;
    // taille = 0;
}

MyArray::MyArray(const MyArray &original)
{
    this->taille = original.taille;
    if (this->taille > 0)
    {
        this->tableau = new int[this->taille];
        for (unsigned int i = 0; i < this->taille; i++)
        {
            this->tableau[i] = original.tableau[i];
        }
    }
    else
    {
        this->tableau = nullptr;
    }
}
MyArray::~MyArray()
{
    delete[] this->tableau;
}
void MyArray::add(const int element)
{
    // try catch pour gerer les exceptions
    try
    {
        // creer un nouveau tableau avec une taille augmente de 1
        int *newTableau = new int[this->taille + 1];
        // copier les elements existants dans le nouveau tableau
        for (unsigned int i = 0; i < this->taille; i++)
        {
            newTableau[i] = this->tableau[i];
        }
        // ajouter le nouvel element a la fin
        newTableau[this->taille] = element;
        // liberer l'ancien tableau
        delete[] this->tableau;
        // mettre a jour le pointeur et la taille
        this->tableau = newTableau;
        this->taille++;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}
void MyArray::remove()
{
    // try catch pour gerer les exceptions
    try
    {
        if (this->taille == 0)
            return; // tableau vide, rien a supprimer

        // creer un nouveau tableau avec une taille diminuee de 1
        int *newTableau = new int[this->taille - 1];
        // copier les elements sauf le dernier dans le nouveau tableau
        for (unsigned int i = 0; i < this->taille - 1; i++)
        {
            newTableau[i] = this->tableau[i];
        }
        // liberer l'ancien tableau
        delete[] this->tableau;
        // mettre a jour le pointeur et la taille
        this->tableau = newTableau;
        this->taille--;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}
unsigned int MyArray::getSize() const
{
    return this->taille;
}
void MyArray::removeAll()
{
    delete[] this->tableau;
    this->tableau = nullptr;
    this->taille = 0;
}
int MyArray::find(const int element) const
{
    try
    {
        for (unsigned int i = 0; i < this->taille; i++)
        {
            if (this->tableau[i] == element)
            {
                return i; // element trouve, retourner l'index
            }
        }
        return -1; // element non trouve
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return -1; // en cas d'exception, retourner -1
    }
}
int MyArray::getAt(const int index) const
{
    try
    {
        if (index < 0 || static_cast<unsigned int>(index) >= this->taille)
        {
            cerr << "Index hors limites" << endl;
            return -1;
        }
        return this->tableau[index];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return -1;
    }
}

int *MyArray::begin() const
{
    return this->tableau; // retourner un pointeur vers le premier element
}
int *MyArray::back() const
{
    if (this->taille == 0)
        return nullptr;                        // tableau vide
    return &(this->tableau[this->taille - 1]); // retourner un pointeur vers le dernier element
}