#include "../include/Player.h"
#include <iostream>
void Player::move()
{
	sf::Vector2f moveDirection = { 0.0f, 0.0f };


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		moveDirection.x--;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		moveDirection.x++;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		moveDirection.y--;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		moveDirection.y++;
	}

	if (moveDirection.x != 0.0f || moveDirection.y != 0.0f)
	{

		if (moveDirection.x < 0.0f)
		{
			Person::move(-3.0f, 0.0f );
			//std::cout << "left" << std::endl;
		}
		
		if (moveDirection.x > 0.0f)
		{
			Person::move(3.0f, 0.0f);
		//	std::cout << "Right" << std::endl;
		}
		
		if (moveDirection.y < 0)
		{
			Person::move(0.0f, -3.0f);
		}
		
		if (moveDirection.y > 0)
		{
			Person::move(0.0f, 3.0f);
		}
	}
}
