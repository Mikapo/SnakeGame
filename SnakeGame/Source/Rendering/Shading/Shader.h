#pragma once

#include <array>
#include <glm/matrix.hpp>
#include <string>
#include <unordered_map>

class Shader
{
public:

	Shader(std::string_view frag_path, std::string_view fert_path);
    ~Shader();
    Shader(const Shader&) = delete;
    Shader(Shader&&) = delete;

    void operator=(const Shader&) = delete;
    void operator=(Shader&&) = delete;

	void bind() const noexcept;
    void unbind() const noexcept;
    void set_uniform4f(std::string_view name, float v1, float v2, float v3, float v4);
    void set_uniform4fv(std::string_view name, size_t count, const float* v);
    void set_uniform3f(std::string_view name, float v1, float v2, float v3);
    void set_uniform3fv(std::string_view name, size_t count, const float* v);
    void set_uniform2f(std::string_view name, float v1, float v2);;
    void set_uniform1f(std::string_view name, float v1);
    void set_uniform1i(std::string_view name, int32_t v1);
    void set_uniform1b(std::string_view name, bool v1);
    void set_uniform_mat4f(std::string_view name, const glm::mat4& matrix);

private:

    struct shader_source
    {
        std::string vertex_source;
        std::string fragment_source;
    };

    uint32_t create_shader(std::string_view vertex_shader, std::string_view fragment_shader);
    uint32_t compile_shader(uint32_t type, std::string_view source);
    std::string parse_shader(std::string_view filepath);
    int32_t get_uniform_location(std::string_view name);

    std::string m_frag_path;
    std::string m_fert_path;
    uint32_t m_shader_id;
    std::unordered_map<std::string_view, int32_t> m_uniform_location_cache;

};
