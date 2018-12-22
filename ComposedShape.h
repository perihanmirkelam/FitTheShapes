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
#include "Circle.h"
#include <string>
#include <vector>
#include <iostream>


class ComposedShape {
private:
	//type enum c-c c-r ...
	int type;
	int quantity;
	int emptyArea;
	int svgWidth;
	int svgHeight;
	std::string svgString;
	std::vector<std::string> smallShapes;
	std::string bigShapeSvg;
	void setSvgSizes(int, int);
	void calculateEmptyArea();
	int calculateQuantity();
	int getEmptyArea();
	std::string createSvgString();
	void convertCircleToPolygon(Circle);
	void optimalFit(Rectangle, Rectangle);
	void optimalFit(Rectangle, Triangle);
	void optimalFit(Rectangle, Circle);
	void optimalFit(Triangle, Triangle);
	void optimalFit(Triangle, Rectangle);
	void optimalFit(Triangle, Circle);
	void optimalFit(Circle, Circle);
	void optimalFit(Circle, Rectangle);
	void optimalFit(Circle, Triangle);


public:
	ComposedShape(Triangle bigOne, Triangle smallOne);

	void draw();
};

#endif /* COMPOSEDSHAPE_H_ */
