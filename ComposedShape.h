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
	string svgString;
	void calculateSvgSize();
	void calculateEmptyArea();
	int calculateQuantity();
	int getEmptyArea();
	string createSvgString();

public:
	ComposedShape(Rectangle, Rectangle);
	ComposedShape(Rectangle, Triangle);
	ComposedShape(Rectangle, Circle);
	ComposedShape(Triangle, Triangle);
	ComposedShape(Triangle, Rectangle);
	ComposedShape(Triangle, Circle);
	ComposedShape(Circle, Circle);
	ComposedShape(Circle, Rectangle);
	ComposedShape(Circle, Triangle);

	void draw();
};

#endif /* COMPOSEDSHAPE_H_ */
