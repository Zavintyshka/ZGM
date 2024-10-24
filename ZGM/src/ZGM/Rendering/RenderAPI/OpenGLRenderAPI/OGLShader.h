#pragma once
#include "ZGM/Core.h"
#include "OGLCore.h"
#include "glm/gtc/matrix_transform.hpp"
#include "Tools/GeneralTools.h"
#include "ZGM/Rendering/Shader.h"


struct Vector4 {
	float x;
	float y;
	float z;
	float w;
};


namespace Render {
	class ZGM_API OGLShader : public Shader {
	private:
		// IDs
		unsigned int m_objectID;
		unsigned int m_vertexShaderID;
		unsigned int m_fragmentShaderID;
		std::unordered_map<std::string, int> m_locationCache;

		// Methods
		std::string GetShaderSourceCode(const std::string& filepath);
		unsigned int CompileShader(unsigned int type, const char* source);
		void AddVertexShader(const std::string& filepath);
		void AddFragmentShader(const std::string& filepath);
		
	public:
		OGLShader(std::string vertexShaderFilepath, std::string fragmentShaderFilepath);
		~OGLShader();

		unsigned int GetShaderID() const {
			return m_objectID;
		}

		void Link() const override;

		void Bind() const override;

		void Unbind() const override;

		unsigned int GetUniformLocation(const std::string& varName);

		void SetUniform(const std::string& varName, Vector4& vec4);

		void SetUniform1i(const std::string& varName, int value) override;

		void SetUniformMat4f(const std::string& varName, glm::mat4& matrix) override;
	};
}
