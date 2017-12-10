#include "Explorer.h"

Explorer::Explorer(Graph* graph_) {
	color = sf::Color::Yellow;
	position = sf::Vector2i(6, 10);
    graph = graph_;
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

bool Explorer::update(double step_size) {

	// While there are moves for us to take
	if (!movement_stack.empty()) {
		bool valid = false; // If the next move is valid, collision
		int x = movement_stack.back();

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
	Pather pather(graph);

	// Get the movement list from the pather
	movement_stack = pather.getPathTo(position, destination_);
	
	return true;
}
