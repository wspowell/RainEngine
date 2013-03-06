// tile


#include "rain_tile.h"


Tile::Tile(uint x, uint y, uint h, uint w, uint t) : xOffset(x), yOffset(y), height(h), width(w), textureID(t) { }

Tile::~Tile() { }

uint Tile::getXOffset() {
	return xOffset;
}

uint Tile::getYOffset() {
	return yOffset;
}

uint Tile::getWidth() {
	return width;
}

uint Tile::getHeight() {
	return height;
}

uint Tile::getTextureID() {
	return textureID;
}