/*****************************************************************
	Programmer: Fabrice Kouonang
	 Date:       10/11/2025
	 But:        Test2 - classe LocalCCNB
	 version:    1.0
******************************************************************/

#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

class LocalCCNB
{
private:
	char numLocal[4];
	int nbreOccupants;
	bool accesProjecteur;
	static int nbInstances;
	// Contraintes privées
	static const int NBRE_OCCUPANTS_MIN;
	static const int NBRE_OCCUPANTS_MAX;
	static const char DEFAULT_NUM_LOCAL[4];
	static const char ERROR_NUM_LOCAL[4];

public:
	// Getters des proprietés
	char *getNumLocal() const;
	int getNbreOccupants() const;
	bool getAccesProjecteur() const;

	// constructeurs
	LocalCCNB();
	LocalCCNB(const char *pNumLocal, const int pNbreOccupants, const bool pAccesProjecteur);
	// constructeur par copie de surface
	LocalCCNB(const LocalCCNB &local);
	// destructeur
	~LocalCCNB();

	void setLocal(const char *pNumLocal, const int pNbreOccupants, const bool pAccesProjecteur);
	void changerAccProj();
	void setNbreOccupants(const int pNbreOccupants);
	void setNumLocal(const char *pNumLocal);
	static void showCount();
};
