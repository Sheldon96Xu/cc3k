#ifndef _DWARF_H
#define _DWARF_H
#include "Enemy.h"

class Dwarf : public Enemy 
{
public:
	Dwarf();
	~Dwarf();
	int attack(Character *) override;
	int attackedBy(Character *) override;
};
#endif
