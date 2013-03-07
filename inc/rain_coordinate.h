// coordinate

#ifndef RAIN_COORDINATE_H
#define RAIN_COORDINATE_H

#include <map>
// Include GLEW. Always include it before gl.h and glfw.h, since it's a bit magic.
#include <GL/glew.h>
// glfw includes gl.h and glu.h
#include <GL/glfw.h>
#include "rain_sprite.h"
#include "rain_types.h"

class Coordinate {
	private:	
		GLfloat xLoc;
		GLfloat yLoc;
		GLfloat xLocScaled;
		GLfloat yLocScaled;
	public:
		Coordinate(GLfloat x, GLfloat y);
		~Coordinate();
		GLfloat getX();
		GLfloat getY();
		GLfloat getXScaled();
		GLfloat getYScaled();
		void setX(GLfloat x);
		void setY(GLfloat y);		
		bool operator < (Coordinate &other);
};

// keeps track of sprite locations, this is so that sprites can be reused in multiple scenes
// key is the spriteID, value is the Coordinate the sprite is at
typedef std::map<uint,Coordinate*> coordinateMap;
typedef coordinateMap::value_type coordinateValType;
typedef coordinateMap::iterator coordinateMapItor;

// keeps track of sprite locations, this is so that sprites can be reused in multiple scenes
// key is the spriteID, value is the Coordinate the sprite is at
typedef std::map<Coordinate*,uint> coordinateTileMap;
typedef coordinateTileMap::value_type coordinateTileValType;
typedef coordinateTileMap::iterator coordinateTileMapItor;

#endif

