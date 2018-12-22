/*
 * ComposedShape.cpp
 *
 *  Created on: Nov 29, 2018
 *      Author: Perihan Mirkelam
 */

#include "ComposedShape.h"
#include <string>
#include <math.h>
#include <vector>
#include "Polygon.h"
#include "Circle.h"
#include "fstream"

int type;
int quantity;
int emptyArea;
int algorithm;
using namespace std;

ComposedShape::ComposedShape(Triangle bigOne, Triangle smallOne) {
	optimalFit(bigOne,smallOne);
}

void ComposedShape::setSvgSizes(int width, int height) {
	//todo: svgwidth=... according to big shape
	this->svgWidth = width;
	this->svgHeight = height;
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
void ComposedShape::draw() {

	string smallsvg;

	for(int i=0; i<smallShapes.size();i++) {
		smallsvg+=smallShapes.at(i);
	}
	ofstream myfile;
	myfile.open("output.svg");
	myfile << "<svg version=\"1.1\"\n"
			"baseProfile=\"full\"\n"
			"width= \"" << svgWidth << "\" height=\"" << svgHeight << "\"\n"
			"xmlns=\"http://www.w3.org/2000/svg\">\n" << bigShapeSvg
			<< smallsvg <<

			// "<rect x=\"0\" y=\"105\" width=\"80\" height=\"80\" fill=\"blue\"/>\n"
			// "<polygon points=\"10,10 20,80 80,80\" class=\"triangle\" />"
			// "<circle cx=\"100\" cy=\"100\" r=\"80\" fill=\"green\" />\n"
			"</svg>" << endl;
	myfile.close();
}

void ComposedShape::convertCircleToPolygon(Circle circle) {
	const double PI = 3.14159265359;

	int x = circle.getPositionX();
	int y = circle.getPositionY();
	int r = circle.getRadius();
	double alpha = 3.6;

	std::vector<Polygon::Point2D> points;

	for (int i = 0; i < 100; i++) {

		double pointX = x + r - (r - r * (cos(i * alpha) * PI / 180.0));
		double pointY = y + r * (sin(i * alpha) * PI / 180.0);

		Polygon::Point2D a(pointX, pointY);

		points.insert(points.begin(), a);
	}

}

std::string ComposedShape::createSvgString() {

}

void ComposedShape::optimalFit(Rectangle, Rectangle){}
void ComposedShape::optimalFit(Rectangle, Triangle){}
void ComposedShape::optimalFit(Rectangle, Circle){}
void ComposedShape::optimalFit(Triangle big, Triangle small){

		int svg_w = big.edge + 1;
		int svg_h = big.height;
		setSvgSizes(svg_w, svg_h);
		std::string svgPart;
		int height = small.height;
		int halfEdge = small.edge / 2;
		cout<<"small triangle height: "<<height<<endl;
		int column = big.edge / small.edge;
		int row = big.height / small.height;

		int bigTriangle_x1 = 0;
		int bigTriangle_y1 = svg_h;
		int bigTriangle_x2 = svg_w;
		int bigTriangle_y2 = svg_h;
		int bigTriangle_x3 = svg_w / 2;
		int bigTriangle_y3 = 0;

		bigShapeSvg = "<polygon points=\"" + to_string(bigTriangle_x1) + ","
				+ to_string(bigTriangle_y1) + " " + to_string(bigTriangle_x2)
				+ "," + to_string(bigTriangle_y2) + " "
				+ to_string(bigTriangle_x3) + "," + to_string(bigTriangle_y3)
				+ "\" class=\"triangle\" fill=\"blue\" /> \n";

		int tempWidth = big.edge - small.edge;

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {

				std::string svgParticle = 	"<polygon points=\""
						+ to_string((i * halfEdge) + (j * small.edge)) + ","
						+ to_string(svg_h - (i * height))
						+ " " //x1 y1
						+ to_string(
								(i * halfEdge) + small.edge
										+ (j * small.edge)) + ","
						+ to_string(svg_h - (i * height))
						+ " " //x2 y2
						+ to_string(
								(i * halfEdge) + halfEdge
										+ (j * small.edge)) + ","
						+ to_string(svg_h - height - (i * height)) //x3 y3
						+ "\" class=\"triangle\" fill=\"green\" style=\"stroke-width:1;stroke:rgb(10,10,10)\" />\n";
			   smallShapes.push_back(svgParticle);
			   svgParticle="";



				if (((j + 1) * small.edge) <= tempWidth + 1) {
					svgParticle=
							"<polygon points=\""
									+ to_string(
											(i * halfEdge) + halfEdge
													+ ((j + 1) * small.edge)) + ","
									+ to_string(svg_h - height - (i * height))
									+ " " //x1 y1
									+ to_string(
											(i * halfEdge) + small.edge
													+ (j * small.edge)) + ","
									+ to_string(svg_h - (i * height))
									+ " " //x2 y2
									+ to_string(
											(i * halfEdge) + halfEdge
													+ (j * small.edge)) + ","
									+ to_string(svg_h - height - (i * height)) //x3 y3
									+ "\" class=\"triangle\" fill=\"green\" style=\"stroke-width:1;stroke:rgb(10,10,10)\" />\n";
					smallShapes.push_back(svgParticle);
				}
			}
			tempWidth = tempWidth - small.edge;
			column = (tempWidth + (small.edge)) / small.edge;
		}

	cout<<"\nTotal Small Triangle Size : " << smallShapes.size();

}
void ComposedShape::optimalFit(Triangle, Rectangle){}
void ComposedShape::optimalFit(Triangle, Circle){}
void ComposedShape::optimalFit(Circle, Circle){}
void ComposedShape::optimalFit(Circle, Rectangle){}
void ComposedShape::optimalFit(Circle, Triangle){}

