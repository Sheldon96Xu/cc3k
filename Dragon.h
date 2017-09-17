#ifndef _DRAGON_H
#define _DRAGON_H
#include "Enemy.h"
#include "DragonHoard.h"

class Dragon : public Enemy 
{
//	std::unique_ptr<DragonHoard> theHoard;
	DragonHoard * theHoard;
public:
	Dragon();
	Dragon(DragonHoard *);
	~Dragon();
	void setHoard(DragonHoard *);
	int attack(Character *) override;
	int attackedBy(Character *) override;
};
#endif	
