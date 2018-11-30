/*
 * Circle.h
 *
 *  Created on: Nov 29, 2018
 *      Author: Perihan Mirkelam
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_

class Circle {
	// "<circle cx=\"100\" cy=\"100\" r=\"80\" fill=\"green\" />\n"
private:
	int radius;
	double area;
	double p_x;
	double p_y;
	void calcArea();
public:
	Circle(int);
	double getArea();
	int getPositionX();
	void setPositionX(double);
	int getPositionY();
	void setPositionY(double);
};

#endif /* CIRCLE_H_ */
