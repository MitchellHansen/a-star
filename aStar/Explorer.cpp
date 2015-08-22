#include "Explorer.h"
#include <iostream>

Explorer::Explorer(Map* map_) {
	color = sf::Color::Blue;
	position = sf::Vector2i(10, 10);
	map = map_;
}


Explorer::~Explorer() {
}

sf::Vector2i Explorer::getPosition() {
	return position;
}

sf::Color Explorer::getColor() {
	return color;
}

bool Explorer::move() {

	// While there are moves for us to take
	if (!movement_stack.empty()) {
		bool valid = false; // If the next move is valid, collision
		int x = movement_stack.top();

		switch (x) {

		case 0: // North
			if (!map->getTile(position.x, position.y - 1)->isSolid()) {
				valid = true;
				position = sf::Vector2i(position.x, position.y - 1);
			}
			break;
		case 1: // East
			if (!map->getTile(position.x + 1, position.y)->isSolid()) {
				valid = true;
				position = sf::Vector2i(position.x + 1, position.y);
			}
			break;
		case 2: // South
			if (!map->getTile(position.x, position.y + 1)->isSolid()) {
				valid = true;
				position = sf::Vector2i(position.x, position.y + 1);
			}
			break;
		case 3: // West
			if (!map->getTile(position.x - 1, position.y)->isSolid()) {
				valid = true;
				position = sf::Vector2i(position.x - 1, position.y);
			}
			break;
		}

		// If the path was blocked
		if (!valid) {
			std::cout << "Path blocked" << std::endl;
			// Flush the moves list
			while(!movement_stack.empty()) {
				movement_stack.pop();
			}
			return false;
		}

		// If everything went well, pop and return true
		movement_stack.pop();
		return true;
	}
	else
		return false;
}

// A*
bool Explorer::plan(sf::Vector2i destination_) {

	return true;
}
