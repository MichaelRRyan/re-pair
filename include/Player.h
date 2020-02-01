#ifndef PLAYER_H
#define PLAYER_H

/// @Author Michael R Ryan
/// @Author Sean Whelan
/// @Date 01/02/2020

#include "Person.h"

class Player : public Person
{
	
public:
	void move();
	void winCheck();
};

#endif // !PLAYER_H