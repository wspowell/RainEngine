// sprite

#include "rain_sprite.h"

Sprite::Sprite(GLfloat x, GLfloat y, uint w, uint h, GLfloat ws, GLfloat hs, uint texID) : xOffset(x), yOffset(y), width(w), height(h), widthScaled(ws), heightScaled(hs), textureID(texID) { }

Sprite::~Sprite() { }

GLfloat Sprite::getXOffset() {
	return xOffset;
}

GLfloat Sprite::getYOffset() {
	return yOffset;
}

uint Sprite::getWidth() {
	return width;
}

uint Sprite::getHeight() {
	return height;
}

GLfloat Sprite::getWidthScaled() {
	return widthScaled;
}

GLfloat Sprite::getHeightScaled() {
	return heightScaled;
}

uint Sprite::getTextureID() {
	return textureID;
}

