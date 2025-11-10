#include "Point.h"

Point::Point(void)
{
	this->x = 0;
	this->y = 0;
}

Point::Point(int x , int y)
{
	//this->x = x;
	//this->y = y;
	this->setX(x);
	this->setY(y);
}

Point::~Point(void)
{

}


void Point::setX(int x)
{
	this->x = x;
}

void Point::setY(int y)
{
	this->y = y;
}

int Point::getX() const
{
	return this->x;
}

int Point::getY() const
{
	return this->y;
}


bool Point::isEqual(const Point& p) const
{
	return (this->x == p.x && this->y == p.y);	
}

void Point::move(int x,int y)
{
	this->x += x;
	this->y += y;
}

void Point::move(const Point& p)
{
	this->move(p.x,p.y);

	//ou
	//this->x += p.x;
	//this->y += p.y;
}

void Point::setLocation(int x,int y)
{
	this->x = x;
	this->y = y;

}

void Point::setLocation(const Point& p)
{
	this->setLocation(p.x,p.y);

	//ou
	//this->x = p.x;
	//this->y = p.y;
}

bool Point::isOrigin() const
{
	
	return this->x == 0 && this->y == 0;
	//ou
	//Point origine(0,0);
	//return this->isEqual(origine);
}

void Point::afficher() const
{
	cout << "( " << this->x << ", " << this->y << " )";
}

double Point::distance(const Point& p) const
{
	return sqrt(pow(this->x - p.x,2.0) + pow(this->y - p.y,2.0));
}

double Point::distance(int x, int y) const
{
	return sqrt(pow(this->x - x,2.0) + pow(this->y - y,2.0));
}