/*
 * Rectangle.cpp
 *
 *  Created on: Nov 28, 2018
 *      Author: codemania
 */

#include "Rectangle.h"

Rectangle::Rectangle(int width, int height){
	this->area = 0.0;
	this->width = width;
	this->height = height;
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




