#pragma once

#include "ZGM/Core.h"
#include "OGLCore.h"
#include "stb_image/stb_image.h"
#include "Tools/GeneralTools.h"


namespace Render {
	class ZGM_API Texture {
	private:
		unsigned int m_objectID;
		std::string m_filepath;
		unsigned char* m_localBuffer;
		int m_width, m_height, m_BPP;
	public:
		Texture(const std::string& filepath);
		~Texture();
		void Bind(unsigned int slot = 0) const;
		void Unbind() const;
		inline int GetWidth() const;
		inline int GetHeight() const;
		unsigned int GetID() const;
	};
}

