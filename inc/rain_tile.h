// tile
// a tile is a static sprite, it may have an animation state but it does not move
// in essence, a tile is the background (not an enemy, character, or moving object)


#include "rain_types.h"

class Tile {
	private:
		uint xOffset;
		uint yOffset;
		uint height;
		uint width;
		uint textureID;
	public:
		Tile(uint x, uint y, uint h, uint w, uint t);
		~Tile();
		uint getXOffset();
		uint getYOffset();
		uint getWidth();
		uint getHeight();
		uint getTextureID();
};
