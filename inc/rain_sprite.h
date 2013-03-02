// sprite



#ifndef RAIN_SPRITE_H
#define RAIN_SPRITE_H

#include "rain_types.h"

class Sprite {
	private:
		uint width;
		uint height;
		uint textureID;
	public:
		Sprite(uint w, uint h, uint texID);
		~Sprite();
		uint getWidth();
		uint getHeight();
		uint getTextureID();
};


#endif

