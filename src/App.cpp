#include "App.h"
#include <iostream>
#include "Map.h"
#include <chrono>

#ifdef linux
#elif defined _WIN32
#elif defined TARGET_OS_MAC
#endif

// ========== Constructors =============
App::App() {
	window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "aStart Pathing Demo");
}
App::~App() { }

// ========== Mutes =============
void App::Init() {

	// Set up the background texture
	background_texture = new sf::Texture();
	background_texture->loadFromFile("../assets/background.png");
	backgroundSprite.setTexture(*background_texture);

	// Pixel array for drawing the tiles, explorer
	_pixelArray = new sf::Uint8[WINDOW_WIDTH * WINDOW_HEIGHT * 4];
	pixel_array_texture.create(WINDOW_WIDTH, WINDOW_HEIGHT);

	// Create the explorer, giving it a reference to the map data
	explorer = new Explorer(&map);
}

void App::Input() {
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window->close();

		// Set the destination
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			sf::Vector2i mouse_position = sf::Mouse::getPosition(*window);
			explorer->setDestination(sf::Vector2i(mouse_position.x/ 5, mouse_position.y/ 5)); 
		}
		
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Q) {
				explorer->setDestination(sf::Vector2i(20, 20));
			}
			if (event.key.code == sf::Keyboard::W) {
				explorer->setDestination(sf::Vector2i(50, 50));
			}
			if (event.key.code == sf::Keyboard::E) {
				explorer->setDestination(sf::Vector2i(100, 12));
			}
		}
	}
}

void App::Update(double step_size) {

	Input();

	// Have the explorer go one move forward
	explorer->move();
}

void App::Render() {


	// HOUSEKEEPING

	// Get the physics fps for the last render cycle
	physics_fps = physics_frame_count * render_fps;

	// Frame time in seconds
	frame_time = delta_time * 1000;

	// And the render fps
	render_fps = 1000 / frame_time;



	// RENDERING

	// Clear and draw a fresh background
	window->clear(sf::Color::Blue);
	window->draw(backgroundSprite);

	// Clean up the pixel array and reset everything to 0's again
	for (int i = 0; i < WINDOW_WIDTH * WINDOW_HEIGHT * 4; i++) {
		_pixelArray[i] = 0;
	}
	
	// Color all the tiles
	for (int x = 0; x < Map::CELLS_WIDTH; x++) {
		for (int y = 0; y < Map::CELLS_HEIGHT; y++) {
	
			// Get the current cell position
			sf::Vector2i pos;
			pos.x = x;
			pos.y = y;

			// Use that to find the color of the tile at that position
			sf::Color thing = map.getTile(pos)->getColor();
			
			// Fill the 4x4 pixel area taken up by the cell 
			for (int x2 = 1; x2 < 5; x2++) {
				for (int y2 = 1; y2 < 5; y2++) {
				
					int pixel_x = (x * 5) + x2;
					int pixel_y = (y * 5) + y2;

					_pixelArray[(pixel_y * WINDOW_WIDTH + pixel_x) * 4] =     thing.r;            // Red
					_pixelArray[(pixel_y * WINDOW_WIDTH + pixel_x) * 4 + 1] = thing.g;            // Green
					_pixelArray[(pixel_y * WINDOW_WIDTH + pixel_x) * 4 + 2] = thing.b;            // Blue
					_pixelArray[(pixel_y * WINDOW_WIDTH + pixel_x) * 4 + 3] = thing.a;            // Alpha

				}
			}
		}
	}
	
	// Draw the explorer
	// Basically the same as above, fills 4x4 area where the explorer is located
	for (int x2 = 1; x2 < 5; x2++) {
		for (int y2 = 1; y2 < 5; y2++) {

			int pixel_x = (explorer->getPosition().x * 5) + x2;
			int pixel_y = (explorer->getPosition().y * 5) + y2;
			
			sf::Color color = explorer->getColor();

			_pixelArray[(pixel_y * WINDOW_WIDTH + pixel_x) * 4]     = color.r;            // Red
			_pixelArray[(pixel_y * WINDOW_WIDTH + pixel_x) * 4 + 1] = color.g;            // Green
			_pixelArray[(pixel_y * WINDOW_WIDTH + pixel_x) * 4 + 2] = color.b;            // Blue
			_pixelArray[(pixel_y * WINDOW_WIDTH + pixel_x) * 4 + 3] = color.a;            // Alpha

		}
	}
	
	// Update and draw the pixel array
	pixel_array_texture.update(_pixelArray);
	pixel_array_sprite.setTexture(pixel_array_texture);
	window->draw(pixel_array_sprite);
	
	// Finish!
	window->display();
}


void App::Run() {
	Init();

	while (window->isOpen()) {
		// Time since app start
		elapsed_time = time();

		// Time between last frame start and this frame
		// 2 seconds = 30 seconds - 28 seconds
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

			physics_frame_count++;
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
