#include "../include/CameraController.h"

/// @Author Michael R Ryan
/// @Date 01/02/2020

CameraController::CameraController(sf::RenderWindow & t_window) :
	m_windowRef{ t_window },
	m_view{ t_window.getDefaultView() }
{
}

///////////////////////////////////////////////////////////////////////////////
void CameraController::moveWindow(sf::Vector2f t_targetPos)
{
	sf::Vector2f distanceVec = t_targetPos - m_view.getCenter();
	m_view.setCenter(m_view.getCenter() + (distanceVec / 2.0f));
}
