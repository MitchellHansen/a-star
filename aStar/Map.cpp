#include "Map.h"
#include <stdlib.h>


Map::Map() {
	Init();
}


Map::~Map() {
}

Tile* Map::getTile(sf::Vector2i position_) {

	// If the position is within bounds
	if (position_.x > CELLS_WIDTH || position_.x < 0
		|| position_.y > CELLS_HEIGHT || position_.y < 0) {
		return nullptr;
	}
	else
		// Return the value specified 
		return tileArray[position_.x][position_.y];
}

bool Map::isTileSolid(sf::Vector2i position_) {

	// If the position is within bounds
	if (position_.x >= CELLS_WIDTH || position_.x < 0
		|| position_.y >= CELLS_HEIGHT || position_.y < 0) {
		return true; // If it isn't say that the tile is solid
	}
	else 
		// Return whether the tile is solid
		return tileArray[position_.x][position_.y]->isSolid();
}

Tile* Map::getTile(int x_, int y_) {

	// If the position is within bounds
	if (x_ > CELLS_WIDTH || x_ < 0
		|| y_ > CELLS_HEIGHT || y_ < 0) {
		return nullptr;
	}
	else
		// Return the value specified 
		return tileArray[x_][y_];
}

void Map::overwriteTile(sf::Vector2i position_, Tile* data) {
	// If the position is within bounds
	if (position_.x >= CELLS_WIDTH || position_.x < 0
		|| position_.y >= CELLS_HEIGHT || position_.y < 0) {
		return; // If it isn't just return
	}
	else { // If it is, then delete the old data, replace it with the new
		delete tileArray[position_.x][position_.y];
		tileArray[position_.x][position_.y] = data;
	}
}

void Map::Init() {

	// Fill up the map with a random scatter of solid and passable tiles
	
	int q;

	for (int x = 0; x < CELLS_WIDTH; x++) {
		for (int y = 0; y < CELLS_HEIGHT; y++) {
			q = rand() % 100; 
			if (q > 65) {
				tileArray[x][y] = new Tile(true, 100.0, sf::Color::Cyan);
			}
			else {
				tileArray[x][y] = new Tile(false, 0.0, sf::Color::Red);
			}
				
		}
	}
}
