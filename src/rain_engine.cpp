// rain engine

#include "rain_engine.h"


RainEngine::RainEngine() : sceneID(0), spriteID(0), tileID(0), textureID(0) { 
	printf("Initializing engine...\n");
}
RainEngine::~RainEngine() { }

bool RainEngine::running() {
	bool isRunning = true;

	// Swap buffers (BEFORE CLEAR!)
	glfwSwapBuffers();
	
	// clear the screen
	// GL_COLOR_BUFFER_BIT: Indicates the buffers currently enabled for color writing.
	// GL_DEPTH_BUFFER_BIT: Indicates the depth buffer.
	// GL_STENCIL_BUFFER_BIT: Indicates the stencil buffer.
	glClear(GL_COLOR_BUFFER_BIT);

	double framerate = getFrameRate();
	if(framerate != -1) {
		printf("%f ms/frame\n",framerate);
	}

	// Check if the ESC key was pressed or the window was closed
	if( glfwGetKey( GLFW_KEY_ESC ) == GLFW_PRESS || !glfwGetWindowParam( GLFW_OPENED ) ) {
		printf("Closing window on key (%u)\n",GLFW_KEY_ESC);
		isRunning = false;
	}

	return isRunning;
}


// Window
void RainEngine::initWindow(uint w, uint h, uint m, uint a) {
	win.init(w,h,m,a);
}

bool RainEngine::openWindow() {
	bool result = win.open(); 
	mse.init();
	return result;
}

double RainEngine::getFrameRate() { return win.getFrameRate(); }
uint RainEngine::getWindowWidth() { return win.getWidth(); }
uint RainEngine::getWindowHeight() { return win.getHeight(); }


uint RainEngine::createTexture(string filename) {
	Texture *tex = new Texture();
	// check to see if the texture exists, use the existing one if possible
	for(textureMapItor itor = textures.begin(); itor != textures.end(); ++itor) {
		if((*itor).second->getFilename() == filename) {
			textureID = (*itor).first; // return the id, this is not the OpenGL textureID
			return textureID;
		}
	}

	// create a new texture
	if(!tex->createTexture(filename)) {
		textureID = 0; // 0 is the null texture
		fprintf(stdout, "Using null texture\n");
	} else {
		tex->loadTexture(); // load texture into OpenGL
		++textureID; // increment the id
		textures.insert(textureValType(textureID,tex)); // add texture to the map
	}

	return textureID;
}
 
uint RainEngine::createSprite(uint xOffset, uint yOffset, uint w, uint h, uint texID) {
	Texture *tex = getTexture(textureID);
	uint texH = tex->getHeight();
	uint texW = tex->getWidth();
	// the '-1' in the next line is to offset the sprite to screen coordinate (0,0). (*2 because its TWO across)
	Sprite *spr = new Sprite((GLfloat)xOffset/texW,(GLfloat)yOffset/texH,w,h,((GLfloat)w/win.getWidth())*2,((GLfloat)h/win.getHeight())*2,texID); // setup the sprite
	++spriteID; // the spriteID is the next number in the series
	sprites.insert(spriteValType(spriteID,spr)); // add sprite to the map
	printf("Created sprite (id:%u) width %u height %u with texture (id:%u)@(%u,%u)\n",spriteID,w,h,texID,xOffset,yOffset);
	return spriteID;
}
  
uint RainEngine::createTile(uint xOffset, uint yOffset, uint width, uint height, uint textureID) {
	Texture *tex = getTexture(textureID);
	uint texH = tex->getHeight();
	uint texW = tex->getWidth();
	Tile *tl = new Tile((GLfloat)xOffset/texW,(GLfloat)yOffset/texH,width,height,((GLfloat)width/win.getWidth())*2,((GLfloat)height/win.getHeight())*2,textureID);
	++tileID;
	tiles.insert(tileValType(tileID,tl));
	printf("Created tile (id:%u)\n",tileID);
	return tileID;
}

void RainEngine::addTile(uint scnID, uint tlID, uint row, uint col) {
	Scene *scn = getScene(scnID);
	// add sprite to the scene
	scn->addTile(tlID,row,col);
	printf("Added tile (id:%u) to scene (id:%u) @ grid(%u,%u)\n",tlID,scnID,row,col); 
}

uint RainEngine::createScene(uint rows, uint columns, uint tilesize) {
	Scene *scn = new Scene(rows,columns,((GLfloat)tilesize/win.getWidth())*2);
	++sceneID;
	scenes.insert(sceneValType(sceneID,scn));
	printf("Created scene (id:%u)\n",sceneID);
	return sceneID;
}

void RainEngine::addSprite(uint scnID, uint sprID) {
	Scene *scn = getScene(scnID);
	scn->addSprite(sprID);
	printf("Added sprite (id:%u) to scene (id:%u)\n",sprID,scnID);
}

Texture* RainEngine::getTexture(uint texID) {
	textureMapItor texPos = textures.find(texID);
	if(texPos == textures.end()) {
		fprintf(stderr, "Could not find texture (id:%u)\n",texID);
		return NULL;
	}
	return (*texPos).second;
}

Scene* RainEngine::getScene(uint scnID) {
	sceneMapItor scnPos = scenes.find(scnID);
	if(scnPos == scenes.end()) {
		fprintf(stderr, "Could not find scene (id:%u)\n",scnID);
		return NULL;
	}
	return (*scnPos).second;
}

Sprite* RainEngine::getSprite(uint sprID) {
	spriteMapItor sprPos = sprites.find(sprID);
	if(sprPos == sprites.end()) {
		fprintf(stderr, "Could not find sprite (id:%u)\n",sprID);
		return NULL;
	}
	return (*sprPos).second; 
}

void RainEngine::setSprite(uint scnID, uint sprID, uint x, uint y) {
	Scene *scn = getScene(scnID);
	scn->setSprite(sprID,x,y);
}

void RainEngine::moveSprite(uint scnID, uint sprID, int x, int y) {
	Scene *scn = getScene(scnID);
	scn->moveSprite(sprID,x,y);
}

Tile* RainEngine::getTile(uint tlID) {
	tileMapItor tlPos = tiles.find(tlID);
	if(tlPos == tiles.end()) {
		fprintf(stderr, "Could not find tile (id:%u)\n",tlID);
		return NULL;
	}
	return (*tlPos).second; 
}

uint RainEngine::getRows(uint scnID) {
	Scene *scn = getScene(scnID);
	return scn->getRows();
}

uint RainEngine::getCols(uint scnID) {
	Scene *scn = getScene(scnID);
	return scn->getCols();
}

uint RainEngine::getWidth(uint scnID) {
	Scene *scn = getScene(scnID);
	return scn->getWidth();
}

uint RainEngine::getHeight(uint scnID) {
	Scene *scn = getScene(scnID);
	return scn->getHeight();
}



void RainEngine::renderScene(uint scnID) {
	// render each spriteID in the Scene
	Scene *scn = getScene(scnID);
	if(scn == NULL) { 
		fprintf(stderr, "Could not render scene (id:%u)\n",scnID);
		return; 
	}

	coordinateTileMap tileCoords = scn->getTileCoords();
	for(coordinateTileMapItor itor = tileCoords.begin(); itor != tileCoords.end(); ++itor) {
		// render tiles as quads
		uint tlID = (*itor).second;
		Tile *tl = getTile(tlID);
		GLfloat w = tl->getWidthScaled();
		GLfloat h = tl->getHeightScaled();
		uint texID = tl->getTextureID();
		
		Texture *tex = getTexture(texID);
		GLfloat tw = (GLfloat)tl->getWidth()/tex->getWidth();
		GLfloat th = (GLfloat)tl->getHeight()/tex->getHeight();
		GLfloat tileXoffset = tl->getXOffset();
		GLfloat tileYoffset = tl->getYOffset();
		
		GLfloat x = (*itor).first->getX(); // get tile coordinate
		GLfloat y = (*itor).first->getY();

		renderQuad(x,y,w,h,tileXoffset,tileYoffset,tw,th,texID);
	}
	
	coordinateMap spriteCoords = scn->getSpriteCoords();
	for(coordinateMapItor itor = spriteCoords.begin(); itor != spriteCoords.end(); ++itor) {
		// render sprites as quads
		uint sprID = (*itor).first;
		Sprite *spr = getSprite(sprID);
		GLfloat w = spr->getWidthScaled();
		GLfloat h = spr->getHeightScaled();
		uint texID = spr->getTextureID();

		Texture *tex = getTexture(texID);
		GLfloat tw = (GLfloat)spr->getWidth()/tex->getWidth();
		GLfloat th = (GLfloat)spr->getHeight()/tex->getHeight();
		GLfloat spriteXoffset = spr->getXOffset();
		GLfloat spriteYoffset = spr->getYOffset();
		
		GLfloat x = (*itor).second->getXScaled(); // find x,y coordinate scaled to opengl
		GLfloat y = (*itor).second->getYScaled();

		renderQuad(x,y,w,h,spriteXoffset,spriteYoffset,tw,th,texID);
	}
}

void RainEngine::renderQuad(GLfloat x, GLfloat y, GLfloat w, GLfloat h, GLfloat xOffset, GLfloat yOffset, GLfloat tWidth, GLfloat tHeight, uint texID) {
	//printf("Rendering Quad @ (%f,%f) with dimensions (%f,%f) and texture (id:%u) @ (%f,%f) with dimensions (%f,%f)\n",x,y,w,h,texID,xOffset,yOffset,tWidth,tHeight);

	// bind the proper texture (check to see if it has already been bound?)
	Texture *tex = getTexture(texID);
	tex->loadTexture();
	
	// draw the quad
	glBegin (GL_QUADS);
	glTexCoord2f (xOffset, yOffset);
	glVertex2f (x, y);
	glTexCoord2f (xOffset+tWidth, yOffset);
	glVertex2f (x+w, y);
	glTexCoord2f (xOffset+tWidth, yOffset+tHeight);
	glVertex2f (x+w, y-h);
	glTexCoord2f (xOffset, yOffset+tHeight);
	glVertex2f (x, y-h);
	glEnd ();
}

void RainEngine::updateMouse() {
	//mse.update();
}

float RainEngine::getMouseXOffset() {
	return mse.getXOffset();
}

float RainEngine::getMouseYOffset() {
	return mse.getYOffset();
}

void RainEngine::updateSprite(uint sprID, uint x, uint y) {
	//Sprite *spr = getSprite(sprID);

	//float newX = spr->getX()+x;
	//float newY = spr->getY()+y;
	//spr->setX(newX);
	//spr->setY(newY);
}















