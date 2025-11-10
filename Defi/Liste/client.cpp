/**************************************************************************************************
*
*  Auteur : Ghislain Duguay
*  Date : Novembre
*
*  Description :
*
***********************************************************************************************************/

#include <iostream>
#include "Liste.h"
#include <list>
using namespace std;


/****************  Prototypes de fonctions *****************************/


/**************** Programme principal *******************************/
int main(void)
{
	//Probl�me #1
	Liste liste1;
	liste1.ajouterFin(Point(1,1));
	liste1.ajouterFin(Point(2,2));
	liste1.afficher();
	Liste liste2 = liste1;
	liste2.afficher();	

	return 0;
}