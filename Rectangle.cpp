/*
 * Rectangle.cpp
 *
 *  Created on: Nov 28, 2018
 *      Author: Perihan Mirkelam
 */

#include "Rectangle.h"
	 // "<rect x=\"0\" y=\"105\" width=\"80\" height=\"80\" fill=\"blue\"/>\n"

Rectangle::Rectangle(int width, int height){
	this->p_x=0.0;
	this->p_y=0.0;
	this->area=0.0;
	this->width=width;
	this->height=height;
	calcArea();
}

void Rectangle::calcArea() {
	area = width * height;
}

double Rectangle::getArea() {
	return this->area;
}

void Rectangle::setRotated(bool isRotated) {
	this->rotated = isRotated;
}

bool Rectangle::isRotated() {
	return this->rotated;
}

int Rectangle::getPositionX(){
	return this->p_x;
}
void Rectangle::setPositionX(double position_x){
	//check if negative
	p_x = position_x;
}

int Rectangle::getPositionY(){
	return this->p_y;
}
void Rectangle::setPositionY(double position_y){
	//check if negative
	p_y = position_y;
}

int Rectangle::getWidth(){
	return width;
}

int Rectangle::getHeight(){
	return height;
}




