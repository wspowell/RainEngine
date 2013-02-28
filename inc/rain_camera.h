// camera


#ifndef RAIN_CAMERA_H
#define RAIN_CAMERA_H


#include "rain_types.h"


class Camera {
	private:
		uint xPos; // center of camera
		uint yPos; // center of camera
	public:
		Camera();
		~Camera();
		void update(uint x, uint y);
		uint getX();
		uint getY();
};


#endif
