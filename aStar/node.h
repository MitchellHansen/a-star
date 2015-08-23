#pragma once
#include <map>
#include "App.h"
#include <unordered_map>

class Pather;

class node {
public:
	
	//		XY position, hueristic value, cameFrom direction, parent, ref to pather
	node(sf::Vector2i position_, double hueristic_, int came_from_, node* parent_, Pather* pather_);
	node();
	~node();

	

	// Populate the open_list with neighbors
	void getNewNeighbors();

	// HAS THE ABILITY TO DELETE THE PARENT!!
	node* getParent();

	sf::Vector2i getPosition();
	double getHueristic();
	int getCameFrom();

private:
	// Position of the node
	sf::Vector2i position;
	
	// The parent of the node, previous one visited
	node* parent;

	// How close it is to the destination
	double hueristic;

	// What direction the parent was
	int came_from;

	// Ref to pather
	Pather* pather;

};