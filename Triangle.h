/*
 * Triangle.h
 *
 *  Created on: Nov 28, 2018
 *      Author: Perihan Mirkelam
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

class Triangle {
private:
	double area;
	int edge;
	double height;
	bool rotated;
	double p_x;
	double p_y;
	void calcArea();

public:
	Triangle(int);
	double getArea();
	void setRotated(bool);
	bool isRotated();
	int getPositionX();
	void setPositionX(double);
	int getPositionY();
	void setPositionY(double);
};

#endif /* TRIANGLE_H_ */

