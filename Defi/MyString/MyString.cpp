#include "MyString.h"

MyString::MyString(void)
	: buf(NULL), len(0)
{
	// buf = NULL;
	// len = 0;
}

MyString::MyString(const char *str)
{
	buf = NULL;
	setBuffer(str);
}

MyString::MyString(const char cara) // constructeur d'un caractere (Erreur)
{
	len = 1;

	// on reserve l'espace necessaire +1 pour le NULL
	try
	{
		buf = new char[len + 1];
	}
	catch (bad_alloc)
	{
		exit(-1);
	}

	buf[0] = cara;
	buf[1] = '\0';
	//cout << "Constructeur d'un caractere appele" << endl;
	//cout << "Adresse de l'objet: " << this << endl;
	//cout << "Caractere: " << cara << endl;
	//cout << "Adresse du buffer: " << (void *)buf << endl;
}

MyString::MyString(int longueur, char cara)
{
	len = longueur;

	// on reserve l'espace necessaire +1 pour le NULL
	try
	{
		buf = new char[len + 1];
	}
	catch (bad_alloc)
	{
		exit(-1);
	}

	// fill(buf,buf+len,cara);
	// buf[len] = NULL;

	for (int i = 0; i < len; i++)
		buf[i] = cara;

	buf[len] = '\0';
}

MyString::MyString(const MyString &original)
{
	this->buf = NULL;
	setBuffer(original.buf);
}

MyString::~MyString(void)
{
	delete[] buf;
}

int MyString::getLength() const
{
	return len;
}

char MyString::getChar(int index) const
{
	if (index >= 0 && index < len)
		return buf[index];
	else
		return '\0';
}

void MyString::afficher() const
{
	if (buf)
		cout << buf<< endl;
}

char *MyString::getBuffer() const
{
	return buf;
}

void MyString::setBuffer(const char *str)
{
	// supprimer avec delete l'ancienne chaine
	delete[] buf;
	// trouver la longueur de str
	len = strlen(str);

	try
	{
		buf = new char[len + 1];
	}
	catch (bad_alloc)
	{
		exit(-1);
	}

	// on copy la chaine str dans notre espace memoire
	strcpy(buf, str);
}

void MyString::append(const char *str)
{
	// trouver la longueur de la nouvelle chaine
	// len += strlen(str);
	len = strlen(buf) + strlen(str);

	// reserver l'espsace memoire
	char *temp;
	try
	{
		temp = new char[len + 1];
	}
	catch (bad_alloc)
	{
		exit(-1);
	}

	// copier les chaines dans le nouvelle emplacement
	strcpy(temp, buf);
	strcat(temp, str);

	// deleter la chaine originale
	delete[] buf;

	buf = temp;
}

// surcharge de setBuffer et append pour MyString
void MyString::setBuffer(const MyString &obj)
{
	char *str = obj.getBuffer(); // (Erreur)

	// supprimer avec delete l'ancienne chaine
	delete[] buf;
	// trouver la longueur de str
	len = strlen(str);

	try
	{
		buf = new char[len + 1];
	}
	catch (bad_alloc)
	{
		exit(-1);
	}

	// on copy la chaine str dans notre espace memoire
	strcpy(buf, str);
}

void MyString::append(const MyString &obj)
{
	char *str = obj.getBuffer(); // (Erreur)

	// trouver la longueur de la nouvelle chaine
	// len += strlen(str);
	len = strlen(buf) + strlen(str);

	// reserver l'espsace memoire
	char *temp;
	try
	{
		temp = new char[len + 1];
	}
	catch (bad_alloc)
	{
		exit(-1);
	}

	// copier les chaines dans le nouvelle emplacement
	strcpy(temp, buf);
	strcat(temp, str);

	// deleter la chaine originale
	delete[] buf;

	buf = temp;
}
