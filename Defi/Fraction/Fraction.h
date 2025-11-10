#pragma once
#include <iostream>
using namespace std;

class Fraction
{
private:
	int numerateur;
	int denominateur;

public:
	// Constructeurs et Destructeur
	// Fraction(void);
	Fraction(int = 1, int = 1);
	Fraction(const Fraction &);
	~Fraction(void);

	// getters and setters
	int getNumerateur() const;
	int getDenominateur() const;
	void setNumerateur(int);
	void setDenominateur(int);

	void afficher() const;
	double retournerDecimale() const;
	// void ajouter(const Fraction&);
	Fraction& ajouter(const Fraction &);
	// methodes de la classe avec static, retourne une reference
	static Fraction additionner(const Fraction &, const Fraction &); // (Erreur)
	Fraction soustraire(const Fraction &) const;
	Fraction multiplier(const Fraction &) const;
	Fraction diviser(const Fraction &) const;

	void inverser();
};