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
	Square::Get().ChangeCoordinateSystem({ 0.0f, 0.0f }, { 20.0f, 20.0f });
}

void SnakeGame::Tick()
{
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
