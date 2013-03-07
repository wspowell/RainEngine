// sprite



#ifndef RAIN_SPRITE_H
#define RAIN_SPRITE_H

// Include GLEW. Always include it before gl.h and glfw.h, since it's a bit magic.
#include <GL/glew.h>
// glfw includes gl.h and glu.h
#include <GL/glfw.h>
#include "rain_types.h"

class Sprite {
	private:
		GLfloat xOffset;
		GLfloat yOffset;
		uint width; 
		uint height;
		GLfloat widthScaled;
		GLfloat	heightScaled;
		uint textureID;
	public:
		Sprite(GLfloat x, GLfloat y, uint w, uint h, GLfloat ws, GLfloat hs,  uint texID);
		~Sprite();
		GLfloat getXOffset();
		GLfloat getYOffset();
		uint getWidth();
		uint getHeight();
		GLfloat getWidthScaled();
		GLfloat getHeightScaled();
		uint getTextureID();
};


#endif

