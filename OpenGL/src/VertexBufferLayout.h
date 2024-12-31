#pragma once
#include <vector>
#include "Renderer.h"

struct VertexBufferElement {
	 int type;
	 unsigned int count;
	 unsigned char normalised;

	 static unsigned int GetSizeOfType(unsigned int type)
	 {
		 switch (type)
		 {
		 case GL_FLOAT: return sizeof(GLfloat);
		 case GL_UNSIGNED_INT: return sizeof(GLuint);
		 case GL_UNSIGNED_BYTE: return sizeof(GLbyte);
		 }
		 ASSERT(false);
		 return 0;
	 }
};

class VertexBufferLayout {
private:
	std::vector<VertexBufferElement> m_Elements;
	unsigned int m_stride;

public:
	VertexBufferLayout() : m_stride(0) {}

	template <typename T>
	void Push(unsigned int count)
	{
		static_assert(false);
	}

	template<>
	void Push<float>(unsigned int count)
	{
		m_Elements.push_back({GL_FLOAT, count, GL_FALSE});
		m_stride += VertexBufferElement::GetSizeOfType(GL_FLOAT) * count;
	}

	template<>
	void Push<unsigned int>(unsigned int count)
	{
		m_Elements.push_back({ GL_UNSIGNED_INT, count, GL_FALSE });
		m_stride += VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT) * count;
	}

	template<>
	void Push<char>(unsigned int count)
	{
		m_Elements.push_back({ GL_BYTE, count, GL_TRUE });
		m_stride += VertexBufferElement::GetSizeOfType(GL_BYTE) * count;
	}

	inline const std::vector<VertexBufferElement> GetElements() const { return m_Elements; }
	inline unsigned int GetStride() const { return m_stride; }
};