#ifndef _JEFF_H
#define _JEFF_H
#include "Player.h"

class Jeff : public Player 
{
public:
	Jeff();
	~Jeff();
	int attack(Character *) override;
	int attackedBy(Character *) override;
};
#endif
