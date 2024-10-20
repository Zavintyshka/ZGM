#pragma once

namespace Render {
	class ZGM_API Shader {
	public:
		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;
		virtual void Link() const = 0;
		virtual void SetUniform1i(const std::string& varName, int value) = 0;
	};
}