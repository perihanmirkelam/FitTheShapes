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

ComposedShape::ComposedShape(Rectangle bigOne, Rectangle smallOne) {
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
void ComposedShape::drawTT() {
	cout<<"hohoooo0\n";
	string bigSvg = bigShapeTriangle->draw();
	cout<<"hohoooo1\n";
	cout<<bigSvg;
	string smallSvgs="";
	for(int i=0; i<smallTriangleShapes.size();i++) {
		smallSvgs+= smallTriangleShapes.at(i).draw();
	}
	cout<<smallSvgs;

	ofstream myfile;
	myfile.open ("output.svg");
	myfile << "<svg version=\"1.1\"\n"
	          "baseProfile=\"full\"\n"
	          "width= \"" << svgWidth << "\" height=\"" << svgHeight << "\"\n"
	          "xmlns=\"http://www.w3.org/2000/svg\">\n"
	          << bigSvg << smallSvgs <<
		     // "<rect width=\"70%\" height=\"50%\" fill=\"red\" />\n"
	         // "<rect x=\"0\" y=\"105\" width=\"80\" height=\"80\" fill=\"blue\"/>\n"
	         // "<polygon points=\"10,10 20,80 80,80\" class=\"triangle\" />"
	         // "<circle cx=\"100\" cy=\"100\" r=\"80\" fill=\"green\" />\n"
	          "</svg>" << endl;
	myfile.close();
}

void ComposedShape::drawRR() {
	cout<<"hohoooo0\n";
	string bigSvg = bigShapeRectangle->draw();
	cout<<"hohoooo1\n";
	cout<<bigSvg;
	string smallSvgs="";
	for(int i=0; i<smallRectangleShapes.size();i++) {
		smallSvgs+= smallRectangleShapes.at(i).draw();
	}
	cout<<smallSvgs;

	ofstream myfile;
	myfile.open ("output.svg");
	myfile << "<svg version=\"1.1\"\n"
	          "baseProfile=\"full\"\n"
	          "width= \"" << svgWidth << "\" height=\"" << svgHeight << "\"\n"
	          "xmlns=\"http://www.w3.org/2000/svg\">\n"
	          << bigSvg << smallSvgs <<
		     // "<rect width=\"70%\" height=\"50%\" fill=\"red\" />\n"
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

void ComposedShape::optimalFit(Rectangle big, Rectangle small){

	int quantityOfSmallShapes = 0;
	bigShapeRectangle = new Rectangle(big.getWidth(),big.getHeight());

	setSvgSizes(big.getWidth(), big.getHeight());

	int quantityStraight = (bigShapeRectangle->getHeight() / small.getHeight()) * (bigShapeRectangle->getWidth() / small.getWidth());
	int quantityRotated = (bigShapeRectangle->getHeight() / small.getWidth()) * (bigShapeRectangle->getWidth() / small.getHeight());
	int row=0, column = 0;


	int bigx1y1[2],bigx2y2[2],bigx3y3[2], bigx4y4[2];
	bigx1y1[0] = 0;
	bigx1y1[1] = 0;

	bigx2y2[0] = bigShapeRectangle->getWidth();
	bigx2y2[1] = 0;

	bigx3y3[0] = bigShapeRectangle->getWidth();
	bigx3y3[1] = bigShapeRectangle->getHeight();

	bigx4y4[0] = 0;
	bigx4y4[1] = bigShapeRectangle->getHeight();


	this->bigShapeRectangle->setPositions(bigx1y1, bigx2y2, bigx3y3, bigx4y4);
	this->bigShapeRectangle->setColor("blue");
	if(quantityStraight >= quantityRotated){
		quantityOfSmallShapes = quantityStraight;
		row = bigShapeRectangle->getHeight() / small.getHeight();
		column = bigShapeRectangle->getWidth() / small.getWidth();
	} else {
		quantityOfSmallShapes = quantityRotated;
		row = bigShapeRectangle->getHeight() / small.getWidth();
		column = bigShapeRectangle->getWidth() / small.getHeight();
		int temp = small.getWidth();
		small.setWidth(small.getHeight());
		small.setHeight(temp);
	}
	for (int i=0; i<row; i++){
		for(int j=0; j<column; j++){

			Rectangle smallRect(small.getWidth(), small.getHeight());
			int x1y1[2],x2y2[2],x3y3[2], x4y4[2];

			int base_x = small.getWidth() * j;
			int base_y = i * small.getHeight();
			x1y1[0] = base_x;
			x1y1[1] = base_y;

			x2y2[0] = base_x + small.getWidth();
			x2y2[1] = base_y;

			x3y3[0] = base_x + small.getWidth();
			x3y3[1] = base_y +small.getHeight();

			x4y4[0] = base_x;
			x4y4[1] = base_y + small.getHeight();
			smallRect.setColor("yellow");
			smallRect.setPositions(x1y1,x2y2,x3y3,x4y4);
			smallRectangleShapes.push_back(smallRect);
		}
	}

	cout<<"\nTotal Small Rect Size : " << smallRectangleShapes.size()<<endl;
}
void ComposedShape::optimalFit(Rectangle, Triangle){}
void ComposedShape::optimalFit(Rectangle, Circle){}
void ComposedShape::optimalFit(Triangle big, Triangle small){

		int svg_w = big.getEdge()+1;
		int svg_h = big.getHeight();
		setSvgSizes(svg_w, svg_h);
		std::string svgPart;
		int height = small.getHeight();
		int halfEdge = small.getEdge() / 2;
		cout<<"small triangle height: "<<height<<endl;
		int column = big.getEdge() / small.getEdge();
		int row = big.getHeight() / small.getHeight();

		int bigTriangle_x1 = 0;
		int bigTriangle_y1 = svg_h;
		int bigTriangle_x2 = svg_w;
		int bigTriangle_y2 = svg_h;
		int bigTriangle_x3 = svg_w / 2;
		int bigTriangle_y3 = 0;

		int bigx1y1[2],bigx2y2[2],bigx3y3[2];
		bigx1y1[0] = 0;
		bigx1y1[1] = svg_h;
		bigx2y2[0] = svg_w;
		bigx2y2[1] = svg_h;
		bigx3y3[0] = svg_w / 2;
		bigx3y3[1] = 0;
		big.setPositions(bigx1y1, bigx2y2, bigx3y3);
		big.setColor("blue");

		this->bigShapeTriangle = new Triangle(big.getEdge());
		this->bigShapeTriangle->setPositions(bigx1y1, bigx2y2, bigx3y3);
		this->bigShapeTriangle->setColor("blue");



		//bigShape = new Triangle(big.getEdge());
		//Triangle triangles[]  = new Triangle[5];

		int tempWidth = big.getEdge() - small.getEdge();

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				cout<<i<<"\n";

				Triangle smallTriangle(small.getEdge());
				smallTriangle.setColor("green");
				int x1y1a[2],x2y2a[2],x3y3a[2];
				x1y1a[0] = (i * halfEdge) + (j * small.getEdge());
				x1y1a[1] = svg_h - (i * height);

				x2y2a[0] = (i * halfEdge) + (small.getEdge()) +(j * small.getEdge());
				x2y2a[1] = svg_h - (i * height);

				x3y3a[0] = (i * halfEdge) + halfEdge + (j * small.getEdge());
				x3y3a[1] = svg_h - height - (i * height);

			   smallTriangle.setPositions(x1y1a,x2y2a,x3y3a);
			   smallTriangleShapes.push_back(smallTriangle);


				if (((j + 1) * small.getEdge()) <= tempWidth + 1) {

					Triangle smallTrianglez(small.getEdge());
					smallTrianglez.setColor("green");
					int x1y1z[2],x2y2z[2],x3y3z[2];
					x1y1z[0] = (i * halfEdge) + halfEdge + ((j + 1) * small.getEdge());
					x1y1z[1] = svg_h - height - (i * height);

					x2y2z[0] = (i * halfEdge) + small.getEdge() + (j * small.getEdge());
					x2y2z[1] = svg_h - (i * height);

					x3y3z[0] = (i * halfEdge) + halfEdge + (j * small.getEdge());
					x3y3z[1] = svg_h - height - (i * height);

					smallTrianglez.setPositions(x1y1z,x2y2z,x3y3z);

					smallTriangleShapes.push_back(smallTrianglez);
				}
				cout<<"xx";

			}
			cout<<"aa";
			tempWidth = tempWidth - small.getEdge();
			column = (tempWidth + (small.getEdge())) / small.getEdge();
		}
		cout<<"ffff";
		cout<<smallTriangleShapes.size();

	cout<<"\nTotal Small Triangle Size : " << smallTriangleShapes.size()<<endl;

}
void ComposedShape::optimalFit(Triangle, Rectangle){





}
void ComposedShape::optimalFit(Triangle, Circle){}
void ComposedShape::optimalFit(Circle, Circle){}
void ComposedShape::optimalFit(Circle, Rectangle){}
void ComposedShape::optimalFit(Circle, Triangle){}

