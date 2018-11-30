/*
 * Rectangle.h
 *
 *  Created on: Nov 28, 2018
 *      Author: Perihan Mirkelam
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

class Rectangle {
	 // "<rect x=\"0\" y=\"105\" width=\"80\" height=\"80\" fill=\"blue\"/>\n"
private :
	int width;
	int height;
	bool rotated;
	double area;
	double p_x;
	double p_y;
	void calcArea();
public 	:
	Rectangle(int,int);
	double getArea();
	void setRotated(bool);
	bool isRotated();
	int getPositionX();
	void setPositionX(double);
	int getPositionY();
	void setPositionY(double);
	int getWidth();
	int getHeight();
};





#endif /* RECTANGLE_H_ */
