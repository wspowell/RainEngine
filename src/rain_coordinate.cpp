// coordinate

#include "rain_coordinate.h"

Coordinate::Coordinate(uint x, uint y) : xLoc(x), yLoc(y) { }
Coordinate::~Coordinate() { }
uint Coordinate::getX() { return xLoc; }
uint Coordinate::getY() { return yLoc; }
void Coordinate::setX(uint x) { xLoc = x; }
void Coordinate::setY(uint y) { yLoc = y; }
