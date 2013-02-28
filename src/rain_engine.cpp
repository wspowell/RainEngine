//

#include "rain_engine.h"


RainEngine::RainEngine() : sceneID(0), spriteID(0), textureID(0) { 
	printf("Initializing engine...\n");
}
RainEngine::~RainEngine() { }

// Window
bool RainEngine::openWindow() {
	bool result = win.open(); 
	mse.init();
	return result;
}
void RainEngine::setWindowTitle(const char* t) { win.setTitle(t); }
void RainEngine::setWindowSize(uint w, uint h) { win.setWidth(w); win.setHeight(h); }
void RainEngine::setWindowAA(uint a) { win.setAntiAliasing(a); }
void RainEngine::setWindowMode(int m) { win.setMode(m); }
double RainEngine::getWindowFrameRate() { return win.getFrameRate(); }
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
	} else {
		tex->loadTexture(); // load texture into OpenGL
		++textureID; // increment the id
		textures.insert(textureValType(textureID,tex)); // add texture to the map
	}

	return textureID;
}

uint RainEngine::createSprite(uint w, uint h, uint texID) {
	Sprite *spr = new Sprite(w,h,texID); // setup the sprite
	++spriteID; // the spriteID is the next number in the series
	sprites.insert(spriteValType(spriteID,spr)); // add sprite to the map
	printf("Created sprite (id:%u) width %u height %u at (%u,%u)\n",spriteID,w,h,x,y);
	return spriteID;
}

uint RainEngine::createScene(uint w, uint h) {
	Scene *scn = new Scene(w,h);
	++sceneID;
	scenes.insert(sceneValType(sceneID,scn));
	printf("Created scene (id:%u)\n",sceneID);
	return sceneID;
}

void RainEngine::addSpriteToScene(uint scnID, uint sprID) {
	Scene *scn = getScene(scnID);
	Sprite *spr = getSprite(sprID);
	if(scn != NULL && spr != NULL) {
		// add sprite to the scene
		scn->addSprite(sprID);
		printf("Added sprite (id:%u) to scene (id:%u)\n",sprID,scnID);
	}
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

void RainEngine::renderScene(uint scnID) {
	// render each spriteID in the Scene
	Scene *scn = getScene(scnID);
	if(scn == NULL) { 
		fprintf(stderr, "Could not render scene (id:%u)\n",scnID);
		return; 
	}
	
	//renderSprite(scn->getBackground());

	uintVector sceneSprites = scn->getSprites();
	for(uintVecItor itor = sceneSprites.begin(); itor != sceneSprites.end(); ++itor) {
		renderSprite(*itor);
	}
}

void RainEngine::renderSprite(uint sprID) {
	Sprite *spr = getSprite(sprID);
	if(spr == NULL) { return; }
	GLfloat x_scaled = ((GLfloat)spr->getX()/win.getWidth())*2-1; // top left x
	GLfloat y_scaled = 1-(((GLfloat)spr->getY())/win.getHeight())*2; // top left y
	GLfloat width_scaled = x_scaled+((GLfloat)spr->getWidth()/win.getWidth())*2; // width of sprite
	GLfloat height_scaled = y_scaled-((GLfloat)spr->getHeight()/win.getHeight())*2; // negative height, (*2 because its TWO across)

	glBegin (GL_QUADS);
	glTexCoord2f (0, 0);
	glVertex2f (x_scaled, y_scaled);
	glTexCoord2f (1.0, 0.0);
	glVertex2f (width_scaled, y_scaled);
	glTexCoord2f (1.0, 1.0);
	glVertex2f (width_scaled, height_scaled);
	glTexCoord2f (0.0, 1.0);
	glVertex2f (x_scaled, height_scaled);
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

void RainEngine::updateSprite(uint sprID, float x, float y) {
	Sprite *spr = getSprite(sprID);

	float newX = spr->getX()+x;
	float newY = spr->getY()+y;
	spr->setX(newX);
	spr->setY(newY);
}















