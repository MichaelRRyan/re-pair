#ifndef PLAYER_H
#define PLAYER_H

/// @Author Michael R Ryan
/// @Author Sean Whelan
/// @Date 01/02/2020

#include "Person.h"
#include "Config.h"
#include "MathUtility.h"

class Player : public Person
{
public:
	Player();

	void move();
	void winCheck();

private:
	float m_speed;
};

#endif // !PLAYER_H