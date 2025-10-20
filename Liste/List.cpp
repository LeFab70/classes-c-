#include "List.h"

List::List()
{
    this->premier = nullptr;
    this->qunatiteNodes = 0;
}

List::~List()
{
    // liberation de la memoire occupee par les nodes
    Node *actuel = this->premier;
    Node *temporaire;
    while (actuel != nullptr)
    {
        temporaire = actuel;
        actuel = actuel->getSuivant();
        delete temporaire; // appel du destructeur de Node
    }
}

Node *List::getPremier() const
{
    return this->premier;
}

int List::getQuantiteNodes() const
{
    return this->qunatiteNodes;
}

void List::ajouterFin(Point p)
{
    // creer un nouveau node dynamique
    Node *nouveauNode = new Node(p);

    // mise a jour de la liste en ajoutant un node a la fin, on parcourt la liste
    if (this->premier == nullptr)
    {
        // liste vide, le nouveau node devient le premier
        this->premier = nouveauNode;
    }
    else
    {
        // liste non vide, parcourir jusqu'au dernier node
        Node *actuel = getPremier();
        while (actuel->getSuivant())
        {
            actuel = actuel->getSuivant();
        }
        // lier le dernier node au nouveau node
        actuel->setSuivant(nouveauNode);
    }

    //delete nouveauNode; // liberation de la memoire occupee par le nouveau node temporaire
    // mise a jour de la quantite de nodes
    this->qunatiteNodes++; // incrementer le compteur de nodes
}

void List::afficher() const
{
    // cas liste vide
    if (getPremier() == nullptr)
    {
        cout << "La liste est vide." << endl;
        return;
    }

    Node *actuel = getPremier(); // commencer par la tete de la liste
    while (actuel)
    {
        actuel->getDonnee().afficher(); // afficher le point du node actuel
        actuel = actuel->getSuivant();  // passer au node suivant
    }
}
