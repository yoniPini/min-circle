// 315538074

#ifndef MINCIRCLE_H_
#define MINCIRCLE_H_
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <math.h>
#include <iostream>

using namespace std;

// ------------ DO NOT CHANGE -----------
class Point{
public:
	float x,y;
	Point(float x,float y):x(x),y(y){}
};

class Circle{
public:
	Point center;
	float radius;
	Circle(Point c,float r):center(c),radius(r){}
};
// --------------------------------------

// implement

Point centerOfPoints(Point *p1, Point *p2) {
	double x = (p1->x - p2->x) / 2;
	double y = (p1->y - p2->y) / 2;
	return Point(x, y);
}

Circle findMinCircle(Point** points,size_t size) {
	float maxD = 0;
	Point p1(0, 0), p2(0, 0);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			double t = distance(points[i], points[j]);
			if (t > maxD)
			{
				p1 = * points[i];
				p2 = * points[j];
				maxD = t;
			}
		}
	}


	return Circle(centerOfPoints(&p1, &p2), maxD / 2);
}

// you may add helper functions here


double distance(Point *p1, Point *p2) {
	return sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2)); 
}

double distance(Circle &c, Point p) {
	return sqrt(pow(c.center.x - p.x, 2) + pow(c.center.y - p.y, 2)); 
}

#endif /* MINCIRCLE_H_ */
