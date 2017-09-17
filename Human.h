#ifndef _HUMAN_H
#define _HUMAN_H
#include "Enemy.h"

class Human : public Enemy 
{
public:
	Human();
	~Human();
	int attack(Character *) override;
	int attackedBy(Character *) override;
};
#endif
