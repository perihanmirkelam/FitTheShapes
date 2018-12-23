/*
 * Shape.cpp
 *
 *  Created on: Dec 23, 2018
 *      Author: codegenius
 */

#include "Shape.h"

void Shape::setColor(std::string clr){
	this->color = clr;

}

std::string Shape::getColor() {
	return color;
}

double Shape::getArea(){
	return area;
}
double Shape::getPerimeter(){
	return perimeter;
}
