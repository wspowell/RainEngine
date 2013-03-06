// scene

#include "rain_scene.h"

// SCENE

Scene::Scene(uint r, uint c, uint t) : rows(r), cols(c), tilesize(t) { 
	printf("Initializing scene...\n");
}

Scene::~Scene() { }


// SPRITES

void Scene::addSprite(uint spriteID) {
	sprites.push_back(spriteID);
	spriteCoords.insert(coordinateValType(spriteID, new Coordinate(0,0))); // default to 0,0 until it is updated 
}

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
}

// move sprite by offset in reference to the sprites center
void Scene::moveSprite(uint spriteID, int x, int y) {
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
void Scene::setSprite(uint spriteID, uint x, uint y) {
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
	tileCoords.insert(coordinateValType(tileID, new Coordinate(r,c)));
}

void Scene::removeTile(uint tileID) {
	// if tileID is in the scene then remove it
	// if tileID is not already in the scene then add it
	for(uintVecItor itor = tiles.begin(); itor != tiles.end(); ++itor) {
		if((*itor) == tileID) { 
			tiles.erase(itor);
		}
	}
	 
	// remove coordinate from map
	coordinateMapItor pos = tileCoords.find(tileID);
	if(pos != tileCoords.end()) {
		tileCoords.erase(pos);
	}
}

uintVector Scene::getTiles() {
	return tiles;
}


uint Scene::getRows() {
	return rows;
}

uint Scene::getCols() {
	return cols;
}

uint Scene::getWidth() {
	return (cols*tilesize);
}

uint Scene::getHeight() {
	return (rows*tilesize);
}



