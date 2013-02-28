// mouse


#ifndef RAIN_MOUSE_H
#define RAIN_MOUSE_H

#include <stdio.h>
#include <stdlib.h>
#include <GL/glfw.h>

class Mouse {
	private:
		float xCenter;
		float yCenter;
		float mouseSpeed;
	public:
		Mouse();
		~Mouse();
		void init();
		float getXOffset();
		float getYOffset();
};





#endif
