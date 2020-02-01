#ifndef PERSON_H
#define PERSON_H

/// @Author Michael R Ryan
/// @Date 01/02/2020

#include <SFML/Graphics.hpp>

class Person : public sf::Drawable
{
public:
	Person();

	void move(float t_x, float t_y);
	void move(sf::Vector2f t_vector);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::RectangleShape m_boundingBox;
};

#endif // !PERSON_H