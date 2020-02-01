/// @Author Michael Rainsford Ryan

#include "../include/Game.h"
#include <iostream>

Game::Game() :
	m_window{ sf::VideoMode{ 800u, 600u, 32u }, "Basic Game" },
	m_exitGame{ false }
{
	setupShapes();
}

Game::~Game()
{

}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float FPS = 60.0f;
	sf::Time timePerFrame = sf::seconds(1.0f / FPS); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // Run as many times as possible
		timeSinceLastUpdate += clock.restart();
		if (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // Run at a minimum of 60 fps
			update(timePerFrame); // 60 fps
		}
		render(); // Run as many times as possible
	}
}

void Game::processEvents()
{
	sf::Event nextEvent;
	while (m_window.pollEvent(nextEvent))
	{
		if (sf::Event::Closed == nextEvent.type) // check if the close window button is clicked on.
		{
			m_window.close();
		}
	}
}

void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}

	sf::Vector2f moveDirection = { 0.0f, 0.0f };

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		moveDirection.x--;
		//std::cout << "left" << std::endl;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		moveDirection.x++;
		//std::cout << "Right" << std::endl;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		moveDirection.y--;
		//std::cout << "Up" << std::endl;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		moveDirection.y++;
		//std::cout << "Down" << std::endl;
	}

	if (moveDirection.x != 0.0f && moveDirection.y != 0.0f)
	{
		m_player.move();
	}

	for (NPC& npc : m_npcs)
	{
		npc.update();
	}
}

void Game::render()
{
	m_window.clear();

	for (NPC& npc : m_npcs)
	{
		m_window.draw(npc);
	}

	m_window.draw(m_player);
	
	m_window.display();
}

void Game::setupShapes()
{
	for (int i = 0; i < NPC_NUM; i++)
	{
		m_npcs.push_back(NPC());
	}
}