#ifndef _SHADE_H
#define _SHADE_H
#include "Player.h"

class Shade : public Player 
{
public:
	Shade();
	~Shade();
	int attack(Character *) override;
	int attackedBy(Character *) override;
};
#endif
