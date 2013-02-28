// texture

#ifndef RAIN_TEXTURE_H
#define RAIN_TEXTURE_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <vector>
// Include GLEW. Always include it before gl.h and glfw.h, since it's a bit magic.
#include <GL/glew.h>
// glfw includes gl.h and glu.h
#include <GL/glfw.h>
#include <glm/glm.hpp>
#include "rain_types.h"

using namespace std;

class Texture {
	private:
		GLuint textureID; // openGL texture id reference, opengl manages its own texture data, assigned by TextureManager
		uint height;
		uint width;
		string filename;
		unsigned char *data; // Actual RGB data

		unsigned char* loadBMP(string n);
	public:
		Texture();
		~Texture();
		bool createTexture(string fn);
		bool loadTexture();
		string getFilename();
		GLuint getTextureID();
		GLuint loadShaders(const char * vertex_file_path,const char * fragment_file_path);
		void render();
};

#endif

