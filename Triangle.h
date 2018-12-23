/*
 * Triangle.h
 *
 *  Created on: Nov 28, 2018
 *      Author: Perihan Mirkelam
 */
#include <iostream>
#include <string>
#include "Shape.h"

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

class Triangle: public Shape {
private:
	int *x1y1;
	int *x2y2;
	int *x3y3;
	int edge;
    double height;
	bool rotated;

public:
	Triangle(int);
	virtual void calcArea();
	virtual void calcPerimeter();
	double getHeight();
	int getEdge();
	void setRotated(bool);
	bool isRotated();
	void setX1Y1Position(int *);
	void setX2Y2Position(int *);
	void setX3Y3Position(int *);
	void setPositions(int *, int *, int *);
	int *getX1Y1Position();
	int *getX2Y2Position();
	int *getX3Y3Position();
	virtual std::string draw();
};

#endif /* TRIANGLE_H_ */

