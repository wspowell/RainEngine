// scene

#include "rain_scene.h"

Scene::Scene(uint c, uint r) : cols(c), rows(r) { 
	printf("Initializing scene...\n");
}

Scene::~Scene() { }

void Scene::addSprite(uint spriteID) {
	// if spriteID is not already in the scene then add it
	bool exists = false;
	for(uintVecItor itor = sprites.begin(); itor != sprites.end(); ++itor) {
		if((*itor) == spriteID) { 
			exists = true; 
			break; 
		}
	}
	if(!exists) {
		sprites.push_back(spriteID);
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
}

uintVector Scene::getSprites() {
	return sprites;
}

void Scene::addTile(uint r, uint c) {
	
}



