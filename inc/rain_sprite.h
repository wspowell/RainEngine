// sprite



#ifndef RAIN_SPRITE_H
#define RAIN_SPRITE_H

#include "rain_types.h"

class Sprite {
	private:
		uint xOffset;
		uint yOffset;
		uint width;
		uint height;
		uint textureID;
	public:
		Sprite(uint x, uint y, uint w, uint h, uint texID);
		~Sprite();
		uint getXOffset();
		uint getYOffset();
		uint getWidth();
		uint getHeight();
		uint getTextureID();
};


#endif

