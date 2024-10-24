#pragma once
#include "ZGM/Core.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace Render {
	class ZGM_API Camera {
	private:
		float m_posX = 0, m_posY = 0;
		float m_winWidth, m_winHeight;

		glm::vec3 m_translation = glm::vec3(-m_posX, -m_posY, 0.0f);
		glm::mat4 m_identityMatrix = glm::mat4(1.0f);

		glm::mat4 m_viewMatrix = glm::translate(m_identityMatrix, m_translation);
		glm::mat4 m_projMatrix;
		
		glm::mat4 m_vpMatrix;

		Camera(float winWidth, float winHeight);

		void UpdateVP();
		

	public:
		static Camera& CreateCamera(float winWidth, float winHeight) {
			static Camera instance(winWidth, winHeight);
			return instance;
		}

		glm::vec2 GetPos() const;
		glm::mat4 GetVPMatrix() const;
		void SetPos(glm::vec2 pos);
	};
}