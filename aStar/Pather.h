#pragma once
#include <map>
#include "App.h"
#include <unordered_map>

class Pather;

class node {
public:

	node(sf::Vector2i XY, int h, int cF, int cL, node* p, Pather* pather_);
	node();
	~node();

	sf::Vector2i xy;

	// Ugh, pointers, ugh c++
	node* parent;
	int hueristic;
	int cameFrom;
	int closedList;
	Pather* pather;

	void neighbors();
private:

};

class Pather {
public:
	Pather(Map* map_);
	~Pather();

	Map* map;

	std::unordered_map<node*, int> openList;
	std::unordered_map<node*, int> closedList;
	int visitedMap[App::WINDOW_HEIGHT][App::WINDOW_WIDTH];

	 std::vector<int> pathTo(sf::Vector2i start, sf::Vector2i end);
	 std::vector<int> loop();
	 std::vector<int> returnPath();

	 sf::Vector2i getEndNodePosition();

	node* start_node;
	node* active_node;

	bool no_path = false;
	bool early_exit;

private:

	std::vector<int> path_list;
	node* end_node;

};



