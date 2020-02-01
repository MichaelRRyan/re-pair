#ifndef PERSON_H
#define PERSON_H

/// @Author Michael R Ryan
/// @Date 01/02/2020

#include <SFML/Graphics.hpp>
#include "Config.h"

class Person : public sf::Drawable
{
public:
	Person();
	Person(float const t_x, float const t_y);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	const sf::Vector2f getPosition() const;
	void setPosition(float t_x, float t_y);

protected:
	void move(float t_x, float t_y);
	void move(sf::Vector2f t_vector);

	const sf::Vector2f getSize() const;

private:
	sf::RectangleShape m_boundingBox;
};

#endif // !PERSON_H