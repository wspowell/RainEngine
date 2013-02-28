// sprite

#include "rain_sprite.h"

Sprite::Sprite(float w, float h, uint texID) : width(w), height(h), textureID(texID) { }

Sprite::~Sprite() { }

float Sprite::getWidth() {
	return width;
}

float Sprite::getHeight() {
	return height;
}

uint Sprite::getTextureID() {
	return textureID;
}


