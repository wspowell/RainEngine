// rain engine

#include "rain_engine.h"

int main(int argc, char** argv)
{
    // test the gfx engine
	RainEngine rain;

	uint sceneX = 500;
	uint sceneY = 500;

	rain.setWindowSize(sceneX,sceneY);
	rain.setWindowMode(1);
	rain.setWindowAA(1);

	if(!rain.openWindow()) {
		fprintf( stderr, "Failed to initialize Rain Engine.\n" );
	}   

	// create textures
	uint null_texture = rain.createTexture("forest.bmp");

	// use textures to create sprites
	uint character = rain.createSprite(800,800,null_texture);

	int num = 100;
/*
	srand(time(NULL));
	for(int x = 1; x <= num; x++) {
		int w = rand()%rain.getWindowWidth();
		int h = rand()%rain.getWindowHeight();
		rain.createSprite(w,h,30,30,null_texture);
	}*/

	// create a scene
	uint forest = rain.createScene(800,800);

	// load sprites into a scene/
	rain.addSpriteToScene(forest,character);
	/*for(int x = 1; x <= num; x++) {
		rain.addSpriteToScene(forest,x);
	}*/
	// Ensure we can capture the escape key being pressed below
	glfwEnable( GLFW_STICKY_KEYS );

	// Use our shader
	//glUseProgram(programID);

	do {
		// clear the screen
		// GL_COLOR_BUFFER_BIT: Indicates the buffers currently enabled for color writing.
		// GL_DEPTH_BUFFER_BIT: Indicates the depth buffer.
		// GL_STENCIL_BUFFER_BIT: Indicates the stencil buffer.
		glClear(GL_COLOR_BUFFER_BIT);

		double framerate = rain.getWindowFrameRate();
		if(framerate != -1) {
			printf("%f ms/frame\n",framerate);
		}
		
/*
		//float r3 = LO + (float)rand()/((float)RAND_MAX/(HI-LO));
		float LO = 0;
		float HI = 1;
		//rain.updateMouse();
		//rain.updateSprite(character,rain.getMouseXOffset(),rain.getMouseYOffset());
		srand(time(NULL));
		float rx,ry,w,h;
		for(int x = 1; x <= num; x++) {
			rx = rand()%100;
			ry = rand()%100;
			w = LO + (float)rand()/((float)RAND_MAX/(HI-LO));
			h = LO + (float)rand()/((float)RAND_MAX/(HI-LO));
			if(rx < 50) { w = w*(-1); }
			if(ry < 50) { h = h*(-1); }
			rain.updateSprite(x,w,h);
		}*/
		
		rain.renderScene(forest); // render forest


		//rain.updatePosition(character,1,1); // move character by an offset of +1x,+1y

		//shrubery->render();
		//character->render();	 
		

		// Swap buffers
		glfwSwapBuffers();
	 
	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey( GLFW_KEY_ESC ) != GLFW_PRESS && glfwGetWindowParam( GLFW_OPENED ) );

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

	
