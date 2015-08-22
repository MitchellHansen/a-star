#include "Map.h"
#include <stdlib.h>


Map::Map() {
	Init();
}


Map::~Map() {
}



Tile* Map::getTile(sf::Vector2i position_) {
	if (position_.x > CELLS_WIDTH || position_.x < 0
		|| position_.y > CELLS_HEIGHT || position_.y < 0) {
		return nullptr;
	}
	
	return tileArray[position_.x][position_.y];
}

bool Map::isTileSolid(sf::Vector2i position_) {
	if (position_.x >= CELLS_WIDTH || position_.x < 0
		|| position_.y >= CELLS_HEIGHT || position_.y < 0) {
		return true;
	}
	else 
		return tileArray[position_.x][position_.y]->isSolid();
}
Tile* Map::getTile(int x_, int y_) {
	return tileArray[x_][y_];
}

void Map::setTile(sf::Vector2i position, Tile* data) {
	delete tileArray[position.x][position.y];
	tileArray[position.x][position.y] = data;
}

void Map::Init() {
	int q;

	for (int x = 0; x < CELLS_WIDTH; x++) {
		for (int y = 0; y < CELLS_HEIGHT; y++) {
			q = rand() % 100; 
			if (q > 90) {
				tileArray[x][y] = new Tile(true, 100.0, sf::Color::Cyan);
			}
			else {
				tileArray[x][y] = new Tile(false, 0.0, sf::Color::Red);
			}
				
		}
	}
}
