#include "App.h"

/**
 *  Specs
 *     I want to be able to define a graph in any order and with any XY positioning of nodes
 *     I want to be able to render these nodes and render their "connections" between each other
 *     I want to be able to Apply the A* pathfinding algorithm to this graph and receive back a path to follow
 *     I want to be able to render a path follower which will follow the received path and stop on obsticles
 *     I want a gui (imgui) to allow me basic interaction with the graph
 *
 *
 *  
 *  Monolithic renderer or inbuilt render methods?
 *
 *
 * Find neighbors = Just get the adjacency list
 *
 * Remove node:
 *      Remove self from all ajdacent nodes
 *
 * Add node:
 *      Set adjacency list
 *      Add self to each node in adjacency list
 *
*/


App::App() {
	window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "aStart Pathing Demo");
}
App::~App() {

}

void App::Init() {
    //Tile::set_spritesheet("assets/sprite_sheet_xml.xml", "assets/sprite_sheet.png");
    graph.init();

}

void App::Input(double step_size) {

	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window->close();

		// Set the destination
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			sf::Vector2i mouse_position = sf::Mouse::getPosition(*window);
			//explorer->setDestination(sf::Vector2i(mouse_position.x/ 5, mouse_position.y/ 5));
		}
		
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Q) {
			    window->close();
			}
		}
	}
}

void App::Update(double step_size) {

	Input(step_size);
//    explorer->update(step_size);
  

}

void App::Render() {

	// Clear and draw a fresh background
	window->clear(sf::Color(100, 149, 237, 255));


	// Finish!
	window->display();
}


void App::Run() {

	Init();

	while (window->isOpen()) {

		// Time since app start
		elapsed_time = time();

		// Time between last frame start and this frame
		delta_time = elapsed_time - current_time;
		current_time = elapsed_time;

		// Make sure we aren't taking too big of steps when lagging
		if (delta_time > 0.02f)
			delta_time = 0.02f;

		// Add the delta time to the leftover time from the last frame
		accumulator_time += delta_time;

		// While there is time left
		while ((accumulator_time - step_size) >= step_size) {

			// Take away the time we will be simulating
			accumulator_time -= step_size;

			// Update the game for the timestep
			Update(step_size);
		}

		Render();
	}
}

float App::time() {

	static std::chrono::time_point<std::chrono::system_clock> start;
	static bool started = false;

	if (!started) {
		start = std::chrono::system_clock::now();
		started = true;
	}

	std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_time = now - start;
	return static_cast<float>(elapsed_time.count());

}
