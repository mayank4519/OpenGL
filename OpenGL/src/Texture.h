#pragma once

#include "Renderer.h"

class Texture {
private:
	unsigned int m_RendererId;
	std::string m_FilePath;
	unsigned char* m_LocalBuffer;
	int m_Width, m_Height, m_BPP;

public:
	Texture(const std::string& path);
	~Texture();
	inline int GetWidth() const { return m_Width; }
	inline int getHeigth() const { return m_Height; }

	void Bind(unsigned int slot = 0) const;
	void UnBind() const;
};