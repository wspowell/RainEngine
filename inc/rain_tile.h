// tile
// a tile is a static sprite, it may have an animation state but it does not move
// in essence, a tile is the background (not an enemy, character, or moving object)

// Include GLEW. Always include it before gl.h and glfw.h, since it's a bit magic.
#include <GL/glew.h>
// glfw includes gl.h and glu.h
#include <GL/glfw.h>
#include "rain_types.h"

class Tile {
	private:
		GLfloat xOffset;
		GLfloat yOffset;
		uint width; 
		uint height;
		GLfloat widthScaled;
		GLfloat	heightScaled;
		uint textureID;
	public:
		Tile(GLfloat x, GLfloat y, uint w, uint h, GLfloat ws, GLfloat hs, uint texID);
		~Tile();
		GLfloat getXOffset();
		GLfloat getYOffset();
		uint getWidth();
		uint getHeight();
		GLfloat getWidthScaled();
		GLfloat getHeightScaled();
		uint getTextureID();
};
