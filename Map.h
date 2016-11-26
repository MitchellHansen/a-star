#pragma once
#include "Tile.h"
#include <SFML/System/Vector2.hpp>

class Map {
public:
	// Width and height of the map in individual cells
	static const int CELLS_HEIGHT = 153;
	static const int CELLS_WIDTH = 319;

	// Constructors
	Map();
	~Map();

	// Get the tile at the specified position, overloaded
	Tile* getTile(sf::Vector2i position);
	Tile* getTile(int x_, int y_);

	bool isTileSolid(sf::Vector2i);

	// completely replaces the data at the specified position
	void overwriteTile(sf::Vector2i position, Tile* data);

private:
	void Init();

	// Data
	Tile* tileArray[319][153];
};

