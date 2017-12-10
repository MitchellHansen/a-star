#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>    
#include <chrono>      
#include "Delaunay.h"
#include "Explorer.h"
#include "Graph.h"


class App {
public:

	static const int WINDOW_HEIGHT = 800;
	static const int WINDOW_WIDTH = 800;

	App();
	~App();
	void Run();

private:

	Graph graph;
//    Explorer* explorer;

    sf::RenderWindow* window;
	sf::Event event;

	void Init();
	void Input(double step_size);
	void Update(double step_size);
	void Render();

	static float time();

	float step_size           = 0.0166f;
	double current_time       = 0.0;
	double accumulator_time   = 0.0;
	double elapsed_time       = 0.0;
	double delta_time         = 0.0;
};
