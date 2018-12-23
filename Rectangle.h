/*
 * Rectangle.h
 *
 *  Created on: Nov 28, 2018
 *      Author: Perihan Mirkelam
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "string"

class Rectangle {
	 // "<rect x=\"0\" y=\"105\" width=\"80\" height=\"80\" fill=\"blue\"/>\n"
private :

	int *x1y1;
	int *x2y2;
	int *x3y3;
	int *x4y4;
	int width;
	int height;
	bool rotated;
	double perimeter;
	double area;
	void calcArea();
	void calcPerimeter();
	std::string color;

public 	:
	Rectangle(int,int);
	double getArea();
	double getPerimeter();
	void setWidth(int);
	void setHeight(int);
	void setRotated(bool);
	void setX1Y1Position(int *);
	void setX2Y2Position(int *);
	void setX3Y3Position(int *);
	void setX4Y4Position(int *);
	void setPositions(int *, int *, int *, int *);
	int *getX1Y1Position();
	int *getX2Y2Position();
	int *getX3Y3Position();
	int *getX4Y4Position();
	bool isRotated();
	int getWidth();
	int getHeight();
	std::string draw();
	void setColor(std::string color);
	std::string getColor();
};





#endif /* RECTANGLE_H_ */
