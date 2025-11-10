#include "Fraction.h"


//Fraction::Fraction(void)
//{
//	this->numerateur = 1;
//	this->denominateur = 1;
//	//setDenominateur(1);
//	//setNumerateur(1);
//
//	cout << "Constructeur de " << this << endl;
//}

Fraction::Fraction(int num, int deno)
{
	setNumerateur(num);
	denominateur = 1; //initialiser au cas que deno serait = 0
	setDenominateur(deno);
	//cout << "Constructeur de " << this << endl;
}

Fraction::Fraction(const Fraction& original)
{
	this->numerateur = original.numerateur;
	this->denominateur = original.denominateur;
	//cout << "Constructeur copie de " << this << " --> " << &original << endl;
}


Fraction::~Fraction(void)
{
	//cout << "Destructeur de " << this << endl;
}


int Fraction::getNumerateur() const
{
	return numerateur;
}

int Fraction::getDenominateur() const
{
	return denominateur;
}


void Fraction::setNumerateur(int numerateur) 
{
	
	this->numerateur = numerateur;
}

void Fraction::setDenominateur(int deno)
{
	if(deno != 0)
		denominateur = deno;

}


void Fraction::afficher() const
{
	cout << numerateur << "/" << denominateur;
}

double Fraction::retournerDecimale() const
{
	return (double)numerateur/denominateur;
}


Fraction& Fraction::ajouter(const Fraction& f)
{
	Fraction resultat;

	this->numerateur = this->numerateur * f.denominateur + this->denominateur * f.numerateur;

	this->denominateur = this->denominateur * f.denominateur;
	
	resultat = *this;

	return *this;
}

Fraction Fraction::additionner(const Fraction& f, const Fraction& f2) // (Erreur)
{
	Fraction resultat;
	resultat.numerateur = f2.numerateur * f.denominateur +
					f.numerateur * f2.denominateur;

	//faire le denominateur en dernier....
	resultat.denominateur= f2.denominateur * f.denominateur;

	return resultat;

	//prendre avantage de la methode ajouter
	/*Fraction temp = f;
	temp.ajouter(f2);
	return temp;*/
}


Fraction Fraction::soustraire(const Fraction& f)  const
{
	Fraction resultat;

	
	resultat.setNumerateur(f.denominateur * this->numerateur -
							this->denominateur * f.numerateur);

	resultat.setDenominateur(this->denominateur * f.denominateur);

	return resultat;
}
Fraction Fraction::diviser(const Fraction& f) const
{
	Fraction resultat = f;
	resultat.inverser();
	return this->multiplier(resultat);

}
Fraction Fraction::multiplier(const Fraction& f) const
{
	

	return Fraction(this->numerateur * f.numerateur,
					this->denominateur * f.denominateur);
	
}

void Fraction::inverser()
{
	if(this->numerateur) //assure que le numerateur n'est pas 0
		swap(this->numerateur,this->denominateur);
}