RainEngine
==========

2D Game Engine

Author: Wesley Powell

The purpose of this engine is to provide cross-platform playability and the ability to create flexible 2D games. 
(Also, to teach myself game programming)

Technologies incorporated:
1. OpenGL (for graphics)
2. GLFW (for window and input)

Technologies to include:
1. Lua (for game creation)


Overview of architecture
========================

The engine holds all objects contained in the game. Data is passed by the engine to an object if it requires the data. All data in the engine is passed by reference using IDs. These IDs correspond with the objects stored in the engine. The player controls a "Sprite" that can move dynamically around the screen. The world is made up of individual "Scenes". A scene is created from many "Tiles". Tiles are static textures that make up the background of the scene. When a Scene is loaded the engine renders all objects that it contains.

The general flow of creation is:
1. Make a texture (in our case a texture is just an image, even though textures are technically not limited to that)
2. Make a sprite using a texture (container of data, these are objects that move)
3. Make tiles (container of data, these are static objects; or rather, the tiles that make up the background)
4. Make a scene (container of data, these are "maps" or individual areas that the player can move)
5. Add a sprite to the scene
6. Render the scene

