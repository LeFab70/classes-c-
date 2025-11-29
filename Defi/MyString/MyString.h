#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

class MyString
{

	// Friend functions pour comparer deux objets MyString
	friend bool operator==(const MyString &gauche, const MyString &droite);
	friend bool operator!=(const MyString &gauche, const MyString &droite);
	friend bool operator<(const MyString &gauche, const MyString &droite);
	friend bool operator<=(const MyString &gauche, const MyString &droite);
	friend bool operator>(const MyString &gauche, const MyString &droite);
	friend bool operator>=(const MyString &gauche, const MyString &droite);
	friend MyString operator+(const MyString &gauche, const MyString &droite);
	friend ostream &operator<<(ostream &out, const MyString &obj);
	friend istream &operator>>(istream &in, MyString &obj);
	// friend MyString &operator+=(MyString &gauche, const MyString &droite);

private:
	char *buf;
	int len;

public:
	MyString(void);
	MyString(const char *);
	// ajout du constructeur avec un caractere
	MyString(const char);
	// ajout du constructeur avec int et char
	explicit MyString(int, char = ' ');
	MyString(const MyString &);
	~MyString(void);
	int getLength() const;
	char getChar(int) const;
	void afficher() const;

	char *getBuffer() const;
	void setBuffer(const char *);
	void append(const char *);
	// surcharges pour les objets MyString
	void setBuffer(const MyString &);
	void append(const MyString &);

	// tester si la chaine est vide
	bool operator!() const;
	// methode de +=
	MyString &operator+=(const MyString &);

	// surcahge du casting operator const char*()
	//operator const char *() const;
};
