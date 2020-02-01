/// @Author Michael Rainsford Ryan

#include "../include/Game.h"
#include <iostream>

Game::Game() :
	m_window{ sf::VideoMode::getDesktopMode(), "Basic Game", sf::Style::Fullscreen },
	m_cameraController{ m_window },
	m_exitGame{ false },
	m_gamestate{ GameState::Gameplay }
{
	sf::View view = m_window.getDefaultView();

	float heightPerWidth = view.getSize().y / view.getSize().x;

	view.setSize(800.0f, 800.0f * heightPerWidth);

	view.setSize(view.getSize());


	m_window.setView(view);
	m_window.setVerticalSyncEnabled(true);

	if (!m_backgroundTexture.loadFromFile("images//Background.png"))
	{
		std::cout << "Error loading texture file" << std::endl;
	}

	m_backgroundSprite.setTexture(m_backgroundTexture);
	m_backgroundSprite.setPosition(-150.0f, -150.0f);

	if (!m_font.loadFromFile("Slabo.ttf"))
	{
		throw("Error loading font file");
	}

	m_text.setFont(m_font);
	m_text.setFillColor(sf::Color::Black);

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
		if (sf::Event::KeyPressed == nextEvent.type)
		{
			if (m_gamestate == GameState::End)
			{
				if (sf::Keyboard::Space == nextEvent.key.code)
				{
					startRound();
				}
			}
			if (sf::Keyboard::Escape == nextEvent.key.code)
			{
				m_window.close();
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

		float elapsedSeconds = m_gameTimer.getElapsedTime().asSeconds();

		m_text.setString(std::to_string(20 - static_cast<int>(elapsedSeconds)));
		m_text.setPosition(m_player.getPosition().x + m_player.getSize().x / 2.0f, m_player.getPosition().y + m_player.getSize().y);
		m_text.setOrigin(m_text.getGlobalBounds().width / 2.0f, 0.0f);

		if (elapsedSeconds >= 20.0f)
		{
			m_gamestate = GameState::End;
		}
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

		m_window.draw(m_text);
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

	m_gameTimer.restart();
}