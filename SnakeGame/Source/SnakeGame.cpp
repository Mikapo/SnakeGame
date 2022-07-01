#include "SnakeGame.h"
#include "Square.h"
#include <iostream>

void SnakeGame::Start()
{
	Window.set_on_key_event_callback(this, &SnakeGame::OnInput);
	Window.set_render_callback(this, &SnakeGame::Tick);
	Window.start();
}

void SnakeGame::Tick()
{
	Square::Draw({-1.0f, -1.0f }, 0.3f);
	Square::Draw({-0.5f, 0.0f }, 0.3f);
}

void SnakeGame::OnInput(int32_t Key, int32_t Scancode, int32_t Action, int32_t Mods)
{
	if (Action == GLFW_PRESS)
		std::cout << "key pressed\n";
}
