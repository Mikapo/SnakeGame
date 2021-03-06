#include "Index_buffer.h"

Index_buffer::Index_buffer(const void* data, size_t count) noexcept : m_count(count)
{
    glGenBuffers(1, &m_id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32_t) * count, data, GL_STATIC_DRAW);
}

Index_buffer::~Index_buffer() 
{ 
    glDeleteBuffers(1, &m_id); 
}

void Index_buffer::bind() const noexcept{ glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id); }

void Index_buffer::unbind() const noexcept { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }
