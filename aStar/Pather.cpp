#include "Pather.h"
#include <iostream>

node::node(sf::Vector2i XY, int h, int cF, int cL, node* p, Pather* pather_) {
	xy = XY;
	hueristic = h;
	cameFrom = cF;
	closedList = cL;
	parent = p;
	pather = pather_;
}
node::node() {
	
}
node::~node() {
	
}

void node::neighbors() {

	int x = pather->getEndNodePosition().x;
	int y = pather->getEndNodePosition().y;

	sf::Vector2i dest0XY(xy.x, xy.y - 1); // North
	if (!pather->map->isTileSolid(dest0XY) && pather->visitedMap[dest0XY.x][dest0XY.y] != 1) {
		// If so, find the distance between this node and the end node, the hueristic
		int tempx = (x - dest0XY.x);
		int tempy = (y - dest0XY.y);

		// I think dv is the hueristic??
		double dv = sqrt((tempx * tempx) + (tempy * tempy));

		int v = static_cast<int>(dv);

		// Take that value and create a new node
		pather->openList.emplace(new node(dest0XY, v, 0, 1, pather->active_node, pather), v);

		// Set that tile as visited so we don't get stuck in a loop
		pather->visitedMap[dest0XY.x][dest0XY.y] = 1;
	}

	sf::Vector2i dest1XY(xy.x + 1, xy.y); // East
	if (!pather->map->isTileSolid(dest1XY) && pather->visitedMap[dest1XY.x][dest1XY.y] != 1) {
		// If so, find the distance between this node and the end node, the hueristic
		int tempx = (x - dest1XY.x);
		int tempy = (y - dest1XY.y);

		// I think dv is the hueristic??
		double dv = sqrt((tempx * tempx) + (tempy * tempy));

		int v = static_cast<int>(dv);

		// Take that value and create a new node
		pather->openList.emplace(new node(dest1XY, v, 0, 1, pather->active_node, pather), v);

		// Set that tile as visited so we don't get stuck in a loop
		pather->visitedMap[dest1XY.x][dest1XY.y] = 1;
	}

	sf::Vector2i dest2XY(xy.x, xy.y + 1); // South
	if (!pather->map->isTileSolid(dest2XY) && pather->visitedMap[dest2XY.x][dest2XY.y] != 1) {
		// If so, find the distance between this node and the end node, the hueristic
		int tempx = (x - dest2XY.x);
		int tempy = (y - dest2XY.y);

		// I think dv is the hueristic??
		double dv = sqrt((tempx * tempx) + (tempy * tempy));

		int v = static_cast<int>(dv);

		// Take that value and create a new node
		pather->openList.emplace(new node(dest2XY, v, 0, 1, pather->active_node, pather), v);

		// Set that tile as visited so we don't get stuck in a loop
		pather->visitedMap[dest2XY.x][dest2XY.y] = 1;
	}

	sf::Vector2i dest3XY(xy.x - 1, xy.y); // West
	if (!pather->map->isTileSolid(dest3XY) && pather->visitedMap[dest3XY.x][dest3XY.y] != 1) {
		// If so, find the distance between this node and the end node, the hueristic
		int tempx = (x - dest3XY.x);
		int tempy = (y - dest3XY.y);

		// I think dv is the hueristic??
		double dv = sqrt((tempx * tempx) + (tempy * tempy));

		int v = static_cast<int>(dv);

		// Take that value and create a new node
		pather->openList.emplace(new node(dest3XY, v, 0, 1, pather->active_node, pather), v);

		// Set that tile as visited so we don't get stuck in a loop
		pather->visitedMap[dest3XY.x][dest3XY.y] = 1;
	}
}



Pather::Pather(Map* map_) {
	map = map_;
}

Pather::~Pather() {
}

sf::Vector2i Pather::getEndNodePosition() {
	return end_node->xy;
}

std::vector<int> Pather::pathTo(sf::Vector2i start, sf::Vector2i end) {

	// Clear the visited map for erroneous data
	for (int i = 0; i < Map::CELLS_WIDTH; i++) {
		for (int l = 0; l < Map::CELLS_HEIGHT; l++) {
			visitedMap[i][l] = 0;
		}
	}
	
	// Place the start and end nodes
	start_node = new node(start, 0, 0, 0, nullptr, this);
	end_node = new node(end, 0, 0, 0, nullptr, this);

	// Set the entry point, clean up any stray data from last run
	active_node = start_node;
	openList.clear();
	closedList.clear();

	// Seed for the loop
	openList.emplace(start_node, 0);

	early_exit = false;
	//path_list = Loop();

	return path_list;
}


std::vector<int> Pather::loop() {
	while (!openList.empty() && !early_exit) {
		// Early exit jankyness, need to change this
		if (closedList.size() > 3000) {
			no_path = true;
			early_exit = true;
			break;
		}
		else if (active_node->xy.x == end_node->xy.x && end_node->xy.y == end_node->xy.y) {
			early_exit = true;
			break;
		}
		else {
			// Find the pair with the lowest hueristic
			// 5/10
			std::pair<node*, int> bestMin;
			for (auto testMin: openList) {
				if (bestMin.second < testMin.second)
					bestMin = testMin;
			}

			// Find the neighbors for that node
			active_node->neighbors();

			// Remove the active node from the openlist as you have visited it and called its neighbors
			openList.erase(active_node);

			// Check to see if the node has already been added to the closed list, if not, add it
			if (closedList.count(active_node) > 0) {
				closedList.emplace(active_node, active_node->hueristic);
			}

			// Set the new active node to the lowest hueristic that we found earlier 
			active_node = bestMin.first;
		}
	}

	std::vector<int> return_path = returnPath();
	if (no_path || return_path.empty()) {
		return std::vector<int>(0, 0);
		std::cout << " no return path " << std::endl;
	}

	return return_path;
}

std::vector<int> Pather::returnPath() {
	std::vector<int> path;

	while (active_node != nullptr) {
		path.push_back(active_node->cameFrom);
		delete active_node;
		active_node = active_node->parent;
	}

	return path;
}



