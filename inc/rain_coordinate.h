// coordinate

#ifndef RAIN_COORDINATE_H
#define RAIN_COORDINATE_H

#include <map>
#include "rain_sprite.h"
#include "rain_types.h"

class Coordinate {
	private:	
		uint xLoc;
		uint yLoc;
	public:
		Coordinate(uint x, uint y);
		~Coordinate();
		uint getX();
		uint getY();
		void setX(uint x);
		void setY(uint y);
};

// keeps track of sprite locations, this is so that sprites can be reused in multiple scenes
// key is the spriteID, value is the Coordinate the sprite is at
typedef std::map<uint,Coordinate*> coordinateMap;
typedef coordinateMap::value_type coordinateValType;
typedef coordinateMap::iterator coordinateMapItor;

#endif