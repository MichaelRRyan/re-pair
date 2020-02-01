#ifndef CAMERA_CONTROLLER_H
#define CAMERA_CONTROLLER_H

/// @Author Michael R Ryan
/// @Date 01/02/2020

#include <SFML/Graphics.hpp>

class CameraController
{
public:
	CameraController(sf::RenderWindow & t_window);

	void moveWindow(sf::Vector2f t_targetPos);

	void setSmoothness(float t_snapSpeed);

private:
	sf::RenderWindow & m_windowRef;
	sf::View m_view;
	float m_smoothness;
};

#endif // CAMERA_CONTROLLER_H