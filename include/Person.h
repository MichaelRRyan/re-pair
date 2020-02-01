#ifndef NPC_H
#define NPC_H

/// @Author Michael R Ryan
/// @Date 01/02/2020

#include <SFML/Graphics.hpp>

class Person : public sf::Drawable
{
public:
	Person();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::RectangleShape m_boundingBox;
};

#endif // !NPC_H