#include <stdio.h>
#include <math.h>

typedef struct Points
{
    double x;
    double y;
} Point;

void printPoint(Point p);

Point createPoint(double x, double y);

double getDistance(Point a, Point b);

int main()
{
    Point p1, p2;

    printf("distace between points: %lf", getDistance(createPoint(2, -3), createPoint(-4, 5)));

    return 0;
}

void printPoint(Point p)
{
    printf("(%lf, %lf)", p.x, p.y);
}

Point createPoint(double x, double y)
{
    Point p;

    p.x = x;
    p.y = y;

    return p;
}

double getDistance(Point a, Point b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}