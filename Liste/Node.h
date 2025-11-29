#pragma once // eviter inclusion /appel multiple
#include <iostream>
#include <cstring>

using namespace std;
template <class T>
class Node
{
private:
    T donnee;
    Node<T> *suivant;

public:
    Node(T p); // constructeur
    ~Node();       // destructeur
    void setDonnee(const T& p);
    void setSuivant(Node<T> *n);
    T getDonnee() const;
    Node *getSuivant() const;
};



template <class T>
Node<T>::Node(T p)
{
    this->donnee = p;
    this->suivant = nullptr; // initialiser le pointeur suivant a null
}

template <class T>
Node<T>::~Node()
{
}

template <class T>
void Node<T>::setDonnee(const T& p)
{
    this->donnee = p;
}

template <class T>
void Node<T>::setSuivant(Node<T> *n)
{
    this->suivant = n;
}

template <class T>
T Node<T>::getDonnee() const
{
    return this->donnee;
}

template <class T>
Node<T>* Node<T>::getSuivant() const
{
    //recuperer l'adresse du noeud suivant
    // si le noeud suivant est null on retourne null
    // sinon on retourne l'adresse du noeud suivant
    //on la recupere avec this->suivant
    if (this->suivant != nullptr)
    {
        return this->suivant;
    }
    return nullptr;
}