#ifndef _TROLL_H
#define _TROLL_H
#include "Player.h"

class Troll : public Player 
{
public:
	Troll();
	~Troll();
	int attack(Character *) override;
	int attackedBy(Character *) override;
};
#endif
