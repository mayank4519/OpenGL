#pragma once
#include "VertexBuffer.h"

class VertexBufferLayout;
class VertexArray {
	unsigned int m_Renderer_Id;
public:
	VertexArray();
	~VertexArray();

	void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);

	void Bind() const;
	void UnBind() const;
};