// rain engine

#include "rain_engine.h"

// test the engine
int main(int argc, char** argv)
{
	// initialize the engine	
	RainEngine rain;

	// width, height, mode, AA
	rain.initWindow(500,500,0,1);

	// open the window, stop if it fails
	if(!rain.openWindow()) {
		fprintf( stderr, "Failed to initialize Rain Engine.\n" );
		return -1;
	}
	
	// create textures
	uint tileset = rain.createTexture("data/textures/null_texture.bmp");

	// use textures to create sprites
	uint character = rain.createSprite(0,0,30,30,tileset);

	// use textures to create tiles
	//uint grass = rain.createTile(0,30,32,32,tileset);

	// create a scene of r rows and c columns using tilesize s
	uint forest = rain.createScene(25,25,32); // 800x800px, 1,1 is the first tile grid

	// load tiles into a scene at a specific col,row
	/*for(uint r = 0; r < rain.getRows(forest); ++r) {
		for(uint c = 0; c < rain.getCols(forest); ++c) {
			rain.addTile(forest,grass,r,c); // make the whole scene full of grass
		}
	}*/
	
	// load sprites into a scene
	rain.addSprite(forest,character);

	// bind controls to sprite, only one sprite is controllable at a time
	//rain.bindControl(character);
	
	// put the sprite in the middle of the scene
	// sprites in the scene are positioned by their center
	rain.setSprite(forest,character,rain.getWidth(forest)/2,rain.getHeight(forest)/2);

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

	
