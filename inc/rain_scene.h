// scene


#ifndef RAIN_SCENE_H
#define RAIN_SCENE_H

#include <vector>
#include <map>
#include <stdio.h>
#include "rain_types.h"

// for sprites
class Coordinate {
	private:
		uint xLoc;
		uint yLoc;
	public:
		Coordinate(uint x, uint y);
		~Coordinate();
		uint getX();
		uint getY();
};

// keeps track of sprite locations, this is so that sprites can be reused in multiple scenes
// key is the spriteID, value is the Coordinate the sprite is at
typedef map<uint,Coordinate> coordinateMap;
typedef coordinateMap::value_type coordinateValType;
typedef coordinateMap::iterator coordinateMapItor;

// for tiles
class Location {
	private:
		uint col;
		uint row;
	public:
		Location(uint c, uint r);
		~Location();
		uint getCol();
		uint getRow();
};

// keeps track of tile locations, this is so that tiles can be reused in multiple scenes
// key is the tileID, value is the Location the tile is at 
typedef map<uint,Location> locationMap;
typedef locationMap::value_type locationValType;
typedef locationMap::iterator locationMapItor;

class Scene {
	private:
		uint cols;
		uint rows;
		uintVector sprites; // the sprites in this scene
		uintVector tiles; // tiles 
	public:
		Scene(uint w, uint h);
		~Scene();
		void addSprite(uint spriteID);
		void removeSprite(uint spriteID);
		uintVector getSprites();
		void setBackground();
};


// NOTES:

// the scene tracks the locations of all of the tiles and sprites, this way tiles and sprites
// can be reused in other scenes without having to reset the locations of everything

// refit the sprite so that it uses the center instead of the corner

// tiles are referenced by the to left corner

// for a tree that is bigger than a tile, the tile is given an offset so that the program knows
// where the tile is meant to be centered at

// tiles need a flag to show that it is an object, this way they are loaded last (from top to bottom)
// so that they overlap properly





#endif

