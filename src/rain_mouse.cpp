// mouse


#include "rain_mouse.h"


float RAIN_WINDOW_X_CENTER;
float RAIN_WINDOW_Y_CENTER;
float RAIN_MOUSE_X_POS;
float RAIN_MOUSE_Y_POS;
float RAIN_MOUSE_X_OFFSET;
float RAIN_MOUSE_Y_OFFSET;
void updateMouseOnMove(int x, int y) {
	// get the mouse offset
	RAIN_MOUSE_X_OFFSET = RAIN_MOUSE_X_POS - RAIN_WINDOW_X_CENTER;
	RAIN_MOUSE_Y_OFFSET = RAIN_MOUSE_Y_POS - RAIN_WINDOW_Y_CENTER;

	// store the mouse position
	RAIN_MOUSE_X_POS = x;
	RAIN_MOUSE_Y_POS = y;

	// Reset mouse position for next frame
	glfwSetMousePos(RAIN_WINDOW_X_CENTER, RAIN_WINDOW_Y_CENTER); // remember to update this when the window resizes
}

Mouse::Mouse() : mouseSpeed(1) { 
	printf("Initializing mouse...\n");
}

Mouse::~Mouse() { }

void Mouse::init() { 
	//glfwDisable( GLFW_MOUSE_CURSOR );
	glfwSetMousePosCallback((GLFWwindowsizefun)updateMouseOnMove);
	
	// disable the mouse cursor
	glfwDisable( GLFW_MOUSE_CURSOR );

	// set the mouse position to the center of the screen
	// movement is based on the offset moved from the center
	int width, height;
	glfwGetWindowSize(&width, &height);
	glfwSetMousePos(width/2, height/2);
	RAIN_WINDOW_X_CENTER = width/2;
	RAIN_WINDOW_Y_CENTER = height/2;
	RAIN_MOUSE_X_POS = RAIN_WINDOW_X_CENTER;
	RAIN_MOUSE_Y_POS = RAIN_WINDOW_Y_CENTER;
	RAIN_MOUSE_X_OFFSET = 0;
	RAIN_MOUSE_Y_OFFSET = 0;
}

float Mouse::getXOffset() {
	float offset = RAIN_MOUSE_X_OFFSET * mouseSpeed;
	RAIN_MOUSE_X_OFFSET = 0;
	return offset;
}

float Mouse::getYOffset() {
	float offset = RAIN_MOUSE_Y_OFFSET * mouseSpeed;
	RAIN_MOUSE_Y_OFFSET = 0;
	return offset;
}


