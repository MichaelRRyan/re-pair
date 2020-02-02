/// @Author Michael Rainsford Ryan

#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "player.h"
#include "NPC.h"
#include "CameraController.h"

enum class GameState
{
	Licence,
	Splash,
	Gameplay,
	End
};

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

	void startRound();

	sf::RenderWindow m_window;
	bool m_exitGame;

	Player m_player;

	std::vector<NPC> m_npcs;

	CameraController m_cameraController;

	sf::Texture m_backgroundTexture;
	sf::Sprite m_backgroundSprite;

	GameState m_gamestate;

	sf::Clock m_gameTimer;

	sf::Font m_font;
	sf::Text m_text;

	sf::Texture m_spriteSheetTexture;

	sf::Texture m_overlayTexture;
	sf::Sprite m_overlaySprite;

	sf::Music m_backgroundMusic;
};

#endif // !GAME

