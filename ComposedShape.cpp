/*
 * ComposedShape.cpp
 *
 *  Created on: Nov 29, 2018
 *      Author: Perihan Mirkelam
 */

#include "ComposedShape.h"
#include <string>

ComposedShape::ComposedShape(Rectangle bigRectangle, Rectangle smallRectangle) {
	string svgPart;
	int big_w = bigRectangle.getWidth();
	int big_h = bigRectangle.getHeight();
	int small_w = smallRectangle.getWidth();
	int small_h = smallRectangle.getHeight();

	int quantityStraight = (big_h / small_h) * (big_w / small_w);
	int quantityRotated = (big_h / small_w) * (big_w / small_h);
	int row = 0, column = 0;
	if (quantityStraight >= quantityRotated) {
		quantityOfSmallShapes = quantityStraight;
		row = big_h / small_h;
		column = big_w / small_w;
	} else {
		quantityOfSmallShapes = quantityRotated;
		row = big_h / small_w;
		column = big_w / small_h;
		int temp = small_w;
		small_w = small_h;
		small_h = temp;
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			svgPart +=
					"<rect x=\"" + to_string(small_w * j) + "\" y=\""
							+ to_string(i * small_h) + "\" width=\""
							+ to_string(small_w) + "\" height=\""
							+ to_string(small_h)
							+ "\" fill=\"yellow\" style=\"stroke-width:1;stroke:rgb(10,10,10)\" />\n";
		}
	}
	//return svgPart;
}

ComposedShape::draw() {
}

int type;
int quantity;
int emptyArea;
void ComposedShape::calculateSvgSize() {
	//todo: svgwidth=... according to big shape
}
void ComposedShape::calculateEmptyArea() {
	//todo: emptyArea=...
}
int ComposedShape::calculateQuantity() {
	//todo: quantity=...
}
int ComposedShape::getEmptyArea() {
	return emptyArea;
}

ComposedShape::ComposedShape(Rectangle, Triangle) {

}
void ComposedShape::draw() {

}

