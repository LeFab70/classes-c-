/*****************************************************************
	Programmer: Fabrice Kouonang
	 Date:       10/11/2025
	 But:        Test2 - classe LocalCCNB
	 version:    1.0
******************************************************************/

#include "LocalCCNB.h"

// Initialisation des constantes statiques
const int LocalCCNB::NBRE_OCCUPANTS_MIN = 4;
const int LocalCCNB::NBRE_OCCUPANTS_MAX = 42;
const char LocalCCNB::DEFAULT_NUM_LOCAL[4] = "N/A";
const char LocalCCNB::ERROR_NUM_LOCAL[4] = "ERR";
int LocalCCNB::nbInstances = 0;
// Getters des proprietés
char *LocalCCNB::getNumLocal() const
{
	return const_cast<char *>(numLocal);
}
int LocalCCNB::getNbreOccupants() const
{
	return this->nbreOccupants;
}

bool LocalCCNB::getAccesProjecteur() const
{
	return this->accesProjecteur;
}
// constructeurs
LocalCCNB::LocalCCNB() : numLocal("N/A"), nbreOccupants(0), accesProjecteur(false)
{
	nbInstances++;
}

LocalCCNB::LocalCCNB(const char *pNumLocal, const int pNbreOccupants, const bool pAccesProjecteur)
{
	setLocal(pNumLocal, pNbreOccupants, pAccesProjecteur);
	nbInstances++;
}

// constructeur par copie de surface
LocalCCNB::LocalCCNB(const LocalCCNB &local)
{
	try
	{
		strncpy(numLocal, local.numLocal, sizeof(numLocal));
		nbreOccupants = local.nbreOccupants;
		accesProjecteur = local.accesProjecteur;
		nbInstances++;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}

// destructeur
LocalCCNB::~LocalCCNB()
{
	nbInstances--;
}

// Méthodes de modification des proprietés
void LocalCCNB::setLocal(const char *pNumLocal, const int pNbreOccupants, const bool pAccesProjecteur)
{
	setNumLocal(pNumLocal);
	setNbreOccupants(pNbreOccupants);
	accesProjecteur = pAccesProjecteur;
}

void LocalCCNB::changerAccProj()
{
	accesProjecteur = !accesProjecteur;
}

void LocalCCNB::setNbreOccupants(const int pNbreOccupants)
{
	if (pNbreOccupants >= NBRE_OCCUPANTS_MIN && pNbreOccupants <= NBRE_OCCUPANTS_MAX)
	{
		nbreOccupants = pNbreOccupants;
	}
	else
	{
		nbreOccupants = NBRE_OCCUPANTS_MIN; // valeur par défaut en cas d'erreur
	}
}

void LocalCCNB::setNumLocal(const char *pNumLocal)
{ // le local doit avoir un numéro de 4 caractères donc un p ou n et 3 chiffres
	if (strlen(pNumLocal) == 4 && (pNumLocal[0] == 'P' || pNumLocal[0] == 'N') &&
		isdigit(pNumLocal[1]) && isdigit(pNumLocal[2]) && isdigit(pNumLocal[3]))
	{
		strncpy(numLocal, pNumLocal, sizeof(numLocal));
	}
	else
	{
		strncpy(numLocal, ERROR_NUM_LOCAL, sizeof(numLocal)); // valeur d'erreur
	}
}

void LocalCCNB::showCount()
{
	cout << "Nombre d'instances de LocalCCNB: " << nbInstances << endl;
}
