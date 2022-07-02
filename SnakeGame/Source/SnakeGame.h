#pragma once

#include "Application.h"

class SnakeGame
{
public:
	SnakeGame();

	void Start();

private:
	// gets called on begining of the game
	void BeginPlay();

	// gets called every frame
	void Tick();

	// gets called on input
	void OnInput(int32_t Key, int32_t Scancode, int32_t Action, int32_t Mods);

	Application Window;
};

