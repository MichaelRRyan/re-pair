/// @Author Michael Rainsford Ryan

#include "../include/Game.h"
#include <iostream>

Game::Game() :
	m_window{ sf::VideoMode{ 800u, 600u, 32u }, "Basic Game" },
	m_cameraController{ m_window },
	m_exitGame{ false },
	m_gamestate{ GameState::Gameplay }
{
	if (!m_backgroundTexture.loadFromFile("images//Background.png"))
	{
		std::cout << "Error loading texture file" << std::endl;
	}

	m_backgroundSprite.setTexture(m_backgroundTexture);
	m_backgroundSprite.setPosition(-150.0f, -150.0f);

	startRound();
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

		if (m_gamestate == GameState::End
			&& sf::Event::KeyPressed == nextEvent.type)
		{
			if (sf::Keyboard::Space == nextEvent.key.code)
			{
				startRound();
			}
		}
	}
}

void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}

	if (m_gamestate == GameState::Splash
		|| m_gamestate == GameState::Gameplay)
	{
		for (NPC& npc : m_npcs)
		{
			npc.update();
		}
	}

	if (m_gamestate == GameState::Gameplay)
	{
		if (m_player.winCheck())
		{
			m_gamestate = GameState::End;
		}

		m_player.update();

		m_cameraController.moveWindow(m_player.getPosition());
	}
}

void Game::render()
{
	m_window.clear(sf::Color::White);

	if (m_gamestate == GameState::Splash
		|| m_gamestate == GameState::Gameplay)
	{
		m_window.draw(m_backgroundSprite);

		for (NPC& npc : m_npcs)
		{
			m_window.draw(npc);
		}

		m_window.draw(m_player);
	}
	
	m_window.display();
}

void Game::startRound()
{
	m_cameraController.reset();

	m_player.setup();

	m_npcs.clear();

	for (int i = 0; i < NPC_NUM; i++)
	{
		m_npcs.push_back(NPC());
	}

	int index = rand() % NPC_NUM;
	m_player.setTarget(&m_npcs.at(index));
	m_npcs.at(index).setPerson(&m_player);

	m_gamestate = GameState::Gameplay;
}