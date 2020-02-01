#ifndef NPC_H
#define NPC_H

/// @Author Michael R Ryan
/// @Date 01/02/2020

#include "Person.h"
#include "Matrix3f.h"
#include "Config.h"

class NPC : public Person
{
public:
	NPC();

	void update();

private:
	Person m_person;
	sf::Vector2f m_velocity;
};

#endif // !NPC_H