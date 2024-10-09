#pragma once
#include "ZGM/Core.h"
#include "General.h"
#include "glm/gtc/matrix_transform.hpp"


struct Vector4 {
	float x;
	float y;
	float z;
	float w;
};


class ZGM_API Shader {
private:
	// IDs
	unsigned int m_objectID;
	unsigned int m_vertexShaderID;
	unsigned int m_fragmentShaderID;
	std::unordered_map<std::string, int> m_locationCache;

	std::string GetShaderSourceCode(const std::string& filepath);
	unsigned int CompileShader(unsigned int type, const char* source);


public:
	Shader();
	~Shader();

	unsigned int GetShaderID() const {
		return m_objectID;
	}

	void AddVertexShader(const std::string& filepath);
	void AddFragmentShader(const std::string& filepath);

	void LinkAndValidate() const;
	
	void BindShader() const;

	void UnbindShader() const;

	unsigned int GetUniformLocation(const std::string& varName);

	void SetUniform(const std::string& varName, Vector4& vec4);

	void SetUniform1i(const std::string& varName, int value);

	void SetUniformMat4f(const std::string& varName, glm::mat4& projMatrix);
	
};