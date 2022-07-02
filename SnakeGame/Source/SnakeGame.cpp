#include "SnakeGame.h"
#include "Square.h"
#include <iostream>

SnakeGame::SnakeGame()
{
	Window.set_window_dimensions(1000, 1000);
	Window.set_window_title("SnakeGame");

	Window.set_on_key_event_callback(this, &SnakeGame::OnInput);
	Window.set_render_callback(this, &SnakeGame::Tick);
	Window.set_on_window_open_callback(this, &SnakeGame::BeginPlay);
}

void SnakeGame::Start()
{
	Window.start();
}

void SnakeGame::BeginPlay()
{
	// here we change coordinate system of square
	// which means that left bottom corner of screen is x = 0.0f, y = 0.0f
	// and top right corner of screen is x = 20.0f, y = 20.0f
	// you can change this to anything you want
	Square::Get().ChangeCoordinateSystem({ 0.0f, 0.0f }, { 20.0f, 20.0f });
}

void SnakeGame::Tick()
{
	//draw needs to be called every frame where you want square to be rendered
	//arguments to draw are { position, scale, color }
	//color is 4d vector in RGBA format so x = red, y = green, z = blue, a = alpha
	Square::Get().Draw({5.0f, 5.0f }, 1.0f, {1.0f, 0.0f, 0.0f, 1.0f});


	Square::Get().Draw({16.0f, 16.0f}, 1.0f, {0.0f, 1.0f, 0.0f, 1.0f});
}

void SnakeGame::OnInput(int32_t Key, int32_t Scancode, int32_t Action, int32_t Mods)
{
	if (Action == GLFW_PRESS)
	{
		if (Key == GLFW_KEY_A)
			std::cout << "A pressed \n";

		else if(Key == GLFW_KEY_B)
			std::cout << "B pressed \n";
	}
}
