#pragma once // eviter inclusion /appel multiple
#include <iostream>
#include <cstring>

#include "Node.h"
using namespace std;
template <class T>
class List
{
private:
    Node<T> *premier;
    int qunatiteNodes;

public:
    List();
    ~List();
    Node<T> *getPremier() const;
    int getQuantiteNodes() const;
    void ajouterFin(const T &p);
    void afficher() const;
    void enleverFin();
    void enleverDebut();
    void ajouterDebut(const T &p);
    void inverserListe();
    void viderListe();
};



template <class T>
List<T>::List()
{
    this->premier = nullptr;
    this->qunatiteNodes = 0;
}

template <class T>
List<T>::~List()
{
    // liberation de la memoire occupee par les nodes
    viderListe();
}

template <class T>
Node<T> *List<T>::getPremier() const
{
    return this->premier;
}

template <class T>
int List<T>::getQuantiteNodes() const
{
    return this->qunatiteNodes;
}

template <class T>
void List<T>::ajouterFin(const T &p)
{
    // creer un nouveau node dynamique
    Node<T> *nouveauNode = new Node<T>(p);

    // mise a jour de la liste en ajoutant un node a la fin, on parcourt la liste
    if (this->premier == nullptr)
    {
        // liste vide, le nouveau node devient le premier
        this->premier = nouveauNode;
    }
    else
    {
        // liste non vide, parcourir jusqu'au dernier node
        Node<T> *actuel = getPremier();
        while (actuel->getSuivant())
        {
            actuel = actuel->getSuivant();
        }
        // lier le dernier node au nouveau node
        actuel->setSuivant(nouveauNode);
    }

    // delete nouveauNode; // liberation de la memoire occupee par le nouveau node temporaire
    //  mise a jour de la quantite de nodes
    this->qunatiteNodes++; // incrementer le compteur de nodes
}

template <class T>
void List<T>::afficher() const
{
    // cas liste vide
    if (getPremier() == nullptr)
    {
        cout << "La liste est vide." << endl;
        return;
    }

    Node<T> *actuel = getPremier(); // commencer par la tete de la liste
    while (actuel)
    {
        actuel->getDonnee().afficher(); // afficher le point du node actuel
        actuel = actuel->getSuivant();  // passer au node suivant
    }
}

template <class T>
void List<T>::enleverFin()
{
    if (getQuantiteNodes() == 0)
        return; // liste vide, rien a enlever

    if (getQuantiteNodes() == 1)
    {
        // un seul node dans la liste
        delete getPremier();     // liberer la memoire occupee par le seul node
        this->premier = nullptr; // mettre a jour le premier node
    }
    else
    {
        // plus d'un node dans la liste, parcourir jusqu'au deuxieme dernier node
        Node<T> *actuel = getPremier();
        while (actuel->getSuivant()->getSuivant()) // ici on arrete au deuxieme dernier node, getSuivant()->getSuivant() verifie si le suivant du suivant est null
        {
            actuel = actuel->getSuivant(); // avancer au node suivant
        }
        // supprimer le dernier node
        delete actuel->getSuivant(); // liberer la memoire occupee par le dernier node
        actuel->setSuivant(nullptr); // mettre a jour le deuxieme dernier node
    }
    this->qunatiteNodes--; // decrementer le compteur de nodes
}

template <class T>
void List<T>::enleverDebut()
{
    if (getQuantiteNodes() == 0)
        return; // liste vide, rien a enlever

    Node<T> *temporaire = getPremier();            // stocker le premier node
    this->premier = getPremier()->getSuivant(); // mettre a jour le premier node
    delete temporaire;                          // liberer la memoire occupee par l'ancien premier node
    this->qunatiteNodes--;                      // decrementer le compteur de nodes
}

template <class T>
void List<T>::ajouterDebut(const T &p)
{

    // verifier si la liste est vide
    if (getPremier() == nullptr)
    {
        // liste vide, creer un nouveau node et le definir comme premier
        Node<T> *nouveauNode = new Node<T>(p);
        this->premier = nouveauNode;
        this->qunatiteNodes++; // incrementer le compteur de nodes
        return;
    }

    // liste non vide
    // creer un nouveau node dynamique
    Node<T> *nouveauNode = new Node<T>(p);
    // lier le nouveau node au premier node actuel
    nouveauNode->setSuivant(getPremier());
    // mettre a jour le premier node de la liste
    this->premier = nouveauNode;
    this->qunatiteNodes++; // incrementer le compteur de nodes
}

template <class T>
void List<T>::inverserListe()
{
    // Verifier si la liste est vide ou contient un seul node
    if (getQuantiteNodes() <= 1)
        return; // rien a inverser

    // Initialiser les pointeurs la liste n'est pas vide ou contient plus de un node
    Node<T> *precedent = nullptr;
    Node<T> *actuel = getPremier();
    Node<T> *suivant = nullptr;
    while (actuel)
    {
        suivant = actuel->getSuivant(); // stocker le node suivant
        actuel->setSuivant(precedent);  // inverser le lien
        precedent = actuel;             // avancer precedent
        actuel = suivant;               // avancer actuel
    }
    this->premier = precedent; // mettre a jour le premier node
}

template <class T>
void List<T>::viderListe()
{
    Node<T> *actuel = this->premier;
    Node<T> *temporaire;
    while (actuel != nullptr)
    {
        enleverDebut(); // reutiliser la methode enleverDebut pour liberer chaque node
        // temporaire = actuel;
        // actuel = actuel->getSuivant();
        // delete temporaire;     // appel du destructeur de Node
        // this->qunatiteNodes--; //? est utile?
    }
}
