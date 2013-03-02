// scene

#include "rain_scene.h"




Coordinate::Coordinate(uint x, uint y) : xLoc(x), yLoc(y) { }
Coordinate::~Coordinate() { }
uint Coordinate::getX() { return xLoc; }
uint Coordinate::getY() { return yLoc; }
void Coordinate::setX(uint x) { xLoc = x; }
void Coordinate::setY(uint y) { yLoc = y; }

Location::Location(uint c, uint r) : col(c), row(r) { }
Location::~Location() { }
uint Location::getCol() { return col; }
uint Location::getRow() { return row; }
void Location::setCol(uint c) { col = c; }
void Location::setRow(uint r) { row = r; }


Scene::Scene(uint c, uint r) : cols(c), rows(r) { 
	printf("Initializing scene...\n");
}

Scene::~Scene() { }


// SPRITES


int Scene::hasSprite(uint spriteID) {
	int id = -1;
	for(uintVecItor itor = sprites.begin(); itor != sprites.end(); ++itor) {
		if((*itor) == spriteID) { 
			id = (*itor); 
			break; 
		}
	}
	return id;
}

void Scene::addSprite(uint spriteID) {
	if(hasSprite(spriteID) == -1) {
		sprites.push_back(spriteID);
		spriteCoords.insert(coordinateValType(spriteID, new Coordinate(0,0))); // default to 0,0 until it is updated 
	}
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

// move sprite by offset
void Scene::moveSprite(uint spriteID, uint x, uint y) {
	if(hasSprite(spriteID) != -1) {
		// remove coordinate from map
		coordinateMapItor pos = spriteCoords.find(spriteID);
		if(pos != spriteCoords.end()) {
			uint lastX = (*pos).second->getX();
			uint lastY = (*pos).second->getY();
			(*pos).second->setX(lastX+x);
			(*pos).second->setY(lastY+y);
		}
	}
}

// set sprite coordinate to (x,y)
void Scene::setSprite(uint spriteID, uint x, uint y) {
	if(hasSprite(spriteID) != -1) {
		coordinateMapItor pos = spriteCoords.find(spriteID);
		if(pos != spriteCoords.end()) {
			(*pos).second->setX(x);
			(*pos).second->setY(y);
		}
	}
}

uintVector Scene::getSprites() {
	return sprites;
}



// TILES


int Scene::hasTile(uint tileID) {
	int id = -1;
	for(uintVecItor itor = tiles.begin(); itor != tiles.end(); ++itor) {
		if((*itor) == tileID) { 
			id = (*itor); 
			break; 
		}
	}
	return id;
}

void Scene::addTile(uint tileID) {
	if(hasTile(tileID) == -1) {
		tiles.push_back(tileID);
		tileLocs.insert(locationValType(tileID, new Location(0,0))); // default to 0,0 until it is updated 
	}
}

void Scene::removeTile(uint tileID) {
	// if tileID is in the scene then remove it
	// if tileID is not already in the scene then add it
	for(uintVecItor itor = tiles.begin(); itor != tiles.end(); ++itor) {
		if((*itor) == tileID) { 
			tiles.erase(itor);
		}
	}
	
	// remove location from map
	locationMapItor pos = tileLocs.find(tileID);
	if(pos != tileLocs.end()) {
		tileLocs.erase(pos);
	}
}

// move tile by offset
void Scene::moveTile(uint tileID, uint c, uint r) {
	if(hasTile(tileID) != -1) {
		locationMapItor pos = tileLocs.find(tileID);
		if(pos != tileLocs.end()) {
			uint lastC = (*pos).second->getCol();
			uint lastR = (*pos).second->getRow();
			(*pos).second->setCol(lastC+c);
			(*pos).second->setRow(lastR+r);
		}
	}
}

// set tile location to (c,r)
void Scene::setTile(uint tileID, uint c, uint r) {
	if(hasTile(tileID) != -1) {
		// remove location from map
		locationMapItor pos = tileLocs.find(tileID);
		if(pos != tileLocs.end()) {
			(*pos).second->setCol(c);
			(*pos).second->setRow(r);
		}
	}
}

uintVector Scene::getTiles() {
	return tiles;
}



