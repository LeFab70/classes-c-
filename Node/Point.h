#pragma once // eviter inclusion /appel multiple
#include <iostream>
#include <cstring>
using namespace std;
class Point
{
private:
    int x;
    int y;

public:
    // constructeur par defaut
    Point();
    // constructeurs surcharge
    // sil est defini il remplace celui par defaut, donc faut redefini celui par defaut si des objet avec constructeur par defaut
    Point(int, int);

    // destructeur il ya un seul ou celui par defaut quand objet est static
    ~Point();
    void setX(int);
    void setY(int);
    int getX(void) const;
    int getY(void) const;
    void afficher(void) const;
    bool isEqual(const Point &) const;
    bool isOrigin(void);
    void move(int, int);
    void move(const Point &);
    void setLocation(int, int);
    void setLocation(const Point &);
    double distance(const Point &) const;
    double distance(int, int) const;
};