#pragma once
#include <SFML/Graphics.hpp>
#include <stack>
#include "Map.h"

class Explorer {
public:
	Explorer(Map* map_);
	~Explorer();
	sf::Vector2i getPosition();
	sf::Color getColor();
	void setDestination(sf::Vector2i destination_);
	bool move();
private:
	sf::Color color;
	sf::Vector2i position;
	Map* map;

	std::deque<int> movement_stack;
	bool plan(sf::Vector2i destination_);
};

