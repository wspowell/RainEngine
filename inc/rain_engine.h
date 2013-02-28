// rain game engine
// Author: Wesley Powell
// Feb 2013

#ifndef RAIN_ENGINE_H
#define RAIN_ENGINE_H

#include <map>
#include "rain_window.h"
#include "rain_camera.h"
#include "rain_mouse.h"
#include "rain_sprite.h"
#include "rain_tile.h"
#include "rain_texture.h"
#include "rain_scene.h"

using namespace std;

typedef map<uint,Sprite*> spriteMap;
typedef spriteMap::value_type spriteValType;
typedef spriteMap::iterator spriteMapItor;
typedef map<uint,Tile*> tileMap;
typedef tileMap::value_type tileValType;
typedef tileMap::iterator tileMapItor;
typedef map<uint,Texture*> textureMap;
typedef textureMap::value_type textureValType;
typedef textureMap::iterator textureMapItor;
typedef map<uint,Scene*> sceneMap;
typedef sceneMap::value_type sceneValType;
typedef sceneMap::iterator sceneMapItor;

class RainEngine {
	private:
		Window win; 
		Camera cam;
		Mouse mse;
		sceneMap scenes; // scene pointers
		uint sceneID;
		spriteMap sprites; // sprite pointers
		uint spriteID; // running ID number of all sprites
		tileMap tiles; // tile pointers
		uint tileID; // running ID number of all tiles
		textureMap textures; // texture pointers
		uint textureID; // running ID number of all textures

		// helper function not exposed but used to aid functionality
		Window getWindow() { return win; }
		bool loadTexture(string filename);
		void renderSprite(uint id);

		Scene* getScene(uint scnID);
		Sprite* getSprite(uint sprID);

	public:
		RainEngine();
		~RainEngine();

		// Window
		bool openWindow();
		void setWindowTitle(const char* t);
		void setWindowSize(uint w, uint h);
		void setWindowMode(int m);
		void setWindowAA(uint a);
		double getWindowFrameRate();
		uint getWindowWidth();
		uint getWindowHeight();
		
		
		uint createTexture(string filename);
		uint createSprite(uint w, uint h, uint texID);
		uint createScene(uint w, uint h);
		void addSpriteToScene(uint sceneID, uint spriteID);
		void renderScene(uint sceneID);

		void updateMouse();
		float getMouseXOffset();
		float getMouseYOffset();
		void updateSprite(uint sprID, float x, float y);
};


#endif

