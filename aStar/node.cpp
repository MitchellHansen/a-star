#pragma once
#include "node.h"

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