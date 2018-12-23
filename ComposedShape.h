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
	Triangle *bigShapeTriangle;
	Rectangle *bigShapeRectangle;
	Circle *bigShapeCircle;
	std::vector<Triangle> smallTriangleShapes;
	std::vector<Rectangle> smallRectangleShapes;
	std::vector<Circle> smallCircleShapes;
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
	ComposedShape(Rectangle bigOne, Rectangle smallOne);

	void drawRR();
	void drawTT();
};

#endif /* COMPOSEDSHAPE_H_ */
