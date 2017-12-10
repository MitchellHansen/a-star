#include "node.h"
#include "Pather.h"


node::node(sf::Vector2i XY, double h, int cF, node* p, Pather* pather_) {
	position = XY;
	hueristic = h;
	came_from = cF;
	parent = p;
	pather = pather_;
}
node::node() {

}
node::~node() {

}

void node::getNewNeighbors() {

	// Get the end node position for calculating distance from end(hueristic)
//	int x = pather->getEndNodePosition().x;
//	int y = pather->getEndNodePosition().y;
//
//	sf::Vector2i dest0XY(position.x, position.y - 1); // North
//	if (!pather->map->isTileSolid(dest0XY) && pather->visited_map(dest0XY.x, dest0XY.y) != 1) {
//		// If so, find the distance between this node and the end node, the hueristic
//		int tempx = (x - dest0XY.x);
//		int tempy = (y - dest0XY.y);
//
//		// I think dv is the hueristic??
//		double dv = sqrt((tempx * tempx) + (tempy * tempy));
//
//		double v = dv;
//
//		// Take that value and create a new node
//		pather->open_list.emplace(new node(dest0XY, v, 0, pather->getActiveNode(), pather), v);
//
//		// Set that tile as visited so we don't get stuck in a loop
//		pather->visited_map(dest0XY.x, dest0XY.y) = 1;
//	}
//
//	sf::Vector2i dest1XY(position.x + 1, position.y); // East
//	if (!pather->map->isTileSolid(dest1XY) && pather->visited_map(dest1XY.x, dest1XY.y) != 1) {
//		// If so, find the distance between this node and the end node, the hueristic
//		int tempx = (x - dest1XY.x);
//		int tempy = (y - dest1XY.y);
//
//		// I think dv is the hueristic??
//		double dv = sqrt((tempx * tempx) + (tempy * tempy));
//
//		double v = dv;
//
//		// Take that value and create a new node
//		pather->open_list.emplace(new node(dest1XY, v, 1, pather->getActiveNode(), pather), v);
//
//		// Set that tile as visited so we don't get stuck in a loop
//		pather->visited_map(dest1XY.x, dest1XY.y) = 1;
//	}
//
//	sf::Vector2i dest2XY(position.x, position.y + 1); // South
//	if (!pather->map->isTileSolid(dest2XY) && pather->visited_map(dest2XY.x, dest2XY.y) != 1) {
//		// If so, find the distance between this node and the end node, the hueristic
//		int tempx = (x - dest2XY.x);
//		int tempy = (y - dest2XY.y);
//
//		// I think dv is the hueristic??
//		double dv = sqrt((tempx * tempx) + (tempy * tempy));
//
//		double v = dv;
//
//		// Take that value and create a new node
//		pather->open_list.emplace(new node(dest2XY, v, 2, pather->getActiveNode(), pather), v);
//
//		// Set that tile as visited so we don't get stuck in a loop
//		pather->visited_map(dest2XY.x, dest2XY.y) = 1;
//	}
//
//	sf::Vector2i dest3XY(position.x - 1, position.y); // West
//	if (!pather->map->isTileSolid(dest3XY) && pather->visited_map(dest3XY.x, dest3XY.y) != 1) {
//		// If so, find the distance between this node and the end node, the hueristic
//		int tempx = (x - dest3XY.x);
//		int tempy = (y - dest3XY.y);
//
//		// I think dv is the hueristic??
//		double dv = sqrt((tempx * tempx) + (tempy * tempy));
//
//		double v = dv;
//
//		// Take that value and create a new node
//		pather->open_list.emplace(new node(dest3XY, v, 3, pather->getActiveNode(), pather), v);
//
//		// Set that tile as visited so we don't get stuck in a loop
//		pather->visited_map(dest3XY.x, dest3XY.y) = 1;
//	}
}

sf::Vector2i node::getPosition() {
	return position;
}

node* node::getParent() {
	return parent;
}

double node::getHueristic() {
	return hueristic;
}

int node::getCameFrom() {
	return came_from;
}
