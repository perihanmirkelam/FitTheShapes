/*
 * Rectangle.cpp
 *
 *  Created on: Nov 28, 2018
 *      Author: Perihan Mirkelam
 */

#include "Rectangle.h"
// "<rect x=\"0\" y=\"105\" width=\"80\" height=\"80\" fill=\"blue\"/>\n"

#include "iostream"

using namespace std;

Rectangle::Rectangle(int wdt, int hgt) {
	x1y1 = new int[2];
	x2y2 = new int[2];
	x3y3 = new int[2];
	x4y4 = new int[2];
	this->area = 0.0;
	this->width = wdt;
	this->height = hgt;
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

void Rectangle::setWidth(int w) {

	this->width = w;
}
void Rectangle::setHeight(int h) {
	this->height = h;
}

int Rectangle::getWidth() {
	return width;
}

int Rectangle::getHeight() {
	return height;
}
void Rectangle::calcPerimeter() {
	perimeter = 2 * (height + width);
}

void Rectangle::setX1Y1Position(int* arr) {
	//x1y1 = arr;
	x1y1[0] = arr[0];
	x1y1[1] = arr[1];
}
void Rectangle::setX2Y2Position(int* arr) {
	//x2y2 = arr;
	x2y2[0] = arr[0];
	x2y2[1] = arr[1];
}
void Rectangle::setX3Y3Position(int* arr) {
	//x3y3 = arr;
	x3y3[0] = arr[0];
	x3y3[1] = arr[1];
}

void Rectangle::setX4Y4Position(int* arr) {
	//x3y3 = arr;
	x4y4[0] = arr[0];
	x4y4[1] = arr[1];
}
int *Rectangle::getX1Y1Position() {
	return x1y1;
}
int *Rectangle::getX2Y2Position() {
	return x2y2;
}
int *Rectangle::getX3Y3Position() {
	return x3y3;
}
int *Rectangle::getX4Y4Position() {
	return x4y4;
}

void Rectangle::setPositions(int *x1y1, int *x2y2, int *x3y3, int *x4y4) {
	std::cout << "x1y1: " << x1y1[0] << " | " << x1y1[1] << std::endl;
	std::cout << "x2y2: " << x2y2[0] << " | " << x2y2[1] << std::endl;
	std::cout << "x3y3: " << x3y3[0] << " | " << x3y3[1] << std::endl;
	std::cout << "x4y4: " << x4y4[0] << " | " << x3y3[1] << std::endl;

	setX1Y1Position(x1y1);
	setX2Y2Position(x2y2);
	setX3Y3Position(x3y3);
	setX4Y4Position(x4y4);
}

double Rectangle::getPerimeter() {
	return this->perimeter;
}

std::string Rectangle::draw() {
	std::cout << "s0s\n draw\n";
	std::cout << "x1y1: " << x1y1[0] << " | " << x1y1[1] << std::endl;
	std::cout << "x2y2: " << x2y2[0] << " | " << x2y2[1] << std::endl;
	std::cout << "x3y3: " << x3y3[0] << " | " << x3y3[1] << std::endl;
	std::cout << "x4y4: " << x4y4[0] << " | " << x4y4[1] << std::endl;
	//std::cout<<"ss"<<x1y1[0];
	/*return "<rect x=\"" + to_string(svg_w - height) + "\" y=\"" + to_string(svg_h - width)
			 + "\" width=\"" + to_string(height) + "\" height=\"" + to_string(width)
			 + "\" fill=\""+color+"\" style=\"stroke-width:1;stroke:rgb(10,10,10)\" />\n";*/


	 return "<polygon points=\"" + to_string(this->x1y1[0]) + "," + to_string(x1y1[1])
					+ " " + to_string(x2y2[0]) + "," + to_string(x2y2[1]) + " "
					+ to_string(x3y3[0]) + "," + to_string(x3y3[1]) +" "
					+ to_string(x4y4[0]) + "," + to_string(x4y4[1])
					+ "\" class=\"rectangle\" fill=\""+color+"\"/>\n";
}

void Rectangle::setColor(std::string clr) {
	color = clr;
}
std::string Rectangle::getColor() {
	return color;
}

