/**************************************************************************************************
*
*  Auteur : Ghislain Duguay
*  Date : Novembre
*
*  Description :
*
***********************************************************************************************************/

#include <iostream>
#include "MyString.h"
using namespace std;


/****************  Prototypes de fonctions *****************************/


/**************** Programme principal *******************************/
int main(void)
{
    //Problème #2
	MyString str1("Ghislain");
	MyString str2(" Duguay");  
	MyString str3;
	str1.append(str2); // (Erreur)
	str1.afficher();
	str3.setBuffer(str1); // (Erreur)
	str3.afficher();


	//Problème #3
	MyString str = 'g';
	str.afficher(); //affichera g


	return 0;
}