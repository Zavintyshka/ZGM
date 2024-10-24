#include "zgmpch.h"
#include "Camera.h"

namespace Render {
	void Camera::UpdateVP()
	{
		m_translation = glm::vec3(-m_position.x, -m_position.y, 0.0f);
		m_viewMatrix = glm::translate(m_identityMatrix, m_translation) * glm::rotate(m_identityMatrix, glm::radians(m_rotation), glm::vec3(0.0f, 0.0f, 1.0f));
		m_vpMatrix = m_projMatrix * m_viewMatrix;
	}

	void Camera::Initialize(float winWidth, float winHeight)
	{
		m_winWidth = winWidth;
		m_winHeight = winHeight;

		m_projMatrix = glm::ortho(0.0f, m_winWidth, 0.0f, m_winHeight, -1.0f, 1.0f);
		m_vpMatrix = m_projMatrix * m_viewMatrix;
	}

	const glm::vec2& Camera::GetPos() const
	{
		return m_position;
	}

	const glm::mat4& Camera::GetVPMatrix() const
	{
		return m_vpMatrix;
	}

	void Camera::SetPos(glm::vec2& pos)
	{	
		m_position = pos;
	}
	const float Camera::GetRotation() const
	{
		return m_rotation;
	}
	void Camera::SetRotation(float rotation)
	{
		m_rotation = rotation;
	}
}


