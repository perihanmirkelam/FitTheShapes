/*
 * Triangle.cpp
 *
 *  Created on: Nov 28, 2018
 *      Author: Perihan Mirkelam
 */

#include "Triangle.h"

// "<polygon points=\"10,10 20,80 80,80\" class=\"triangle\" />"

using namespace std;

const double squareRoot3 = 1.732050807568877;

Triangle::Triangle(int edges) {
	x1y1 = new int[2];
	x2y2 = new int[2];
	x3y3 = new int[2];
	this->area = 0.0;
	this->edge = edges;
	this->rotated = false;
	this->height = (edge * squareRoot3) / 2;
	calcArea();
	calcPerimeter();
}

int Triangle::getEdge() {
	return edge;

}
double Triangle::getHeight() {
	return height;
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

void Triangle::calcPerimeter() {
	perimeter = 3*edge;
}

void Triangle::setX1Y1Position(int* arr) {
	//x1y1 = arr;
	x1y1[0] = arr[0];
	x1y1[1] = arr[1];
}
void Triangle::setX2Y2Position(int* arr) {
	//x2y2 = arr;
	x2y2[0] = arr[0];
	x2y2[1] = arr[1];
}
void Triangle::setX3Y3Position(int* arr) {
	//x3y3 = arr;
	x3y3[0] = arr[0];
	x3y3[1] = arr[1];
}
int *Triangle::getX1Y1Position(){
	return x1y1;
}
int *Triangle::getX2Y2Position() {
	return x2y2;
}
int *Triangle::getX3Y3Position() {
	return x3y3;
}

void Triangle::setPositions(int *x1y1, int *x2y2, int *x3y3){
	std::cout<<"x1y1: "<<x1y1[0]<<" | "<<x1y1[1]<<std::endl;
	std::cout<<"x2y2: "<<x2y2[0]<<" | "<<x2y2[1]<<std::endl;
	std::cout<<"x3y3: "<<x3y3[0]<<" | "<<x3y3[1]<<std::endl;

	setX1Y1Position(x1y1);
	setX2Y2Position(x2y2);
	setX3Y3Position(x3y3);
}

std::string Triangle::draw() {
	std::cout<<"s0s\n draw\n";
	std::cout<<"x1y1: "<<x1y1[0]<<" | "<<x1y1[1]<<std::endl;
		std::cout<<"x2y2: "<<x2y2[0]<<" | "<<x2y2[1]<<std::endl;
		std::cout<<"x3y3: "<<x3y3[0]<<" | "<<x3y3[1]<<std::endl;
	//std::cout<<"ss"<<x1y1[0];
	 return "<polygon points=\"" + to_string(this->x1y1[0]) + "," + to_string(x1y1[1])
					+ " " + to_string(x2y2[0]) + "," + to_string(x2y2[1]) + " "
					+ to_string(x3y3[0]) + "," + to_string(x3y3[1])
					+ "\" class=\"triangle\" fill=\""+color+"\"/>\n";
}
