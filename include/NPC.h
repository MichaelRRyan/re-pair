#ifndef NPC_H
#define NPC_H

/// @Author Michael R Ryan
/// @Date 01/02/2020

#include "Person.h"

class NPC : public Person
{
public:
	void update();

private:
	Person m_person;
};

#endif // !NPC_H