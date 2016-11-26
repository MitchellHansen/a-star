#include "Tile.h"



Tile::Tile(bool solid_, double movement_penalty_, sf::Color color_) {
	solid = solid_;
	movement_penalty = movement_penalty_;
	color = color_;
}


Tile::Tile() {
	solid = false;
	movement_penalty = 0.0;
	color = sf::Color::Red;
}

Tile::~Tile() {
}

bool Tile::isSolid() {
	return solid;
}

double Tile::getPenalty() {
	return movement_penalty;
}

sf::Color Tile::getColor() {
	return color;
}

void Tile::Rewrite(bool solid_, double movement_penalty_, sf::Color color_) {
	solid = solid_;
	movement_penalty = movement_penalty_;
	color = color_;
}
