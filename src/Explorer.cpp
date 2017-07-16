#include "Explorer.h"
#include <iostream>
#include "Pather.h"

Explorer::Explorer(Map* map_) {
	color = sf::Color::Yellow;
	position = sf::Vector2i(6, 10);
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


void Explorer::setDestination(sf::Vector2i destination_) {
	// Call a* to get path
	plan(destination_);
}

bool Explorer::move() {

	// While there are moves for us to take
	if (!movement_stack.empty()) {
		bool valid = false; // If the next move is valid, collision
		int x = movement_stack.back();

		switch (x) {
		case 0: // North
			if (!map->getTile(position.x, position.y - 1)->isSolid()) {  // If the tile isn't solid
				valid = true;											 // Set the move to valid
				position = sf::Vector2i(position.x, position.y - 1);	 // Update the Explorers position
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
			while (!movement_stack.empty()) {
				movement_stack.pop_back();
			}
			return false;
		}

		// If everything went well, pop and return true
		movement_stack.pop_back();

		return true;
	}
	else
		return false;
}

bool Explorer::plan(sf::Vector2i destination_) {
	
	// Create a new pather with the map data
	Pather pather(map);

	// Get the movement list from the pather
	movement_stack = pather.getPathTo(position, destination_);
	
	return true;
}
