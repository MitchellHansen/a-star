#pragma once
#include <map>
#include "App.h"
#include <unordered_map>
#include "node.h"

class Pather {

public:
	// Constructor
	Pather(Map* map_);
	~Pather();

	// Reference to the map data
	Map* map;

	// Containers for the loop, probably inefficient as hell
	std::unordered_map<node*, double> open_list;
	std::unordered_map<node*, double> closed_list;
	
	// A stack allocated 2d array from a template I stole from stackOverflow
	MultiArray<int, Map::CELLS_WIDTH , Map::CELLS_HEIGHT> visited_map;
	
	// Return a deque with the movement info to path to the end position from the start position
	std::deque<int> getPathTo(sf::Vector2i start, sf::Vector2i end);

	// Returns the end node of the current path
	sf::Vector2i getEndNodePosition();

	// Returns the current active node
	node* getActiveNode();

private:
	// Whether we couldn't find a path
	bool no_path = false;
	// If we found the path and can exit early
	bool early_exit;
	
	// Calculate the return path from back tracing the active nodes
	std::deque<int> returnPath();

	// The main iterative loop for a*
	std::deque<int> loop();

	// Movement list for the Explorer
	std::deque<int> path_list;

	// Start positions node
	node* start_node;
	// Current positions node
	node* active_node;
	// End positions node
	node* end_node;

};



