#include "Node.h"

Node::Node(Point p)
{
    this->donnee = p;
    this->suivant = nullptr; // initialiser le pointeur suivant a null
}

Node::~Node()
{
}

void Node::setDonnee(Point p)
{
    this->donnee = p;
}

void Node::setSuivant(Node *n)
{
    this->suivant = n;
}

Point Node::getDonnee() const
{
    return this->donnee;
}

Node *Node::getSuivant() const
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
