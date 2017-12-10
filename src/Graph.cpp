#include "Graph.h"


Graph::Graph() {
}


Graph::~Graph() {
}

void Graph::init() {
    // Init with a random graph of evenly spaced points

    // For each point find it's N nearest neighbors. 
    //  Choose one randomly to link
    //  Choose a random amount more to link
}


void Graph::add(GraphNode* node) {
    adjacency_list.push_back(node);
}

void Graph::remove(int adjacency_list_index) {

	std::list<GraphNode*>::iterator it;
	std::advance(it, adjacency_list_index);
	adjacency_list.erase(it);
}

bool Graph::remove(GraphNode* node) {

	for (auto it = adjacency_list.begin(); it != adjacency_list.end(); ) {
		if ((*it) == node) {
			adjacency_list.erase(it);
            return true;
		}
	}
    return false;
}


GraphNode* Graph::click(sf::Vector2f position) {

    // for every tile
    //   check wether the click position was within the sprite
    //   return that tile
    // if none found
    //   return nullptr
}








