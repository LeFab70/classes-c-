/*****************************************************************
     Programmer: Fabrice Kouonang
     Fraction:       08/09/2025
     But:        gestion des fractions en poo en C++
     version:    1.0
******************************************************************/
#include <iostream>
#include "Fraction.h"
#include <iomanip>
using namespace std;
const unsigned short SIZE = 10;
/******************** Prototypes des fonctions ****************/
template <typename T>
int compare_Generique(const void *arg1, const void *arg2);

void afficherTableau(const Fraction *fractions, int size);
/******************** Programme principal ****************/
int main(void)
{
     // cout << endl
     //      << endl
     //      << "Programme de gestion des fractions en POO en C++"
     //      << endl
     //      << endl;
     // // Manipulations des objets dans un array
     // Fraction *fractions = new Fraction[5]; // tableau de pointeurs vers des objets Fractions
     // // le constructeur par defaut est appelé pour chaque objet du tableau soit 5 fois ici
     // for (int i = 0; i < 5; i++)
     // {
     //      fractions[i].setNum(1);
     //      fractions[i].setDen(i + 2);
     // }
     // cout << endl
     //      << "Valeurs rationnelles fractions:" << endl;

     // for (int i = 0; i < 5; i++)
     // {
     //      fractions[i].afficher();
     //      cout << " , ";
     // }
     // cout << endl
     //      << "Valeurs decimales des fractions:" << endl;
     // for (int i = 0; i < 5; i++)
     // {
     //      cout << (float)fractions[i].getNum() / fractions[i].getDen();
     //      cout << "--";
     // }

     // delete[] fractions; // liberation de la memoire allouée pour le tableau

     //      // Test ajouter avec parametres entiers
     //     Fraction  f1(1, 2);
     //      f1.ajouter(3, 4);
     //      f1.afficher(); // devrait afficher 10/8
     //      // Test ajouter avec un objet Fraction

     //      Fraction f2(1, 2);
     //      f2.ajouter(Fraction(3, 4));
     //      cout << endl;
     //      f2.afficher(); // devrait afficher 10/8
     //      // test addition de deux fractions
     //      Fraction f3(1, 2);
     //      Fraction f4(3, 4);
     //      cout << endl;
     //      Fraction f5 = f3.additionner(f4);
     //      f5.afficher(); // devrait afficher 10/8
     //      cout << endl;
     //      f5 = f3.soustraire(f4);
     //      f5.afficher(); // devrait afficher -2/8
     //      cout << endl;
     //      f5 = f3.multiplier(f4);
     //      f5.afficher(); // devrait afficher 3/8
     //      cout << endl;
     //      f5 = f3.diviser(f4);
     //      f5.afficher(); // devrait afficher 4/6
     //      cout << endl
     //           << "Simplification: " << endl;
     //      // f5 = f5.simplifier();
     //      f5.afficher(); // devrait afficher 2/3
     //      cout << endl;
     //      f5 = f3.inverser();
     //      cout << "Inverse: " << endl;
     //      f5.afficher(); // devrait afficher 2/1

     //      // ccreation objet constant
     //      const Fraction f6(5, 10);
     //      cout << endl
     //           << "Objet constant: " << endl;
     //      f6.afficher(); // devrait afficher 5/10
     //      f6.getNum();   // ok
     //      f6.getDen(); // ok
     // f6.setNum(3); // erreur car objet constant
     // f6.setDen(4); // erreur car objet constant
     // f6.ajouter(1,2); // erreur car objet constant
     // f6.ajouter(Fraction(1,2)); // erreur car objet constant
     // f5 = f6.simplifierAlteree(); // erreur car objet constant
       
      //definiton du cind pour le random
     srandom(time(NULL)); 
     Fraction *fractions = new Fraction[SIZE - 1]; // tableau de pointeurs vers des objets Fractions
    //un tablkeau va par defaut faire appel au constructeur par defaut pour chaque objet du tableau soit SIZE fois ici
     for (int i = 0; i < SIZE; i++)
     {
          fractions[i].setNum(random() % 10 + 1);
          fractions[i].setDen(random() % 10 + 1);
     }

     cout << "****************Tableau non trie ******************" << endl;
     afficherTableau(fractions, SIZE);

     delete[] fractions; // liberation de la memoire allouée pour le tableau
     // trier le tableau de fractions
     cout << endl
          << "****************Tableau trie ******************" << endl;
     qsort(fractions, SIZE, sizeof(fractions[0]), compare_Generique<const Fraction *>);
     afficherTableau(fractions, SIZE);
     
     //En c++ il existe 4 methodes codées pour nous
     // 1. le constructeur par defaut
     // 2. le constructeur de copie
     // 3. l'operateur d'affectation =
     // 4. le destructeur
 // le constructeur par copie permet de créer un nouvel objet en copiant un objet existant passé en paramètre
     Fraction f1(1, 2);
     Fraction f2 = f1; // appel du constructeur de copie
     //ou
     Fraction f2(f1); // appel du constructeur de copie
     Fraction f3;     // appel du constructeur par defaut
     f3 = f1;         // appel de l'operateur d'affectation =

     
     cout << endl
          << endl
          << "Fermeture du programme, \n pressez surla touche entrée,pour quitter le programme"
          << endl
          << endl;
     return 0;
}
/******************** Definitions des fonctions ****************/
template <typename T>
int compare_Generique(const void *arg1, const void *arg2)
{
     // // comparer deux objets de type T
     // if (*(T *)arg1 < *(T *)arg2)
     //      return -1;
     // if (*(T *)arg1 > *(T *)arg2)
     //      return 1;
     // return 0;

     // application aux fractions
     const Fraction *f1 = (const Fraction *)arg1;
     const Fraction *f2 = (const Fraction *)arg2;
     // if
     //      typeof(T) == Fraction
     //      {

               float val1 = (float)f1->getNum() / f1->getDen();
               float val2 = (float)f2->getNum() / f2->getDen();
               if (val1 < val2)
                    return -1;
               if (val1 > val2)
                    return 1;
               return 0;
        //  }
}
/*   ****************************
 * le cycle de vie d'un objet comprend:
 * *********************************** */
// 1. allocation memoire / creation objet
// 2. initialisation objet (constructeur)
// 3. utilisation objet
// 4. destruction objet (destructeur)
// 5. liberation memoire (destructeur si objet dynamique)

// Remarque: un objet statique est detruit automatiquement a la fin du bloc dans lequel il est defini
// un objet dynamique doit etre detruit explicitement avec l'operateur delete
// un objet statique est alloué sur la pile (stack)
// un objet dynamique est alloué sur le tas (heap)
// utiliser new pour creer un objet dynamique
// un parametre ou une variable locale est alloué sur la pile (stack) il utilise la memoire automatiquement, avec appel constructeur et  au destructeur a la fin du bloc
// utiliser le parametre en tant que reference pour eviter la copie de l'objet
// const Class& param pour eviter la modification de l'objet
// mais plus access aux getters et setters, alors on peut
// un objet constant ne peut acceder qu'aux methodes constantes (getters) ou affichage ou qui modifier pas objets
// un objet non constant peut acceder a toutes les methodes

void afficherTableau(const Fraction *fractions, int size)
{
     for (int i = 0; i < size; i++)
     {
          fractions[i].afficher();
          cout << " ---->";
          fractions[i].afficherDecimal();
          cout << endl;
     }
}
