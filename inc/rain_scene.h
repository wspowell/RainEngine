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
		void setX(uint x);
		void setY(uint y);
};

// keeps track of sprite locations, this is so that sprites can be reused in multiple scenes
// key is the spriteID, value is the Coordinate the sprite is at
typedef std::map<uint,Coordinate*> coordinateMap;
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
		void setCol(uint c);
		void setRow(uint r);
};

// keeps track of tile locations, this is so that tiles can be reused in multiple scenes
// key is the tileID, value is the Location the tile is at 
typedef std::map<uint,Location*> locationMap;
typedef locationMap::value_type locationValType;
typedef locationMap::iterator locationMapItor;

class Scene {
	private:
		uint cols;
		uint rows;
		uintVector sprites; // the sprites in this scene
		coordinateMap spriteCoords; // coordinates of sprites
		uintVector tiles; // tiles
		locationMap tileLocs; // locations of tiles
	public:
		Scene(uint w, uint h);
		~Scene();

		int hasSprite(uint spriteID);
		void addSprite(uint spriteID);
		void removeSprite(uint spriteID);
		void moveSprite(uint spriteID, uint x, uint y);
		void setSprite(uint spriteID, uint x, uint y);
		uintVector getSprites();

		int hasTile(uint tileID);
		void addTile(uint tileID);
		void removeTile(uint tileID);
		void moveTile(uint tileID, uint c, uint r);
		void setTile(uint tileID, uint c, uint r);
		uintVector getTiles();
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

