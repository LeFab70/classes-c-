#pragma once
#include <iostream>
#include <math.h>
using namespace std;

class Point
{
private :
	int x;
	int y;

public:
	Point(void);
	Point(int , int);
	~Point(void);

	void setX(int);
	void setY(int);
	int getX() const;
	int getY() const;

	bool isEqual(const Point&) const;
	void move(int,int);
	void move(const Point&);
	void setLocation(int,int);
	void setLocation(const Point&);
	bool isOrigin()const;
	void afficher() const;
	double distance(const Point&) const;
	double distance(int,int)const ;

};

