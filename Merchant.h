#ifndef _MERCHANT_H
#define _MERCHANT_H
#include "Enemy.h"

class Merchant : public Enemy 
{
	static bool Hostile;
public:
	Merchant();
	~Merchant();
	bool isHostile();
	int attack(Character *) override;
	int attackedBy(Character *) override;
};
#endif	
