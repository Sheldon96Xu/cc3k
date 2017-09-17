#ifndef _GOBLIN_H
#define _GOBLIN_H
#include "Player.h"

class Goblin : public Player 
{
public:
	Goblin();
	~Goblin();
	int attack(Character *) override;
	int attackedBy(Character *) override;
};
#endif
