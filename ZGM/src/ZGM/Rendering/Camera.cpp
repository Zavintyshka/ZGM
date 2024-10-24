#include "zgmpch.h"
#include "Camera.h"

namespace Render {
	Camera::Camera(float winWidth, float winHeight)
	: m_winWidth(winWidth), m_winHeight(winHeight)
	{
		m_projMatrix = glm::ortho(0.0f, winWidth, 0.0f, winHeight, -1.0f, 1.0f);
		m_vpMatrix = m_projMatrix * m_viewMatrix;
	}

	void Camera::UpdateVP()
	{
		m_translation = glm::vec3(-m_posX, -m_posY, 0.0f);
		m_viewMatrix = glm::translate(m_identityMatrix, m_translation);
		m_vpMatrix = m_projMatrix * m_viewMatrix;
	}

	glm::vec2 Camera::GetPos() const
	{
		return glm::vec2(m_posX, m_posY);
	}

	glm::mat4 Camera::GetVPMatrix() const
	{
		return m_vpMatrix;
	}

	void Camera::SetPos(glm::vec2 pos)
	{
		m_posX = pos.x;
		m_posY = pos.y;
		UpdateVP();
	}
}


