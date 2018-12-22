#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <math.h>
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "Polygon.h"

using namespace std;

//area
double bigRectangleArea = 0.0;
double bigCircleArea = 0.0;
double bigTriangleArea = 0.0;
double rectangleArea = 0.0;
double circleArea = 0.0;
double triangleArea = 0.0;
double bigShapeArea = 0.0;
double smallShapeArea = 0.0;

//whole file size
int svg_w = 0;
int svg_h = 0;

//rectangle sizes
int bigRectangle_x = 0;
int bigRectangle_y = 0;
int bigRectangle_w = 0;
int bigRectangle_h = 0;
int rectangle_x = 0;
int rectangle_y = 0;
int rectangle_w = 0;
int rectangle_h = 0;

//circle sizes
int bigCircle_x = 0;
int bigCircle_y = 0;
int bigCircle_r = 0;
int circle_x = 0;
int circle_y = 0;
int circle_r = 0;

//triangle sizes
int bigTriangle_x1 = 0;
int bigTriangle_y1 = 0;
int bigTriangle_x2 = 0;
int bigTriangle_y2 = 0;
int bigTriangle_x3 = 0;
int bigTriangle_y3 = 0;
int bigTriangle_e = 0;
int triangle_x1 = 0;
int triangle_y1 = 0;
int triangle_x2 = 0;
int triangle_y2 = 0;
int triangle_x3 = 0;
int triangle_y3 = 0;
int triangle_e = 0;

//shape types
enum class Shape {
	R, C, T
};

//desired shape types
Shape bigShapeType;
Shape smallShapesType;

string bigShapeSvg;
int quantityOfSmallShapes;

void askSmallShapes();
void askBigShape();
void drawSvg(string);
void assignShapeType(bool, string);

void drawSvg(string smallShapes) {
	string svg;
	ofstream myfile;
	myfile.open("output.svg");
	myfile << "<svg version=\"1.1\"\n"
			"baseProfile=\"full\"\n"
			"width= \"" << svg_w << "\" height=\"" << svg_h << "\"\n"
			"xmlns=\"http://www.w3.org/2000/svg\">\n" << bigShapeSvg
			<< smallShapes <<

			// "<rect x=\"0\" y=\"105\" width=\"80\" height=\"80\" fill=\"blue\"/>\n"
			// "<polygon points=\"10,10 20,80 80,80\" class=\"triangle\" />"
			// "<circle cx=\"100\" cy=\"100\" r=\"80\" fill=\"green\" />\n"
			"</svg>" << endl;
	myfile.close();
}

string trianglesInTriangle() {
	string svgPart;
	int height = (int) (triangle_e * sqrt(3)) / 2;
	int halfEdge = triangle_e / 2;
	cout << "triangle height: " << height << endl;
	int column = svg_w / triangle_e;
	int row = svg_h / height;
	quantityOfSmallShapes += column * row;
	svg_w += 1;
	int tempWidth = svg_w - triangle_e;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			svgPart +=
					"<polygon points=\""
							+ to_string((i * halfEdge) + (j * triangle_e)) + ","
							+ to_string(svg_h - (i * height))
							+ " " //x1 y1
							+ to_string(
									(i * halfEdge) + triangle_e
											+ (j * triangle_e)) + ","
							+ to_string(svg_h - (i * height))
							+ " " //x2 y2
							+ to_string(
									(i * halfEdge) + halfEdge
											+ (j * triangle_e)) + ","
							+ to_string(svg_h - height - (i * height)) //x3 y3
							+ "\" class=\"triangle\" fill=\"green\" style=\"stroke-width:1;stroke:rgb(10,10,10)\" />\n";

			if (((j + 1) * triangle_e) <= tempWidth + 1) {
				svgPart +=
						"<polygon points=\""
								+ to_string(
										(i * halfEdge) + halfEdge
												+ ((j + 1) * triangle_e)) + ","
								+ to_string(svg_h - height - (i * height))
								+ " " //x1 y1
								+ to_string(
										(i * halfEdge) + triangle_e
												+ (j * triangle_e)) + ","
								+ to_string(svg_h - (i * height))
								+ " " //x2 y2
								+ to_string(
										(i * halfEdge) + halfEdge
												+ (j * triangle_e)) + ","
								+ to_string(svg_h - height - (i * height)) //x3 y3
								+ "\" class=\"triangle\" fill=\"green\" style=\"stroke-width:1;stroke:rgb(10,10,10)\" />\n";
				quantityOfSmallShapes++;
			}
		}
		tempWidth = tempWidth - triangle_e;
		column = (tempWidth + (triangle_e)) / triangle_e;
	}
	return svgPart;
}
string circlesInTriangle() {
	string svgPart;
	int diameter = 2 * circle_r;
	int innerVertical = ((circle_r * sqrt(3)) / 2) + 1;
	int row = (svg_h - (circle_r * sqrt(3)))
			/ (diameter - (circle_r * sqrt(3) - circle_r) / 4);
	quantityOfSmallShapes += (row * (row + 1)) / 2;
	//svg_w+=1;
	//int tempWidth = svg_w - triangle_e;
	int minusX = -circle_r;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < i + 1; j++) {
			svgPart +=
					"<circle cx=\""
							+ to_string(
									int(
											(svg_w / 2) - (i * circle_r)
													+ (j * diameter)))
							+ "\" cy=\""
							+ to_string(
									(int) ((i + 1) * diameter)
											- (i
													* (circle_r * sqrt(3)
															- circle_r) / 4))
							+ "\" r=\" " + to_string(circle_r)
							+ "\" fill=\"green\" style=\"stroke-width:1;stroke:rgb(10,10,10)\" />\n";
			// addMinusX =-addMinusX;
		}
	}
	return svgPart;
}

string rectanglesInTriangle() {
	string svgPart;
	int row = svg_h / rectangle_h;
	int column = svg_w / rectangle_w;
	int leapLength = (rectangle_h / sqrt(3)) + 1;
	int bigTriangle_w = svg_w;
	int bigTriangle_h = svg_h;

	if (row == 0 && column == 0 && (svg_w / rectangle_h) > 0
			&& (svg_w / rectangle_w) > 0) {
		//if only one and rotated rectangle fit in triangle
		svgPart +=
				"<rect x=\"" + to_string(svg_w - rectangle_h) + "\" y=\""
						+ to_string(svg_h - rectangle_w) + "\" width=\""
						+ to_string(rectangle_h) + "\" height=\""
						+ to_string(rectangle_w)
						+ "\" fill=\"yellow\" style=\"stroke-width:1;stroke:rgb(10,10,10)\" />\n";
		return svgPart;
	}

	int upperWidth = bigTriangle_w - (2 * leapLength);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if ((j + 1) * rectangle_w <= upperWidth) {
				svgPart +=
						"<rect x=\""
								+ to_string(
										(i + 1) * leapLength + j * rectangle_w)
								+ "\" y=\""
								+ to_string(bigTriangle_h - rectangle_h)
								+ "\" width=\"" + to_string(rectangle_w)
								+ "\" height=\"" + to_string(rectangle_h)
								+ "\" fill=\"yellow\" style=\"stroke-width:1;stroke:rgb(10,10,10)\" />\n";
				quantityOfSmallShapes++;
			}
		}
		bigTriangle_w = upperWidth;
		upperWidth = bigTriangle_w - (2 * (leapLength));
		bigTriangle_h -= rectangle_h;
	}
	return svgPart;
}

string trianglesInCircle() {
	string svgPart;
	return svgPart;
}
string circlesInCircle() {
	string svgPart;
	int diameter = 2 * circle_r;
	//int row = (2 * bigCircle_r) / (diameter - (circle_r * sqrt(3) - circle_r) / 4);
	int row = (2 * bigCircle_r) / (diameter);
	quantityOfSmallShapes += (row * (row + 1)) / 2;
	int sCircle_r = ((circle_r * sqrt(3)) - circle_r);
	int sDiameter = (diameter - sCircle_r);
	row = row / 2;
	row = row % 2 == 1 ? row : row + 1;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < i * 2 + 1; j++) {
			svgPart +=
					"<circle cx=\""
							+ to_string(
									(int) ((svg_w / 2) - ((i * 2 * circle_r))
											+ (j * diameter))) + "\" cy=\""
							+ to_string(
									(int) (((i + 1) * circle_r)
											+ (i * (circle_r)))) + "\" r=\" "
							+ to_string(circle_r)
							+ "\" fill=\"green\" style=\"stroke-width:1;stroke:rgb(10,10,10)\" />\n";
			svgPart +=
					"<circle cx=\""
							+ to_string(
									(int) ((svg_w / 2) - ((i * 2 * circle_r))
											+ (j * diameter))) + "\" cy=\""
							+ to_string(
									(svg_h - (int) (((i + 1) * circle_r))
											- (i * (circle_r)))) + "\" r=\" "
							+ to_string(circle_r)
							+ "\" fill=\"green\" style=\"stroke-width:1;stroke:rgb(10,10,10)\" />\n";
		}
	}
	return svgPart;
}
string rectanglesInCircle() {
	string svgPart;
	cout << "Unfortunately rectangles in circle part not prepared yet." << endl;
	return svgPart;
}

//calculate and draw how many triangle fit in rectangle
string trianglesInRectangle() {
	string svgPart;
	int height = (triangle_e * sqrt(3)) / 2;
	int halfEdge = triangle_e / 2;
	cout << "triangle height: " << height << endl;
	int column = bigRectangle_w / triangle_e;
	int row = bigRectangle_h / height;
	quantityOfSmallShapes = (column) * (row);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			svgPart +=
					"<polygon points=\"" + to_string(j * triangle_e) + ","
							+ to_string(height + i * height)
							+ " " //x1 y1
							+ to_string(triangle_e + (j * triangle_e)) + ","
							+ to_string(height + i * height)
							+ " " //x2 y2
							+ to_string(halfEdge + (j * triangle_e)) + ","
							+ to_string(i * height) //x3 y3
							+ "\" class=\"triangle\" fill=\"green\" style=\"stroke-width:1;stroke:rgb(10,10,10)\" />\n";
			if ((halfEdge + ((j + 1) * triangle_e)) <= svg_w) {
				svgPart +=
						"<polygon points=\""
								+ to_string(halfEdge + ((j + 1) * triangle_e))
								+ "," + to_string(i * height)
								+ " " //x1 y1
								+ to_string(triangle_e + (j * triangle_e)) + ","
								+ to_string(height + i * height)
								+ " " //x2 y2
								+ to_string(halfEdge + (j * triangle_e)) + ","
								+ to_string(i * height) //x3 y3
								+ "\" class=\"triangle\" fill=\"green\" style=\"stroke-width:1;stroke:rgb(10,10,10)\" />\n";
				quantityOfSmallShapes++;
			}
		}
	}
	return svgPart;
}

//calculate and draw how many circle fit in rectangle
string circlesInRectangle() {
	string svgPart;
	int diameter = circle_r * 2;
	int column = bigRectangle_w / diameter;
	int row = bigRectangle_h / diameter;
	quantityOfSmallShapes = (column) * (row);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			svgPart +=
					"<circle cx=\"" + to_string(circle_r + (j * diameter))
							+ "\" cy=\"" + to_string(circle_r + (i * diameter))
							+ "\" r=\"" + to_string(circle_r)
							+ "\" fill=\"green\" style=\"stroke-width:1;stroke:rgb(10,10,10)\" />\n";
		}
	}
	return svgPart;
}

//calculate and draw how many rectangle fit in rectangle
string rectanglesInRectangle() {
	string svgPart;
	int quantityStraight = (bigRectangle_h / rectangle_h)
			* (bigRectangle_w / rectangle_w);
	int quantityRotated = (bigRectangle_h / rectangle_w)
			* (bigRectangle_w / rectangle_h);
	int row = 0, column = 0;
	if (quantityStraight >= quantityRotated) {
		quantityOfSmallShapes = quantityStraight;
		row = bigRectangle_h / rectangle_h;
		column = bigRectangle_w / rectangle_w;
	} else {
		quantityOfSmallShapes = quantityRotated;
		row = bigRectangle_h / rectangle_w;
		column = bigRectangle_w / rectangle_h;
		int temp = rectangle_w;
		rectangle_w = rectangle_h;
		rectangle_h = temp;
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			svgPart +=
					"<rect x=\"" + to_string(rectangle_w * j) + "\" y=\""
							+ to_string(i * rectangle_h) + "\" width=\""
							+ to_string(rectangle_w) + "\" height=\""
							+ to_string(rectangle_h)
							+ "\" fill=\"yellow\" style=\"stroke-width:1;stroke:rgb(10,10,10)\" />\n";
		}
	}
	return svgPart;
}

void drawSmallShapes(Shape bigShapeType, Shape smallShapeType) {
	string smallShapes = "";
	switch (bigShapeType) {
	case Shape::R:
		switch (smallShapeType) {
		case Shape::R:
			smallShapes = rectanglesInRectangle();
			break;
		case Shape::C:
			smallShapes = circlesInRectangle();
			break;
		case Shape::T:
			smallShapes = trianglesInRectangle();
			break;
		}
		break;
	case Shape::C:
		switch (smallShapeType) {
		case Shape::R:
			smallShapes = rectanglesInCircle();
			break;
		case Shape::C:
			smallShapes = circlesInCircle();
			break;
		case Shape::T:
			smallShapes = trianglesInCircle();
			break;
		}
		break;
	case Shape::T:
		switch (smallShapeType) {
		case Shape::R:
			smallShapes = rectanglesInTriangle();
			break;
		case Shape::C:
			smallShapes = circlesInTriangle();
			break;
		case Shape::T:
			smallShapes = trianglesInTriangle();
			break;
		}
		break;
	}
	cout << "smallShapes: " << smallShapes << endl;
	drawSvg(smallShapes);
}
double calculateRectangleArea(bool isBigShape) {
	double area = 0.0;
	if (isBigShape) {
		bigRectangleArea = bigRectangle_w * bigRectangle_h;
		area = bigRectangleArea;
	} else {
		rectangleArea = rectangle_w * rectangle_h;
		area = rectangleArea;
	}
	return area;
}
double calculateCircleArea(bool isBigShape) {
	double area = 0.0;
	if (isBigShape) {
		bigCircleArea = M_PI * pow(bigCircle_r, 2);
		area = bigCircleArea;
	} else {
		circleArea = M_PI * pow(circle_r, 2);
		area = circleArea;
	}
	return area;
}

double calculateTriangleArea(bool isBigShape) {
	double area = 0.0;
	if (isBigShape) {
		bigTriangleArea = (pow(bigTriangle_e, 2) * sqrt(3)) / 2;
		area = bigTriangleArea;
	} else {
		triangleArea = (pow(triangle_e, 2) * sqrt(3)) / 2;
		area = triangleArea;
	}
	return area;
}

void drawBigShape() {
	switch (bigShapeType) {
	case Shape::R:
		bigShapeSvg = "<rect x=\"0\" y=\"0\" width=\"" + to_string(svg_w)
				+ "\" height=\"" + to_string(svg_h) + "\" fill=\"blue\"/>\n";
		break;
	case Shape::C:
		bigCircle_x = svg_w / 2;
		bigCircle_y = svg_h / 2;
		bigShapeSvg = "<circle cx=\"" + to_string(bigCircle_x) + "\" cy=\""
				+ to_string(bigCircle_y) + "\" r=\"" + to_string(bigCircle_r)
				+ "\" fill=\"blue\" />\n";
		break;
	case Shape::T:
		bigTriangle_x1 = 0;
		bigTriangle_y1 = svg_h;
		bigTriangle_x2 = svg_w;
		bigTriangle_y2 = svg_h;
		bigTriangle_x3 = svg_w / 2;
		bigTriangle_y3 = 0;
		bigShapeSvg = "<polygon points=\"" + to_string(bigTriangle_x1) + ","
				+ to_string(bigTriangle_y1) + " " + to_string(bigTriangle_x2)
				+ "," + to_string(bigTriangle_y2) + " "
				+ to_string(bigTriangle_x3) + "," + to_string(bigTriangle_y3)
				+ "\" class=\"triangle\" fill=\"blue\" /> \n";
		break;
	}
}

void calculateSvgSize() {
	switch (bigShapeType) {
	case Shape::R:
		svg_w = bigRectangle_w;
		svg_h = bigRectangle_h;
		break;
	case Shape::C:
		svg_w = bigCircle_r * 2;
		svg_h = bigCircle_r * 2;
		break;
	case Shape::T:
		svg_w = bigTriangle_e;
		svg_h = (int) (bigTriangle_e / 2) * (sqrt(3));
		break;
	}
	drawBigShape();
}

//ask for width and height of rectangle
void askRectangleSize(bool isBigShape) {
	int width;
	int height;
	cout << "Enter width of rectangle:\n";
	cin >> width;
	while (cin.fail() || width < 1) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout
				<< "Bad value! Please enter a positive integer value for width of rectangle: "
				<< endl;
		cin >> width;
	}
	cout << "Enter height of rectangle:\n";
	cin >> height;
	while (cin.fail() || height < 1) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout
				<< "Bad value! Please enter a positive integer value for height of rectangle: "
				<< endl;
		cin >> height;
	}
	if (isBigShape) {
		bigRectangle_w = width;
		bigRectangle_h = height;
	} else {
		rectangle_w = width;
		rectangle_h = height;
	}
}

//ask for radius length of circle
void askCircleSize(bool isBigShape) {
	int radius;
	cout << "Enter radius of circle:\n";
	cin >> radius;
	while (cin.fail() || radius < 1) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout
				<< "Bad value! Please enter a positive integer value for radius of circle: "
				<< endl;
		cin >> radius;
	}
	if (isBigShape) {
		bigCircle_r = radius;
	} else {
		circle_r = radius;
	}
}

//ask for edge length of equilateral triangle
void askTriangleSize(bool isBigShape) {
	int edge;
	cout << "Enter edge length of triangle:\n";
	cin >> edge;
	while (cin.fail() || edge < 1) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout
				<< "Bad value! Please enter a positive integer value for edge length of triangle: "
				<< endl;
		cin >> edge;
	}
	if (isBigShape) {
		bigTriangle_e = edge;
	} else {
		triangle_e = edge;
	}
}
void assignShapeType(bool isBigShape, string input) {
	Shape shape;
	if (input == "R" || input == "r") {
		shape = Shape::R;
	} else if (input == "C" || input == "c") {
		shape = Shape::C;
	} else if (input == "T" || input == "t") {
		shape = Shape::T;
	} else {
		cout << "Incorrect input! Try again..." << endl;
		isBigShape ? askBigShape() : askSmallShapes();
		return;
	}
	if (isBigShape) {
		bigShapeType = shape;
	} else {
		smallShapesType = shape;
	}
}

// ask what is the type of small shapes and their sizes
void askSmallShapes() {
	string smallShape = "";
	cout
			<< "Please enter the type of shape include your container shape (R, C, T):\n";
	cin >> smallShape;
	assignShapeType(false, smallShape);

	switch (smallShapesType) {
	case Shape::R:
		askRectangleSize(false);
		if (calculateRectangleArea(false) > bigShapeArea) {
			cout << "This area must be smaller than first one!" << endl;
			cout << "calculateRectangleArea(false): "
					<< calculateRectangleArea(false) << " bigShapeArea: "
					<< bigShapeArea << endl;
			rectangle_w = 0;
			rectangle_h = 0;
			rectangleArea = 0.0;
			askSmallShapes();
		}
		break;
	case Shape::C:
		askCircleSize(false);
		if (calculateCircleArea(false) > bigShapeArea) {
			cout << "This area must be smaller than first one!" << endl;
			circle_r = 0;
			circleArea = 0.0;
			askSmallShapes();
		}
		break;
	case Shape::T:
		askTriangleSize(false);
		calculateTriangleArea(false);
		if (calculateTriangleArea(false) > bigShapeArea) {
			cout << "This area must be smaller than first one!" << endl;
			triangle_e = 0;
			triangleArea = 0.0;
			askSmallShapes();
		}
		break;
	}
	drawSmallShapes(bigShapeType, smallShapesType);
}

// ask what is the type of the big shape and its sizes
void askBigShape() {
	string mainShape;
	cout << "Please enter the main container shape (R, C, T):\n";
	cin >> mainShape;
	assignShapeType(true, mainShape);
	double area = 0.0;

	switch (bigShapeType) {
	case Shape::R:
		askRectangleSize(true);
		area = calculateRectangleArea(true);
		break;
	case Shape::C:
		askCircleSize(true);
		area = calculateCircleArea(true);
		break;
	case Shape::T:
		askTriangleSize(true);
		area = calculateTriangleArea(true);
		break;
	}
	bigShapeArea = area;
	calculateSvgSize();
	askSmallShapes();
}

int main() {

	Rectangle awesome(50, 50);
	Triangle littleAwesome(6);
	Circle circle(10);

	Polygon a = Rectangle (10,10);

	askBigShape();
	/*
	 cout<< "Drawing svg to canvas width: "<< svg_w << " svg height: " << svg_h <<endl;

	 cout<<"big rectangle: " << bigRectangle_x << ", " << bigRectangle_y << ", " << bigRectangle_w <<", " << bigRectangle_h << "\n"
	 << "big circle: " << bigCircle_x << ", " << bigCircle_y << ", " << bigCircle_r  << "\n"
	 << "big triangle: (" << bigTriangle_x1 << ", " << bigTriangle_y1 << "), ("
	 << bigTriangle_x2 <<", " << bigTriangle_y2 << "), (" << bigTriangle_x3 <<", " << bigTriangle_y3 << ")\n \n"
	 << "rectangle: " << rectangle_x << ", " << rectangle_y << ", " << rectangle_w <<", " << rectangle_h << "\n"
	 << "circle: " << circle_x << ", " << circle_y << ", " << circle_r  << "\n"
	 << "triangle: (" << triangle_x1 << ", " << triangle_y1 << "), ("
	 << triangle_x2 <<", " << triangle_y2 << "), (" << triangle_x3 <<", " << triangle_y3 << ")\n \n"
	 << "rectangle area: " << rectangleArea << " - big rectangle area: " << bigRectangleArea << "\n"
	 << "circle area: " << circleArea << " - big circle area: " << bigCircleArea << "\n"
	 << "triangle area: " << triangleArea << " - big triangle area: " << bigTriangleArea << "\n"
	 << "svg height: " << svg_h << " - svg width: " << bigTriangleArea << "\n"
	 << endl;

	 double remainedArea = bigShapeArea - (quantityOfSmallShapes*smallShapeArea);
	 cout << "I can fit at most " << quantityOfSmallShapes << " small shapes into the main container. "
	 << "The empty area (blue) in container is " <<  remainedArea << endl;*/

	return 0;
}
