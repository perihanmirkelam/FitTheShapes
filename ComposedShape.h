/*
 * ComposedShape.h
 *
 *  Created on: Nov 29, 2018
 *      Author: Perihan Mirkelam
 */

#ifndef COMPOSEDSHAPE_H_
#define COMPOSEDSHAPE_H_
#include "Rectangle.h"
#include "Triangle.h"
#include <string>

class ComposedShape {
private:
	//type enum c-c c-r ...
	int type;
	int quantity;
	int emptyArea;
	double svgWidth;
	double svgHeight;
	std::string svgString;
	void calculateSvgSize();
	void calculateEmptyArea();
	int calculateQuantity();
	int getEmptyArea();
	std::string createSvgString();

public:
	void draw();
};

#endif /* COMPOSEDSHAPE_H_ */
