// sprite



#ifndef RAIN_SPRITE_H
#define RAIN_SPRITE_H

#include "rain_types.h"

class Sprite {
	private:
		float width;
		float height;
		uint textureID;
	public:
		Sprite(float w, float h, uint texID);
		~Sprite();
		uint getWidth();
		uint getHeight();
		uint getTextureID();
};


#endif

