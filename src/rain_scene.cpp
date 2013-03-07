// scene

#include "rain_scene.h"

// SCENE

Scene::Scene(uint r, uint c, GLfloat t) : rows(r), cols(c), tilesize(t) { 
	printf("Initializing scene...%u,%u x %f\n",r,c,t);
}

Scene::~Scene() { }


// SPRITES

void Scene::addSprite(uint tileID) {
	sprites.push_back(tileID);	
	Coordinate *coord = new Coordinate(0,0);
	spriteCoords.insert(coordinateValType(tileID,coord));
}

/*
void Scene::removeSprite(uint spriteID) {
	// if spriteID is in the scene then remove it
	// if spriteID is not already in the scene then add it
	for(uintVecItor itor = sprites.begin(); itor != sprites.end(); ++itor) {
		if((*itor) == spriteID) { 
			sprites.erase(itor);
		}
	}
	
	// remove coordinate from map
	coordinateMapItor pos = spriteCoords.find(spriteID);
	if(pos != spriteCoords.end()) {
		spriteCoords.erase(pos);
	}
}*/

// move sprite by offset in reference to the sprites center
void Scene::moveSprite(uint spriteID, GLfloat x, GLfloat y) {
	// remove coordinate from map
	coordinateMapItor pos = spriteCoords.find(spriteID);
	if(pos != spriteCoords.end()) {
		uint lastX = (*pos).second->getX();
		uint lastY = (*pos).second->getY();
		(*pos).second->setX(lastX+x);
		(*pos).second->setY(lastY+y);
	}
}

// set sprite coordinate to (x,y)
void Scene::setSprite(uint spriteID, GLfloat x, GLfloat y) {
	coordinateMapItor pos = spriteCoords.find(spriteID);
	if(pos != spriteCoords.end()) {
		(*pos).second->setX(x);
		(*pos).second->setY(y);
	}
}

uintVector Scene::getSprites() {
	return sprites;
}

coordinateMap Scene::getSpriteCoords() {
	return spriteCoords;
}


// TILES

void Scene::addTile(uint tileID, uint r, uint c) {
	tiles.push_back(tileID);
	GLfloat rloc = (r*tilesize)-1; // center at 0,0 window and -1,1 opengl
	GLfloat cloc = 1-(c*tilesize);
	Coordinate *coord = new Coordinate(cloc,rloc);
	tileCoords.insert(coordinateTileValType(coord,tileID));
	printf("--- %f,%f ---\n",rloc,cloc);
}

/*
void Scene::removeTile(uint tileID) {
	// if tileID is in the scene then remove it
	// if tileID is not already in the scene then add it
	for(uintVecItor itor = tiles.begin(); itor != tiles.end(); ++itor) {
		if((*itor) == tileID) { 
			tiles.erase(itor);
		}
	}
	 
	// remove coordinate from map
	coordinateTileMapItor pos = tileCoords.find(tileID);
	if(pos != tileCoords.end()) {
		tileCoords.erase(pos);
	}
}*/

uintVector Scene::getTiles() {
	return tiles;
}

coordinateTileMap Scene::getTileCoords() {
	return tileCoords;
}

uint Scene::getRows() {
	return rows;
}

uint Scene::getCols() {
	return cols;
}

GLfloat Scene::getWidth() {
	return (cols*tilesize);
}

GLfloat Scene::getHeight() {
	return (rows*tilesize);
}



