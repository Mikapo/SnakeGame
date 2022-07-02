#include "Square.h"

#include <vector>
#include "glm/ext/matrix_transform.hpp"
#include "glm/ext/matrix_clip_space.hpp"
#include "gsl/gsl"

Square::Square()
{
	std::vector<float> Vertices
	{
		-1, -1,
		 1, -1,
		 1,  1,
		-1,  1
	};

	std::vector<uint32_t> Indices
	{
		0, 1, 2,
		0, 2, 3
	};

	Vertex_buffer_layout Layout;
	Layout.push<float>(2);

	SquareBuffers = std::make_unique<Buffers>(std::move(Vertices), std::move(Indices), Layout);
	ShaderPtr = std::make_unique<Shader>("Shaders/Shader.frag", "Shaders/Shader.vert");
}

Square& Square::Get()
{
	static Square Instance;
	return Instance;
}

void Square::ChangeCoordinateSystem(glm::vec2 Min, glm::vec2 Max)
{
	Projection = glm::ortho(Min.x, Max.x, Min.y, Max.y);
}

void Square::Draw(glm::vec2 Position, float Scale, glm::vec4 Color)
{
	const glm::mat4 Identity = glm::mat4(1);
	const glm::mat4 Translate = glm::translate(Identity, glm::vec3(Position, 0));
	const glm::mat4 ScaleMat = glm::scale(Identity, glm::vec3(Scale, Scale, 1));
	const glm::mat4 Model = Translate * ScaleMat;

	ShaderPtr->set_uniform_mat4f("u_model", Model);
	ShaderPtr->set_uniform_mat4f("u_projection", Projection);
	ShaderPtr->set_uniform4f("u_color", Color.r, Color.g, Color.b, Color.a);
	ShaderPtr->bind();
	SquareBuffers->bind();

	GLsizei IndicesCount = gsl::narrow<GLsizei>(SquareBuffers->get_indices_count());
	glDrawElements(GL_TRIANGLES, IndicesCount, GL_UNSIGNED_INT, nullptr);
}
