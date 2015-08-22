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
private:
	sf::Color color;
	sf::Vector2i position;
	Map* map;

	std::stack<int> movement_stack;
	bool move();
	bool plan(sf::Vector2i destination_);
};

