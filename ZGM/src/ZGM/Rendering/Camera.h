#pragma once
#include "ZGM/Core.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace Render {
	class ZGM_API Camera {
	private:
		float m_winWidth = 0.0f, m_winHeight = 0.0f;

		// camera transform
		glm::vec2 m_position = glm::vec2(0.0f, 0.0f);
		float m_rotation = 0.0f;

		glm::vec3 m_translation = glm::vec3(0.0f, 0.0f, 0.0f);
		glm::mat4 m_identityMatrix = glm::mat4(1.0f);

		glm::mat4 m_viewMatrix = glm::translate(m_identityMatrix, m_translation);
		glm::mat4 m_projMatrix = m_identityMatrix;
		
		glm::mat4 m_vpMatrix = m_identityMatrix;

		Camera() {};


	public:

		void UpdateVP();
		static Camera& GetCamera() {
			static Camera instance;
			return instance;
		}

		void Initialize(float winWidth, float winHeight);

		const glm::vec2& GetPos() const;
		void SetPos(glm::vec2& pos);
		const float GetRotation() const;
		void SetRotation(float rotation);

		const glm::mat4& GetVPMatrix() const;
	};
}