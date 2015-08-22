#pragma once
#include <SFML/Graphics.hpp>
#include "App.h"

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


