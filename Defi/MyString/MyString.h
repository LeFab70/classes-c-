#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

class MyString
{
private:
	char* buf;
	int len;

public:
	MyString(void);
	MyString(const char*);
	//ajout du constructeur avec un caractere
	MyString(const char);
	//ajout du constructeur avec int et char
	explicit MyString(int,char=' ');
	MyString(const MyString&);
	~MyString(void);
	int getLength() const;
	char getChar(int) const;
	void afficher() const;

	char* getBuffer() const;
	void setBuffer(const char*);
	void append(const char*);
	//surcharges pour les objets MyString
	void setBuffer(const MyString&);
	void append(const MyString&);
};

