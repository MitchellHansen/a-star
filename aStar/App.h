#pragma once
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Explorer.h"

template<typename T, int width, int height>
class MultiArray {
private:
	typedef T cols[height];
	cols * data;
public:
	T& operator() (int x, int y) { return data[x][y]; }
	MultiArray() { data = new cols[width]; }
	~MultiArray() { delete[] data; }
};
class App {
public:
	// Constants
	static const int WINDOW_HEIGHT = 766;
	static const int WINDOW_WIDTH = 1596;
	const double PI = 3.141592653589793238462643383279;

	App();
	~App();

	// Start the app
	void Run();

private:

	Map map;
	sf::Uint8* _pixelArray;
	sf::Sprite pixel_array_sprite;
	sf::Texture pixel_array_texture;

	Explorer* explorer;

	// Art assets
	sf::Texture* background_texture;

	sf::Sprite backgroundSprite;

	void Init();
	void Input();
	void Update(double step_size);
	void Render();

	// The main render window, probably should think about supporting multiple of these
	sf::RenderWindow* window;
	// The events for the event handler
	sf::Event event;

	// Loop management data, black magic, need to redo
	float time();

	// Size of the physics steps to take
	float step_size = 0.005f;

	double current_time = 0.0;
	double frame_time = 0.0;
	double instant_fps = 0.0;
	double accumulator_time = 0.0;

	int render_frame_count = 0;
	double render_fps = 0;

	int physics_frame_count = 0;
	double physics_fps = 0;

	double elapsed_time = 0;
	double delta_time = 0;
};
