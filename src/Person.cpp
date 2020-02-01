#include "../include/Person.h"

///////////////////////////////////////////////////////////////////////////////
Person::Person()
{
    m_boundingBox.setFillColor(sf::Color{ static_cast<sf::Uint8>(rand() % 255),static_cast<sf::Uint8>(rand() % 255),static_cast<sf::Uint8>(rand() % 255) });
    m_boundingBox.setPosition((GAME_WIDTH / 2.0f) - (getSize().x / 2.0f), (GAME_HEIGHT / 2.0f) - (getSize().y / 2.0f));
    m_boundingBox.setSize({ 30.0f, 60.0f });
}

///////////////////////////////////////////////////////////////////////////////
Person::Person(float const t_x, float const t_y)
{
    m_boundingBox.setFillColor(sf::Color{ static_cast<sf::Uint8>(rand() % 255),static_cast<sf::Uint8>(rand() % 255),static_cast<sf::Uint8>(rand() % 255) });
    m_boundingBox.setPosition(t_x, t_y);
    m_boundingBox.setSize({ 30.0f, 60.0f });
}

///////////////////////////////////////////////////////////////////////////////
void Person::move(float t_x, float t_y)
{
    m_boundingBox.move(t_x, t_y);
}

///////////////////////////////////////////////////////////////////////////////
void Person::move(sf::Vector2f t_vector)
{
    m_boundingBox.move(t_vector);
}

///////////////////////////////////////////////////////////////////////////////
const sf::Vector2f Person::getPosition() const
{
	return m_boundingBox.getPosition();
}

///////////////////////////////////////////////////////////////////////////////
const sf::Vector2f Person::getSize() const
{
    return { m_boundingBox.getGlobalBounds().width, m_boundingBox.getGlobalBounds().height };
}

///////////////////////////////////////////////////////////////////////////////
void Person::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // You can draw other high-level objects
    target.draw(m_boundingBox, states);
}
