#include "../include/Player.h"

/// @Author Michael R Ryan
/// @Author Sean Whelan
/// @Date 01/02/2020

Player::Player() :
	m_speed{ 3.0f }
{
}

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

	if (MathUtility::length(moveDirection) != 0.0f)
	{
		Person::move(MathUtility::normalise(moveDirection) * m_speed);

		// Wall collisions
		if (Person::getPosition().x + Person::getSize().x > GAME_WIDTH)
		{
			Person::setPosition(GAME_WIDTH - Person::getSize().x, Person::getPosition().y);
		}

		if (Person::getPosition().x < 0.0f)
		{
			Person::setPosition(0.0f, Person::getPosition().y);
		}

		if (Person::getPosition().y + Person::getSize().y > GAME_HEIGHT)
		{
			Person::setPosition(Person::getPosition().x, GAME_HEIGHT - Person::getSize().y);
		}

		if (Person::getPosition().y < 0.0f)
		{
			Person::setPosition(Person::getPosition().x, 0.0f);
		}
	}
}

void Player::winCheck()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		
	}

}