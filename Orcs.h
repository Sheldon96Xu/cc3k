#ifndef _ORCS_H
#define _ORCS_H
#include "Enemy.h"

class Orcs : public Enemy 
{
public:
	Orcs();
	~Orcs();
	int attack(Character *) override;
	int attackedBy(Character *) override;
};
#endif
