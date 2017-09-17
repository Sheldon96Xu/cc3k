#ifndef _VAMPIRE_H
#define _VAMPIRE_H
#include "Player.h"

class Vampire : public Player 
{
public:
	Vampire();
	~Vampire();
	int attack(Character *) override;
	int attackedBy(Character *) override;
};
#endif
