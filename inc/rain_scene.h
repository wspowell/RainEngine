// scene


#ifndef RAIN_SCENE_H
#define RAIN_SCENE_H

#include <vector>
#include <map>
#include <stdio.h>
#include "rain_coordinate.h"
#include "rain_types.h"


 
class Scene {
	private:
		uint rows;
		uint cols;
		GLfloat tilesize;
		uintVector sprites; // the sprites in this scene
		coordinateMap spriteCoords; // coordinates of sprites
		uintVector tiles; // tiles
		coordinateTileMap tileCoords; // locations of tiles
	public:
		Scene(uint r, uint c, GLfloat t);
		~Scene();

		void addSprite(uint spriteID);
		void removeSprite(uint spriteID);
		void moveSprite(uint spriteID, GLfloat x, GLfloat y);
		void setSprite(uint spriteID, GLfloat x, GLfloat y);
		uintVector getSprites();
		coordinateMap getSpriteCoords();
		

		void addTile(uint tileID, uint r, uint c);
		void removeTile(uint tileID);
		uintVector getTiles();
		coordinateTileMap getTileCoords();

		uint getRows();
		uint getCols();
		GLfloat getWidth();
		GLfloat getHeight();
};


// NOTES:

// the scene tracks the locations of all of the tiles and sprites, this way tiles and sprites
// can be reused in other scenes without having to reset the locations of everything

// refit the sprite so that it uses the center instead of the corner

// tiles are referenced by the to left corner and are placed in a (row,col) bin on the grid

// for a tree that is bigger than a tile, the tile is given an offset so that the program knows
// where the tile is meant to be centered at. the part the is oversized just overlays other tiles

// check if tile is 'oversized' (bigger x or y than the tilesize),these are 
// loaded last (from top to bottom) so that they overlap properly





#endif

