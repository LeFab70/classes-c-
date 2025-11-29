/*****************************************************************
      Programmer: Fabrice Kouonang
     Date:       29/09/2025
     But:        Test1 - Classe coin
     version:    1.0
    Testing de la classe coin
******************************************************************/
#include <iostream>
#include "Coin.h"
#include <ctime>
#include <chrono>
#include <cstdlib>
#include <string>
using namespace std;
/******************** Prototypes des fonctions ****************/
const int NOMBRE_LANCERS = 100000;
/******************** Programme principal ****************/

int getSeconde();
long long getMilliSeconde();
int main(void)
{
     int heads = 0;
     int tails = 0;
     // int nombreSecondes = 0;
     // int startSecondes = 0;
     // int endSecondes = 0;
     int headsOne = 0;
     int headsTwo = 0;
     string winner = "";

     long long nombreSecondes = 0;
     long long startSecondes = 0;
     long long endSecondes = 0;
     cout << endl
          << endl
          << "Random C++"
          << endl
          << endl;

     startSecondes = getMilliSeconde();
     Coin *c = new Coin();
     for (int i = 1; i < NOMBRE_LANCERS; i++)
     {
          c->flip();
          c->isHeads() ? heads++ : tails++;
     }
     endSecondes = getMilliSeconde(); // getSeconde();
     nombreSecondes = endSecondes - startSecondes;
     cout << "Apres " << NOMBRE_LANCERS << " flips " << endl
          << "Heads : " << heads << endl
          << "Tails : " << tails << endl
          << "Difference: " << abs(heads - tails) << endl
          << "En " << nombreSecondes / 1000.0 << " seconde(s)" << endl;
     ;

     // Testing avec random mersenne twister
     startSecondes = getMilliSeconde(); // getSeconde();
     Coin *coinTwister = new Coin();
     heads = 0;
     tails = 0;
     for (int i = 1; i < NOMBRE_LANCERS; i++)
     {
          coinTwister->flipMt();
          coinTwister->isHeads() ? heads++ : tails++;
     }
     endSecondes = getMilliSeconde(); // getSeconde();

     nombreSecondes = endSecondes - startSecondes;
     cout << endl
          << endl
          << "Random Mersenne Twister" << endl
          << "Apres " << NOMBRE_LANCERS << " flips " << endl
          << "Heads : " << heads << endl
          << "Tails : " << tails << endl
          << "Difference: " << abs(heads - tails) << endl
          << "En " << nombreSecondes / 1000.0 << " seconde(s)" << endl;
     ;

     // Lancer des cents et test du premier a avoir 3 heads de suite
     heads = 0;
     tails = 0;
     int nombreLancers = 0;
     bool stop = false;
     cout << endl
          << endl
          << "Lancer des cents et test du premier a avoir 3 heads de suite" << endl
          << endl;
     Coin *cent1 = new Coin();
     Coin *cent2 = new Coin();
     do
     {
           //cent1->flipMt();
          //cent2->flipMt();

          cent1++;
          ++cent2;
          // cout << " Cent1 : ";
          // cent1->afficher();
          // cout << "\t\t Cent2 : ";
          // cent2->afficher();
          // cout << endl;

          // simplifié par out
          cout << "cent1: " << *cent1 << "\t cent2: " << *cent2 << endl;

          cent1->isHeads() ? headsOne++ : headsOne = 0;
          cent2->isHeads() ? headsTwo++ : headsTwo = 0;
          // verifier si l'un des deux a fait 3 heads de suite
          if (headsOne == 3 || headsTwo == 3)
          {
               stop = true;
          }
          nombreLancers++;
     } while (stop == false && nombreLancers < 10000);

     if (headsOne == 3 && headsTwo == 3)
     {
          winner = "Egalite";
     }
     else if (headsOne == 3)
     {
          winner = "Cent1 a gagne";
     }
     else if (headsTwo == 3)
     {
          winner = "Cent2 a gagne";
     }
     else
     {
          winner = "Aucun n'a gagne";
     }
     cout << endl
          << winner << " apres " << nombreLancers + 1 << " lancers" << endl;
     // liberation de la memoire
     delete cent1;
     delete cent2;
     delete coinTwister;
     delete c;
     cout << endl
          << "--------------------------------------------"
          << endl
          << endl
          << "Fermeture du programme, \n pressez surla touche entrée,pour quitter le programme"
          << endl
          << endl;
     return 0;
}

int getSeconde()
{

     return static_cast<int>(time(0));
}

long long getMilliSeconde()
{
     using namespace std::chrono;
     static auto start = high_resolution_clock::now(); // point de départ fixe
     auto now = high_resolution_clock::now();
     auto diff = duration_cast<milliseconds>(now - start).count(); // ⚠️ millisecondes
     return diff;
}
