#pragma once
#include <SFML\Graphics.hpp>

class Tile {
public:
	Tile(bool solid_, double movement_penalty_, sf::Color color_);
	Tile();
	~Tile();

	bool isSolid();
	double getPenalty();
	sf::Color getColor();
	void Rewrite(bool solid_, double movement_penalty_, sf::Color color_);

private:


	bool solid = false;
	double movement_penalty = 0.0;
	sf::Color color;
};

