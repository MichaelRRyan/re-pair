#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Config.h"

class GUI
{
public:
	GUI();

	void draw(sf::RenderWindow & t_window, GameState t_gameState);

	void processEvents(sf::Event const & t_event, sf::Music & t_music, sf::Clock & t_clock, GameState &t_gamestate, sf::RenderWindow & t_window);

private:

	sf::Texture m_buttonsTexture;
	sf::Texture m_licenceTexture;

	sf::Sprite m_playButtonSprite;
	sf::Sprite m_exitButtonSprite;
	sf::Sprite m_licenceSprite;

	sf::CircleShape m_selectCircle;
};