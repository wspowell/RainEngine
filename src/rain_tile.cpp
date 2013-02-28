// tile


#include "rain_tile.h"


Tile::Tile(uint s, uint o, uint t) : size(s), offset(o), textureID(t) { }
Tile::~Tile() { }
uint Tile::getSize() { return size; }
uint Tile::getOffset() { return offset; }
uint Tile::getTextureID() { return textureID; }

