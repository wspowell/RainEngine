// camera

#include "rain_camera.h"


Camera::Camera() : xPos(0), yPos(0) { }

Camera::~Camera() { }

void Camera::update(uint x, uint y) { 
	xPos = x;
	yPos = y;
}

uint Camera::getX() {
	return xPos;
}

uint Camera::getY() {
	return yPos;
}
