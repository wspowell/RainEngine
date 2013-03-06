// sprite

#include "rain_sprite.h"

Sprite::Sprite(uint x, uint y, uint w, uint h, uint texID) : xOffset(x), yOffset(y), width(w), height(h), textureID(texID) { }

Sprite::~Sprite() { }

uint Sprite::getXOffset() {
	return xOffset;
}

uint Sprite::getYOffset() {
	return yOffset;
}

uint Sprite::getWidth() {
	return width;
}

uint Sprite::getHeight() {
	return height;
}

uint Sprite::getTextureID() {
	return textureID;
}


