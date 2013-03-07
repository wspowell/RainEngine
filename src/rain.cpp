// rain engine

#include "rain_engine.h"

// test the engine
int main(int argc, char** argv)
{
	// initialize the engine	
	RainEngine rain;

	// width, height, mode, AA
	rain.initWindow(960,960,0,1); //480

	// open the window, stop if it fails
	if(!rain.openWindow()) {
		fprintf( stderr, "Failed to initialize Rain Engine.\n" );
		return -1;
	}
	
	// create textures
	uint tileset = rain.createTexture("data/textures/tileset3.bmp");
	//uint grass1 = rain.createTexture("data/textures/grass1.bmp");
	//uint grass2 = rain.createTexture("data/textures/grass2.bmp");

	// use textures to create sprites
	uint character = rain.createSprite(0,32,64,64,tileset);

	// use textures to create tiles
	//uint grass = rain.createTile(0,0,30,30,tileset);
	uint grass1 = rain.createTile(0,0,32,32,tileset);
	uint grass2 = rain.createTile(32,0,32,32,tileset);
	
	// create a scene of r rows and c columns using tilesize s
	uint forest = rain.createScene(25,25,32); // 800x800px

	// load tiles into a scene at a specific col,row
	// initialize random seed
  	srand (time(NULL));
	
	for(uint r = 0; r < 60; ++r) {
		for(uint c = 0; c < 34; ++c) { //rain.getCols(forest)
			uint rnum = rand()%10+1;
			uint tile;
			if(rnum <= 7) { tile = grass1; }
			else { tile = grass2; }
			rain.addTile(forest,tile,r,c); // make the whole scene full of grass
		}
	}
	
	// load sprites into a scene
	rain.addSprite(forest,character);

	// bind controls to sprite, only one sprite is controllable at a time
	//rain.bindControl(character);
	
	// put the sprite in the middle of the scene
	// sprites in the scene are positioned by their center
	//rain.setSprite(forest,character,200,200);

	// Use our shader
	//glUseProgram(programID);

	while(rain.running()) {
		//rain.updateSprite(x,w,h);
		rain.renderScene(forest); // render forest
		//rain.updatePosition(character,1,1); // move character by an offset of +1x,+1y		
	}
	
	return 0;
}














// Draw
		//rain.drawTriangle();
		//rain.renderSprite(1);

		//for(int x = 0; x < 10; x++) {
			//rain.renderSprite(x);
		//}

		//glBindTexture (GL_TEXTURE_2D, 0);
		


//rain.initRenderer(); // do this right after the window has been created

	//rain.createTriangle();

	// load textures
	//string filename = "null_texture.bmp";
	//if(!rain.loadTexture(filename)) {
	//	fprintf(stderr, "Failed to load texture %s\n",filename.c_str());
	//}

	//Texture *tex = new Texture(0);
	//if(!tex->loadBMP(filename)) {
	//	fprintf(stderr, "Failed to load texture %s\n",filename.c_str());
	//}
	//tex->loadTexture();
	//GLuint programID = tex->loadShaders( "shaders/vertexshader.vertexshader", "shaders/fragmentshader.fragmentshader" );

	// create sprites
	//srand (time(NULL));
	//Sprite *spr1 = new Sprite(rain.getWindow(),0,rand()%500,rand()%500,30,30,0);
	//Sprite *spr2 = new Sprite(rain.getWindow(),0,rand()%500,rand()%500,30,30,0);
	
	
	/* initialize random seed: */
  	//srand (time(NULL));
	//for(int x = 0; x < 10; x++) {
		//rain.createSprite(rand()%500,rand()%500,30,30,0);
	//}

	//rain.createSprite(0,0,30,30,0);
	//rain.createSprite(400,400,30,30,0);

	
