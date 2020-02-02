#include "../include/GUI.h"

GUI::GUI()
{
	if (!m_buttonsTexture.loadFromFile("images//buttons.png"))
	{
		throw("Error loading button sprites");
	}
	if (!m_licenceTexture.loadFromFile("images//licence.png"))
	{
		throw("Error loading licence sprites");
	}

	m_playButtonSprite.setTexture(m_buttonsTexture);
	m_exitButtonSprite.setTexture(m_buttonsTexture);
	m_licenceSprite.setTexture(m_licenceTexture);

	m_licenceSprite.setOrigin(m_licenceSprite.getGlobalBounds().width / 2.0f, m_licenceSprite.getGlobalBounds().height / 2.0f);
	m_licenceSprite.setPosition(400.0f, 300.0f);

	m_playButtonSprite.setTextureRect({ 0,0,77,77 });
	m_exitButtonSprite.setTextureRect({ 77,0,77,77 });

	m_playButtonSprite.setOrigin(m_playButtonSprite.getGlobalBounds().width / 2.0f, m_playButtonSprite.getGlobalBounds().height / 2.0f);
	m_exitButtonSprite.setOrigin(m_exitButtonSprite.getGlobalBounds().width / 2.0f, m_exitButtonSprite.getGlobalBounds().height / 2.0f);

	m_playButtonSprite.setPosition(400.0f, 200.0f);
	m_exitButtonSprite.setPosition(400.0f, 300.0f);

	m_selectCircle.setRadius(40.0f);
	m_selectCircle.setFillColor(sf::Color::Transparent);
	m_selectCircle.setOutlineColor(sf::Color{ 0,0,100,100 });
	m_selectCircle.setOutlineThickness(2.0f);
	m_selectCircle.setOrigin(m_selectCircle.getRadius(), m_selectCircle.getRadius());

	m_selectCircle.setPosition(m_playButtonSprite.getPosition());
}

void GUI::draw(sf::RenderWindow& t_window, GameState t_gameState)
{
	if (GameState::Splash == t_gameState)
	{
		t_window.draw(m_playButtonSprite);
		t_window.draw(m_exitButtonSprite);
		t_window.draw(m_selectCircle);
	}
	else if (GameState::Licence == t_gameState)
	{
		t_window.draw(m_licenceSprite);
	}
}

void GUI::processEvents(sf::Event const& t_event, sf::Music& t_music, sf::Clock& t_clock, GameState& t_gamestate, sf::RenderWindow& t_window)
{
	if (sf::Keyboard::Down == t_event.key.code || sf::Keyboard::Up == t_event.key.code)
	{
		if (m_selectCircle.getPosition() == m_playButtonSprite.getPosition())
		{
			m_selectCircle.setPosition(m_exitButtonSprite.getPosition());
		}
		else
		{
			m_selectCircle.setPosition(m_playButtonSprite.getPosition());
		}
	}
	if (sf::Keyboard::Space == t_event.key.code)
	{
		if (m_selectCircle.getPosition() == m_playButtonSprite.getPosition())
		{
			t_music.stop();
			t_music.play();

			t_gamestate = GameState::Gameplay;

			t_clock.restart();
		}
		else
		{
			t_window.close();
		}
	}
}
