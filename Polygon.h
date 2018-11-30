/*
 * Polygon.h
 *
 *  Created on: Nov 30, 2018
 *      Author: codemania
 */

#ifndef POLYGON_H_
#define POLYGON_H_

#include <vector>
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"

class Polygon {
public:
	class Point2D {
	public:
	int pointX;
	int pointY;
	Point2D(int x,int y){
		pointX = x;
		pointY = y;
	};
	};
Polygon(std::vector<Polygon::Point2D> pointVect);
Polygon(Triangle);
Polygon(Rectangle);
Polygon(Circle);

private:
std::vector<Polygon::Point2D> pointVect;
};


#endif /* POLYGON_H_ */
