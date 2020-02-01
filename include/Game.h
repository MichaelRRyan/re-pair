/// @Author Michael Rainsford Ryan

#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
#include <vector>
#include "player.h"
#include "NPC.h"
#include "CameraController.h"

class Game
{
public:

	Game();
	~Game();

	void run();

private:

	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();

	void setupShapes();

	sf::RenderWindow m_window;
	bool m_exitGame;

	Player m_player;

	std::vector<NPC> m_npcs;

	CameraController m_cameraController;

	sf::Texture m_backgroundTexture;
	sf::Sprite m_backgroundSprite;
};

#endif // !GAME

