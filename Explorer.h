#pragma once
#include <SFML/Graphics.hpp>
#include <stack>
#include "Map.h"

class Explorer {
public:
	// Constructors
	Explorer(Map* map_);
	~Explorer();

	// Getters
	sf::Vector2i getPosition();
	sf::Color getColor();

	// Move to the specified destination
	void setDestination(sf::Vector2i destination_);
	
	// Follow the pathlist for one move
	bool move();

private:
	// Color that will be drawn
	sf::Color color;
	
	sf::Vector2i position;
	
	// Reference to the map data
	Map* map;

	// Moves list that will be filled with plan(), and executed by move()
	std::deque<int> movement_stack;

	// Fills the movement stack with moves
	bool plan(sf::Vector2i destination_);
};

