#include "Point.h"

Point::Point()
{
    this->x = 0;
    this->y = 0;
}

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

Point::~Point()
{
    // cout << "Destructeur de Point" << endl;
}

void Point::setX(int x)
{
    this->x = x;
}
void Point::setY(int y)
{
    this->y = y;
}
int Point::getX(void) const
{
    return this->x;
}
int Point::getY(void) const
{
    return this->y;
}
void Point::afficher(void) const
{
    cout << "(" << this->x << ", " << this->y << ")" << endl;
}
bool Point::isEqual(const Point &p) const
{
    return (this->x == p.x && this->y == p.y);
}
bool Point::isOrigin(void)
{
    return (this->x == 0 && this->y == 0);
}
void Point::move(int dx, int dy)
{
    this->x += dx;
    this->y += dy;
}
void Point::move(const Point &p)
{
    this->x += p.x;
    this->y += p.y;
}
void Point::setLocation(int x, int y)
{
    setX(x);
    setY(y);
}
void Point::setLocation(const Point &p)
{
    setX(p.x);
    setY(p.y);
}
double Point::distance(const Point &p) const
{
    return sqrt(pow(this->x - p.x, 2) + pow(this->y - p.y, 2));
}
double Point::distance(int x, int y) const
{
    return sqrt(pow(this->x - x, 2) + pow(this->y - y, 2));
}