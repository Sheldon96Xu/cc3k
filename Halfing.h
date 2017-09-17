#ifndef _HALFING_H
#define _HALFING_H
#include "Enemy.h"

class Halfing : public Enemy 
{
public:
	Halfing();
	~Halfing();
	int attack(Character *) override;
	int attackedBy(Character *) override;
};
#endif	
