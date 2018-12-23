/*
 * Shape.h
 *
 *  Created on: Dec 23, 2018
 *      Author: codegenius
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#include <string>

class Shape {
public:

	virtual void calcArea() = 0;
	virtual void calcPerimeter() = 0;
	virtual std::string draw() = 0;
	void setColor(std::string color);
	std::string getColor();
	double getArea();
	double getPerimeter();

protected:

	std::string color;
	double area;
	double perimeter;
};

#endif /* SHAPE_H_ */
