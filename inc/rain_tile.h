// tile
// a tile is a static sprite, it may have an animation state but it does not move
// in essence, a tile is the background (not an enemy, character, or moving object)


#include "rain_types.h"

class Tile {
	private:
		uint size; // how big the tile is, it is square so x=y
		uint offset; // an offset, if needed, to the top left corner of the tile, 0 is default (ex, a tree tile)
		// TODO: needs x and y offset 
		uint textureID;
	public:
		Tile(uint s, uint o, uint t);
		~Tile();
		uint getSize();
		uint getOffset();
		uint getTextureID();
};
