/*
 * Circle.cpp
 *
 *  Created on: Nov 29, 2018
 *      Author: Perihan Mirkelam
 */

#include "Circle.h"

double PI = 3.14159265359;

Circle::Circle (int radius){
	this->p_x=0.0;
	this->p_y=0.0;
	this->area = 0.0;
	this->radius = radius;
	calcArea();
}

double Circle::getArea(){
	return area;
}

void Circle::calcArea(){
	area = PI * radius * radius;
}

int Circle::getPositionX(){
	return p_x;
}

int Circle::getPositionY(){
	return p_y;
}
int Circle::getRadius(){
	return radius;
}

void Circle::setPositionX(double positionX){
	p_x = positionX;
}

void Circle::setPositionY(double positionY){
	p_y = positionY;
}


