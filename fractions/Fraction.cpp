#include "Fraction.h"

Fraction::Fraction()
{
    this->num = 0;
    this->den = 1; // denominateur par defaut a 1 pour eviter division par 0
}

// constructeur surchargé
Fraction::Fraction(int num, int den)
{
    setNum(num);
    setDen(den);
}

Fraction::~Fraction()
{
    // vide
    // cout << endl << "Destructeur de l'objet Fraction appelé pour " << this->num <<"/"<<this->den<< endl;
}

void Fraction::setDen(int den)
{
    if (den == 0)
    {
        cout << "Erreur: le denominateur ne peut pas etre 0, il est mis a 1 par defaut." << endl;
        this->den = 1;
        return;
    }
    this->den = den;
}
void Fraction::setNum(int num)
{
    this->num = num;
}

int Fraction::getNum(void) const
{
    return this->num;
}
int Fraction::getDen(void) const
{
    return this->den;
}

void Fraction::afficher(void) const
{
    // cout<<"----------------------------"<<endl;
    cout << this->getNum()
         << "/" << this->getDen();
}

void Fraction::ajouter(int num, int den)
{
    if (den == 0)
    {
        cout << "Erreur: le denominateur ne peut pas etre 0, l'operation est annulee." << endl;
        return;
    }
    this->num = this->num * den + num * this->den;
    this->den = this->den * den;
}

void Fraction::ajouter(const Fraction &f)
{
    this->num = this->num * f.den + f.getNum() * this->den;
    this->den = this->den * f.getDen();
}

Fraction Fraction::additionner(const Fraction &f) const
{
    if (f.getDen() == this->den)
    {
        int num = this->num + f.getNum();
        int den = this->den;
        return Fraction(num, den);
    }
    int num = this->num * f.getDen() + f.getNum() * this->den;
    int den = this->den * f.getDen();
    return Fraction(num, den);
}

Fraction Fraction::soustraire(const Fraction &f) const
{
    if (f.getDen() == this->den)
    {
        int num = this->num - f.getNum();
        int den = this->den;
        return Fraction(num, den);
    }
    int num = this->num * f.getDen() - f.getNum() * this->den;
    int den = this->den * f.getDen();
    return Fraction(num, den);
}

Fraction Fraction::multiplier(const Fraction &f) const
{
    int num = this->num * f.getNum();
    int den = this->den * f.getDen();
    return Fraction(num, den);
}

Fraction Fraction::diviser(const Fraction &f) const
{
    int num = this->num * f.getDen();
    int den = this->den * f.getNum();
    return Fraction(num, den);
}

Fraction Fraction::inverser(void) const
{
    if (this->num != 0)
        return Fraction(this->den, this->num);

    // cout << "Erreur: impossible d'inverser une Fraction avec un numerateur nul." << endl;
    return Fraction(0, 1); // retourne une Fraction nulle
}

void Fraction::inverserSwap(void)
{
    if (this->num != 0)
        swap(this->num, this->den);
    // else
    // cout << "Erreur: impossible d'inverser une Fraction avec un numerateur nul." << endl;
}

void Fraction::afficherDecimal(void) const
{
    cout << (float)this->num / this->den;
}

int Fraction::euclide(int a, int b)
{
    if (b == 0)
        return a;
    return euclide(b, a % b);
}

// Fraction Fraction::simplifier(void) const
// {
//     if (this->num == 0)
//         return Fraction(0, 1); //la Fraction est nulle

//     Fraction FractionSimplifiee;
//     int pgcd = euclide(abs(this->num), abs(this->den));
//     FractionSimplifiee.setNum(this->num/pgcd);
//     FractionSimplifiee.setDen(this->den/pgcd);
//     return FractionSimplifiee;
// }

// alteree l'objet courant avec simplification
void Fraction::simplifierAlteree(void)
{
    int pgcd = euclide(abs(this->num), abs(this->den));
    this->setNum(this->num / pgcd);
    this->setDen(this->den / pgcd);
}