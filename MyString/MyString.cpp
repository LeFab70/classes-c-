#include "MyString.h"

// utilisation de la liste d'initialisation sur le constructeur par defaut

MyString::MyString() : buf(new char[1]{'\0'}), len(0)
{
    // this->buf = new char[1]; // allouer de la memoire pour une chaine vide
    // this->buf[0] = '\0';     // initialiser la chaine vide
    // this->len = 0;           // longueur initiale est 0
}
MyString::MyString(const char *str)
{
    // setters
    setBuffer(str);
    // if (str == nullptr)
    // {
    //     MyString(); // appeler le constructeur par defaut si str est null
    // }
    // else
    // {
    //     // pourquoi strcpy_s ne fonctionne pas ici?
    //     // strcpy_s(this->buf, strlen(str) + 1, str); // copier la chaine dans le buffer
    //     this->len = strlen(str);             // obtenir la longueur de la chaine
    //     this->buf = new char[this->len + 1]; // allouer de la memoire pour la chaine
    //     strcpy(this->buf, str);              // copier la chaine dans le buffer
    // }
}
MyString::MyString(int nbreCaractere, const char str)
{
    // if (str == nullptr)
    // {
    //     MyString(); // appeler le constructeur par defaut si str est null
    // }
    // else
    //{
    this->len = nbreCaractere;           // definir la longueur de la chaine
    this->buf = new char[this->len + 1]; // allouer de la memoire pour la chaine
    for (int i = 0; i < this->len; i++)
    {
        this->buf[i] = str; // remplir la chaine avec le caractere donne
    }
    this->buf[this->len] = '\0'; // ajouter le caractere de fin de chaine
                                 // }
}

// constructeur de copie
MyString::MyString(const MyString &original)
{
    // appel de setBuffer pour eviter la duplication de code
    setBuffer(original.buf);
}

MyString::~MyString()
{
    // on fait delete[] car buf est un tableau dynamique
    delete[] this->buf; // liberer la memoire allouee pour la chaine
}
int MyString::getLength() const
{
    return this->len; // retourner la longueur de la chaine
}
char MyString::getChar(int position) const
{
    if (position < 0 || position >= this->len)
    {
        cout << ("Position hors limites"); // lancer une exception si la position est invalide
        return '\0';
    }
    return this->buf[position]; // retourner le caractere a la position donnee
}
void MyString::afficher() const
{
    if (buf)
        cout << this->buf << endl; // afficher la chaine de caracteres
}

const char *MyString::getBuffer() const
{
    return this->buf; // retourner le buffer de la chaine
}

void MyString::setBuffer(const char *str)
{
    delete[] this->buf; // liberer l'ancien buffer

    try
    {
        if (str == nullptr)
        {
            MyString(); // appeler le constructeur par defaut si str est null
        }
        else
        {
            this->len = strlen(str);             // obtenir la longueur de la chaine
            this->buf = new char[this->len + 1]; // allouer de la memoire pour la nouvelle chaine
                                                 // strcpy(this->buf, str);              // copier la nouvelle chaine dans le buffer
            // copie securisée
            // strcpy_s(this->buf, this->len + 1, str);
            strncpy(this->buf, str, this->len - 1);
            this->buf[this->len] = '\0'; // assurer la terminaison de la chaine
        }
    }
    catch (bad_alloc &e)
    {
        cerr << "Erreur d'allocation de memoire: " << e.what() << '\n';
        this->buf = new char[1]{'\0'}; // reinitialiser a une chaine vide en cas d'erreur
        this->len = 0;
        exit(EXIT_FAILURE);
    }
    catch (exception &e)
    {
        cerr << e.what() << '\n';
        exit(EXIT_FAILURE);
    }
}
//redefinition de l'operateur d'affectation
MyString &MyString::operator=(const MyString &other)
{
    setBuffer(other.buf);
    return *this; // retourner une reference vers l'objet courant
}
