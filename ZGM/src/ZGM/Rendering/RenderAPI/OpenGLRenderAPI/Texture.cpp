#include "zgmpch.h"
#include "Texture.h"


namespace Render {
	Texture::Texture(const std::string& filepath)
		: m_filepath(filepath), m_localBuffer(nullptr), m_width(0), m_height(0), m_BPP(0)
	{
#ifdef _DEBUG
		IsFileExists(filepath.c_str());
#endif

		stbi_set_flip_vertically_on_load(1);
		m_localBuffer = stbi_load(m_filepath.c_str(), &m_width, &m_height, &m_BPP, 4);
		glGenTextures(1, &m_objectID);
		Bind();
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_localBuffer);
		Unbind();

		if (m_localBuffer)
			stbi_image_free(m_localBuffer);

	}

	Texture::~Texture()
	{
		glDeleteTextures(1, &m_objectID);
	}

	void Texture::Bind(unsigned int slot) const
	{
		glActiveTexture(GL_TEXTURE0 + slot);
		glBindTexture(GL_TEXTURE_2D, m_objectID);
	}

	void Texture::Unbind() const
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	inline int Texture::GetWidth() const
	{
		return m_width;
	}

	inline int Texture::GetHeight() const
	{
		return m_height;
	}

	unsigned int Texture::GetID() const
	{
		return m_objectID;
	}
}

