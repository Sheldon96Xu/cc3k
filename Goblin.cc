#include "Goblin.h"
#include "Orcs.h"

Goblin::Goblin(): Player{110, 15, 20} { Sym = 'G'; }

Goblin::~Goblin() {}

int Goblin::attack(Character * c) { 
	int damage = regularDamage(c);
	if (c->getHP() == 0) Gold += 5;
	return damage; 
}

int Goblin::attackedBy(Character * c) {
	srand(time(0));
	int miss = rand() % 2;
    if (miss == 0) {
		return c->attack(this); 
	}
	else return -1;
}
