#pragma once // eviter inclusion /appel multiple
#include <iostream>
#include <cstring>
using namespace std;
class Fraction
{
private:
    int num; // numerateur
    int den; // denominateur
    int euclide(int, int);

public:
    // constructeur par defaut
    Fraction();
    // constructeurs surcharge
    // sil est defini il remplace celui par defaut, donc faut redefini celui par defaut si des objet avec constructeur par defaut
    Fraction(int, int);

    // destructeur il ya un seul ou celui par defaut quand objet est static
    ~Fraction();
    void setNum(int);
    void setDen(int);
    int getNum(void) const;
    int getDen(void) const;
    void afficher(void) const;
    void ajouter(int, int);
    void ajouter(const Fraction &);
    Fraction additionner(const Fraction &) const;

    Fraction soustraire(const Fraction &) const;
    Fraction multiplier(const Fraction &) const;
    Fraction diviser(const Fraction &) const;
    Fraction inverser(void) const;
    void inverserSwap(void);
    void afficherDecimal(void) const;
    // Fraction simplifier(void) const;
    void simplifierAlteree(void);
};