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
		void renderQuad(uint x, uint y, uint w, uint h, uint texID);
		
		Texture* getTexture(uint texID);
		Scene* getScene(uint sceneID);
		Sprite* getSprite(uint spriteID);
		Tile* getTile(uint tileID);

	public:
		RainEngine();
		~RainEngine();

		bool running();

		// Window
		void initWindow(uint width, uint height, uint mode, uint antialiasing);
		bool openWindow();
		double getFrameRate();
		uint getWindowWidth();
		uint getWindowHeight();
		

		// creating textures, sprites, scenes
		uint createTexture(string filename);
		uint createSprite(uint xOffset, uint yOffset, uint width, uint height, uint textureID);
		uint createTile(uint xOffset, uint yOffset, uint height, uint width, uint textureID);
		uint createScene(uint rows, uint columns, uint tilesize);

		// manage textures, sprites, scenes
		void addSprite(uint sceneID, uint spriteID);
		void bindControl(uint spriteID);
		void setSprite(uint sceneID, uint spriteID, uint xPosition, uint yPosition);
		void moveSprite(uint sceneID, uint spriteID, int xOffset, int yOffset);
		void addTile(uint sceneID, uint tileID, uint row, uint column);
		uint getRows(uint sceneID);
		uint getCols(uint sceneID);
		uint getWidth(uint sceneID);
		uint getHeight(uint sceneID);

		// controls
		

		// render
		void renderScene(uint sceneID);

		
		void updateMouse();
		float getMouseXOffset();
		float getMouseYOffset();
		void updateSprite(uint sprID, uint x, uint y);
};


#endif

