#pragma once

#include <memory>
#include "Rendering/Buffers/Buffers.h"
#include "Rendering/Shading/Shader.h"

class Square
{
public:
	Square() = delete;

	static void Draw(glm::vec2 Position, float Scale = 1);

private:
	static void Initialize();

	static bool HasBeenInitialized;
	static std::unique_ptr<Buffers> SquareBuffers;
	static std::unique_ptr<Shader> ShaderPtr;
};

