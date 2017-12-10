#include "Pather.h"

Pather::Pather(Graph* graph_) {
	graph = graph_;
}

Pather::~Pather() {
}

sf::Vector2f Pather::getEndNodePosition() {
	return end_node->getPosition();
}

GraphNode* Pather::getActiveNode() {
	return active_node;
}

std::deque<int> Pather::getPathTo(sf::Vector2i start, sf::Vector2i end) {

	// Clear the visited map of erroneous data
//	for (int i = 0; i < Map::CELLS_WIDTH; i++) {
//		for (int l = 0; l < Map::CELLS_HEIGHT; l++) {
//			visited_map(i, l) = 0;
//		}
//	}
	
	// Place the start and end nodes
//	start_node = new node(start, 7000, 0, nullptr, this);
//	end_node = new node(end, 0, 0, nullptr, this);

	// Set the entry point, clean up any stray data from last run
//	active_node = start_node;
//	open_list.clear();
//	closed_list.clear();

	// Seed for the loop, hueristic is intentionally high
//	open_list.emplace(start_node, start_node->getHueristic());

	// Set up the early exit, and enter into the loop
//	early_exit = false;
//	path_list = loop();

	return path_list;
}


std::deque<int> Pather::loop() {
//
//	while (!open_list.empty() && !early_exit) {	
//		
//		if (closed_list.size() > 1000) {           // Quits when the path gets to be over 1000 long, janky 
//			no_path = true;						   // Signal no path was found
//			early_exit = true;					   // Break
//			break;
//		}
//
//		// Check to see if we're at our destination, break if we are
//		if (active_node->getPosition().x == end_node->getPosition().x &&
//			active_node->getPosition().y == end_node->getPosition().y ){
//
//			early_exit = true;
//			break;
//		}
//
//		// If we didn't get held up before, do a round of a*
//		else {
//
//			// Find the pair with the lowest hueristic
//			std::pair<node*, double> bestMin(start_node, 10000);   // Get a clean value for the comparison
//
//			// Compare all the values in openList for the one with the smallest hueristic
//			// O(n) complexity so it can get verrrrryyyy slow
//			for (auto testMin: open_list) {
//				if (bestMin.second >= testMin.second)
//					bestMin = testMin;
//			}
//
//			// Set the new active node to the lowest heuristic that we found earlier
//			active_node = bestMin.first;
//
//			// Find the neighbors for that node
//			active_node->getNewNeighbors();
//
//			// Remove the active node from the openlist as you have visited it and called its neighbors
//			open_list.erase(active_node);
//
//			// Check to see if the node has already been added to the closed list, if not, add it
//			if (closed_list.count(active_node) == 0) {
//				closed_list.emplace(active_node, active_node->getHueristic());
//			}
//
//			
//		}
//	}
//
	// When we're done, get the return path
	std::deque<int> return_path;// = returnPath();
//	if (no_path || return_path.empty()) {              // If we had an error, display it
//		return std::deque<int>();
//		std::cout << " no return path " << std::endl;
//	}

	return return_path;
}

std::deque<int> Pather::returnPath() {
	// Deque that will be returned
	std::deque<int> path;

	// Backtrack through the active_nodes, adding their cameFrom value to the deque
/*	while (active_node->getParent() != nullptr) {
		path.push_back(active_node->getCameFrom());

		node* parent = active_node->getParent();
		delete active_node;
		active_node = parent;
	}
*/
	return path;
}



