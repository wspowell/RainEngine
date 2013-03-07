// coordinate

#include "rain_coordinate.h"

Coordinate::Coordinate(GLfloat x, GLfloat y) : xLoc(x), yLoc(y) { 
	int width, height;
	setX(x);
	setY(y);
}

Coordinate::~Coordinate() { }
GLfloat Coordinate::getX() { return xLoc; }
GLfloat Coordinate::getY() { return yLoc; }
GLfloat Coordinate::getXScaled() { return xLocScaled; }
GLfloat Coordinate::getYScaled() { return yLocScaled; }

void Coordinate::setX(GLfloat x) { 
	xLoc = x; 
	int width, height;
	glfwGetWindowSize(&width, &height);
	xLocScaled = ((GLfloat)x/(GLfloat)width)*2-1; // top left x
}

void Coordinate::setY(GLfloat y) { 
	yLoc = y; 
	int width, height;
	glfwGetWindowSize(&width, &height);
	yLocScaled = 1-(((GLfloat)y)/(GLfloat)height)*2; // top left y
}

bool Coordinate::operator < (Coordinate &other) {
	if(xLoc < other.getX()) { return true; }
    if(xLoc > other.getX()) { return false; }
    return (yLoc < other.getY()) ;
}

