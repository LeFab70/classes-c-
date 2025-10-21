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

void List::ajouterFin(const Point &p)
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

    // delete nouveauNode; // liberation de la memoire occupee par le nouveau node temporaire
    //  mise a jour de la quantite de nodes
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

void List::enleverFin()
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
        Node *actuel = getPremier();
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

void List::enleverDebut()
{
    if (getQuantiteNodes() == 0)
        return; // liste vide, rien a enlever

    Node *temporaire = getPremier();            // stocker le premier node
    this->premier = getPremier()->getSuivant(); // mettre a jour le premier node
    delete temporaire;                          // liberer la memoire occupee par l'ancien premier node
    this->qunatiteNodes--;                      // decrementer le compteur de nodes
}

void List::ajouterDebut(const Point &p)
{

    // verifier si la liste est vide
    if (getPremier() == nullptr)
    {
        // liste vide, creer un nouveau node et le definir comme premier
        Node *nouveauNode = new Node(p);
        this->premier = nouveauNode;
        this->qunatiteNodes++; // incrementer le compteur de nodes
        return;
    }

    // liste non vide
    // creer un nouveau node dynamique
    Node *nouveauNode = new Node(p);
    // lier le nouveau node au premier node actuel
    nouveauNode->setSuivant(getPremier());
    // mettre a jour le premier node de la liste
    this->premier = nouveauNode;
    this->qunatiteNodes++; // incrementer le compteur de nodes
}

void List::inverserListe()
{
    // Verifier si la liste est vide ou contient un seul node
    if (getQuantiteNodes() <= 1)
        return; // rien a inverser

    // Initialiser les pointeurs la liste n'est pas vide ou contient plus de un node
    Node *precedent = nullptr;
    Node *actuel = getPremier();
    Node *suivant = nullptr;
    while (actuel)
    {
        suivant = actuel->getSuivant(); // stocker le node suivant
        actuel->setSuivant(precedent);  // inverser le lien
        precedent = actuel;             // avancer precedent
        actuel = suivant;               // avancer actuel
    }
    this->premier = precedent; // mettre a jour le premier node
}
