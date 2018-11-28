/*
 * Rectangle.h
 *
 *  Created on: Nov 28, 2018
 *      Author: perihanmirkelam
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

class Rectangle {

private :
	int width;
	int height;
	bool rotated;
	double area;
public 	:
	Rectangle(int,int);
	void calcArea();
	double getArea();
	void setRotated(bool);
	bool isRotated();
};





#endif /* RECTANGLE_H_ */
