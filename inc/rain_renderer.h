// rain engine
// Author: Wesley Powell
// Feb 2013
// deals with sprites and sprite sheets, general images

#include <stdio.h>
#include <stdlib.h>
// Include GLEW. Always include it before gl.h and glfw.h, since it's a bit magic.
#include <GL/glew.h>
// glfw includes gl.h and glu.h
#include <GL/glfw.h>
#include <glm/glm.hpp>
#include "types.h"


class Renderer {
	private:
		// This will identify our vertex buffer
		GLuint vertexbuffer;
	public:
		Renderer();
		~Renderer();
		void init();
		void loadTriangle(); // load the triangle data in vertexbuffer into OpenGL memory;
		void drawTriangle();
};

