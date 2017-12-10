#pragma once
#include <map>
#include "App.h"
#include <unordered_map>
#include "GraphNode.h"
#include "Graph.h"

class Pather {

public:
	// Constructor
	Pather(Graph* graph_);
	~Pather();

	// Reference to the map data
	Graph* graph;

	// Containers for the loop, probably inefficient as hell
	// open list are a list of neighbors we are currently considering
	std::unordered_map<GraphNode*, double> open_list;
	// closed list are the tiles we have traversed
	std::unordered_map<GraphNode*, double> closed_list;
	
	// A stack allocated 2d array from a template I stole from stackOverflow
	//MultiArray<int, Map::CELLS_WIDTH , Map::CELLS_HEIGHT> visited_map;
	
	// Return a deque with the movement info to path to the end position from the start position
	// This should return a list of indices for the vector<node*> list of neighbors each node has
	std::deque<int> getPathTo(sf::Vector2i start, sf::Vector2i end);

	// Returns the end node of the current path
	sf::Vector2f getEndNodePosition();

	// Returns the current active node
    GraphNode* getActiveNode();

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
	GraphNode* start_node;
	// Current positions node
	GraphNode* active_node;
	// End positions node
	GraphNode* end_node;

};



