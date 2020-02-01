#include "../include/Person.h"

///////////////////////////////////////////////////////////////////////////////
Person::Person()
{
    m_boundingBox.setFillColor(sf::Color{ static_cast<sf::Uint8>(rand() % 255),static_cast<sf::Uint8>(rand() % 255),static_cast<sf::Uint8>(rand() % 255) });
    m_boundingBox.setPosition(400.0f, 200.0f);
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
void Person::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // You can draw other high-level objects
    target.draw(m_boundingBox, states);
}
