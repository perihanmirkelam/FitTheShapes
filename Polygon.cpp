/*
 * Polygon.cpp
 *
 *  Created on: Nov 30, 2018
 *      Author: codemania
 */
#include <vector>
#include "Polygon.h"
#include "Triangle.h"
#include <iostream>

using namespace std;

Polygon::Polygon(std::vector<Polygon::Point2D> points) {
	// TODO Auto-generated constructor stub
	this->pointVect = points;

}

Polygon::Polygon(Triangle triangle) {
cout<<"Tri cons"<<endl;
}
Polygon::Polygon(Rectangle rect) {
cout<<"Rect cons"<<endl;

}
Polygon::Polygon(Circle circ) {
cout<<"Circ cons"<<endl;

}
