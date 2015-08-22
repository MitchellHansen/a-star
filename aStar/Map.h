#pragma once
#include "Tile.h"
#include <SFML/System/Vector2.hpp>

class Map {
public:
	static const int CELLS_HEIGHT = 153;
	static const int CELLS_WIDTH = 319;

	Map();
	~Map();

	
	Tile* getTile(sf::Vector2i position);
	Tile* getTile(int x_, int y_);
	bool isTileSolid(sf::Vector2i);
	void setTile(sf::Vector2i position, Tile* data);

private:
	void Init();

	Tile* tileArray[319][153];
};

