#include "Square.h"

#include <vector>
#include "glm/ext/matrix_transform.hpp"

bool Square::HasBeenInitialized = false;
std::unique_ptr<Buffers> Square::SquareBuffers;
std::unique_ptr<Shader> Square::ShaderPtr;

void Square::Draw(glm::vec2 Position, float Scale)
{
	if (!HasBeenInitialized)
		Initialize();

	const glm::mat4 Identity = glm::mat4(1);
	const glm::mat4 Translate = glm::translate(Identity, glm::vec3(Position, 0));
	const glm::mat4 ScaleMat = glm::scale(Identity, glm::vec3(Scale, Scale, 1));
	const glm::mat4 Model = Translate * ScaleMat;

	ShaderPtr->set_uniform_mat4f("u_model", Model);
	ShaderPtr->bind();
	SquareBuffers->bind();

	glDrawElements(GL_TRIANGLES, SquareBuffers->get_indices_count(), GL_UNSIGNED_INT, nullptr);
}

void Square::Initialize()
{
	std::vector<float> Vertices
	{
		-1, -1,  0,
		 1, -1,  0,
		 1,  1,  0,
		-1,  1,  0
	};

	std::vector<uint32_t> Indices
	{
		0, 1, 2,
		0, 2, 3
	};

	Vertex_buffer_layout Layout;
	Layout.push<float>(3);

	SquareBuffers = std::make_unique<Buffers>(std::move(Vertices), std::move(Indices), Layout);
	ShaderPtr = std::make_unique<Shader>("Shaders/Shader.frag", "Shaders/Shader.vert");

	HasBeenInitialized = true;
}
