#ifndef _DROW_H
#define _DROW_H
#include "Player.h"

class Drow : public Player 
{
public:
	Drow();
	~Drow();
	int attack(Character *) override;
	int attackedBy(Character *) override;
};
#endif
