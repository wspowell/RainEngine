// window

#ifndef RAIN_WINDOW_H
#define RAIN_WINDOW_H

#include <stdio.h>
#include <stdlib.h>
// Include GLEW. Always include it before gl.h and glfw.h, since it's a bit magic.
#include <GL/glew.h>
// glfw includes gl.h and glu.h
#include <GL/glfw.h>
#include <glm/glm.hpp>
#include "rain_types.h"


using namespace glm;
using namespace std;

class Window {
	private:
		const char* WINDOW_TITLE;
		uint WINDOW_HEIGHT;
		uint WINDOW_WIDTH;
		int WINDOW_MODE;
		uint ANTIALIASING;
		GLuint vaoID;
		static void GLFWCALL resize(int width, int height);
	public:
		Window();
		~Window();
		void init(uint w, uint h, uint m, uint a);
		bool open(); // when the window opens it uses values set by the 'set' functions
		void setTitle(const char* t);
		void setHeight(uint h);
		void setWidth(uint w);
		void setAntiAliasing(uint a);
		void setMode(int m);
		
		uint getHeight();
		uint getWidth();
		GLuint getVao();
		double getFrameRate();
};


#endif

