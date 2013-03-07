// tile


#include "rain_tile.h"


Tile::Tile(GLfloat x, GLfloat y, uint w, uint h, GLfloat ws, GLfloat hs, uint texID) : xOffset(x), yOffset(y), width(w), height(h), widthScaled(ws), heightScaled(hs), textureID(texID) { }

Tile::~Tile() { }

GLfloat Tile::getXOffset() {
	return xOffset;
}

GLfloat Tile::getYOffset() {
	return yOffset;
}

uint Tile::getWidth() {
	return width;
}

uint Tile::getHeight() {
	return height;
}

GLfloat Tile::getWidthScaled() {
	return widthScaled;
}

GLfloat Tile::getHeightScaled() {
	return heightScaled;
}

uint Tile::getTextureID() {
	return textureID;
}