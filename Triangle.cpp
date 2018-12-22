/*
 * Triangle.cpp
 *
 *  Created on: Nov 28, 2018
 *      Author: Perihan Mirkelam
 */

#include "Triangle.h"

// "<polygon points=\"10,10 20,80 80,80\" class=\"triangle\" />"

const double squareRoot3 = 1.732050807568877;

Triangle::Triangle(int edges) {
	this->p_x = 0.0;
	this->p_y = 0.0;
	this->area = 0.0;
	this->edge = edges;
	this->rotated = false;
	this->height = (edge * squareRoot3) / 2;
	calcArea();
}

double Triangle::getArea() {
	return area;
}

void Triangle::calcArea() {
	area = (edge * height) / 2;
}

void Triangle::setRotated(bool rotated) {
	this->rotated = rotated;
}
bool Triangle::isRotated() {
	return this->rotated;
}

int Triangle::getPositionX() {
	return p_x;
}

int Triangle::getPositionY() {
	return p_y;
}

void Triangle::setPositionX(double positionX) {
	p_x = positionX;
}

void Triangle::setPositionY(double positionY) {
	p_y = positionY;
}

