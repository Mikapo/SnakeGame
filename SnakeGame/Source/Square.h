#pragma once

#include <memory>
#include "Rendering/Buffers/Buffers.h"
#include "Rendering/Shading/Shader.h"

class Square
{
public:
	static Square& Get();
	void ChangeCoordinateSystem(glm::vec2 Min, glm::vec2 Max);
	void Draw(glm::vec2 Position, float Scale = 1, glm::vec4 Color = {0.9f, 0.9f, 0.9f, 1.0f});

private:
	Square();
	~Square() = default;

	 glm::mat4 Projection = glm::mat4(1);
	 std::unique_ptr<Buffers> SquareBuffers = nullptr;
	 std::unique_ptr<Shader> ShaderPtr = nullptr;
};

