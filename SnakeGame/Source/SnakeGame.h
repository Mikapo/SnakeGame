#pragma once

#include "Application.h"

class SnakeGame
{
public:
	SnakeGame();

	void Start();

private:
	void BeginPlay();
	void Tick();
	void OnInput(int32_t Key, int32_t Scancode, int32_t Action, int32_t Mods);

	Application Window;
};

