// sprite

#include "rain_sprite.h"

Sprite::Sprite(uint w, uint h, uint texID) : width(w), height(h), textureID(texID) { }

Sprite::~Sprite() { }

uint Sprite::getWidth() {
	return width;
}

uint Sprite::getHeight() {
	return height;
}

uint Sprite::getTextureID() {
	return textureID;
}


