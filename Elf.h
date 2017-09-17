#ifndef _ELF_H
#define _ELF_H
#include "Enemy.h"

class Elf : public Enemy 
{
public:
	Elf();
	~Elf();
	int attack(Character *) override;
	int attackedBy(Character *) override;
};
#endif
