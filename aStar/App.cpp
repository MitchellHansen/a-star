#include "App.h"
#include <windows.h>
#include <iostream>
#include "Map.h"


// ========== Constructors =============
App::App() {
	window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");
}
App::~App() { }

// ========== Mutes =============
void App::Init() {

	// Set up the background texture
	background_texture = new sf::Texture();
	background_texture->loadFromFile("background.png");

	backgroundSprite.setTexture(*background_texture);

	_pixelArray = new sf::Uint8[WINDOW_WIDTH * WINDOW_HEIGHT * 4];
	pixel_array_texture.create(WINDOW_WIDTH, WINDOW_HEIGHT);

	explorer = new Explorer(&map);
}

void App::Input() {
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window->close();
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Space) {
				
			}
		}
	}
}

void App::Update(double step_size) {
	Input();
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

	window->clear(sf::Color::Blue);
	window->draw(backgroundSprite);

	sf::Vector2i pos;
	for (int i = 0; i < WINDOW_WIDTH * WINDOW_HEIGHT * 4; i++) {
		_pixelArray[i] = 0;
	}
	
	// Draw the tiles
	for (int x = 0; x < Map::CELLS_WIDTH; x++) {
		for (int y = 0; y < Map::CELLS_HEIGHT; y++) {
	
			pos.x = x;
			pos.y = y;
			sf::Color thing = map.getTile(pos)->getColor();
			

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
	
	// Draw the player
	
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
	
	pixel_array_texture.update(_pixelArray);
	
	pixel_array_sprite.setTexture(pixel_array_texture);
	window->draw(pixel_array_sprite);
	
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
	static __int64 start = 0;
	static __int64 frequency = 0;

	if (start == 0) {
		QueryPerformanceCounter((LARGE_INTEGER*)&start);
		QueryPerformanceFrequency((LARGE_INTEGER*)&frequency);
		return 0.0f;
	}

	__int64 counter = 0;
	QueryPerformanceCounter((LARGE_INTEGER*)&counter);
	return (float)((counter - start) / double(frequency));
}
