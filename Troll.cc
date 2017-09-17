#include "Troll.h"

Troll::Troll(): Player{120, 25, 15} { Sym = 'T'; }

Troll::~Troll() {}

int Troll::attack(Character * c) { 
	HP += 5;
	if (HP > 120) HP = 120;
	return regularDamage(c); 
}

int Troll::attackedBy(Character * c) { 
	srand(time(0));
	int miss = rand() % 2;
    if (miss == 0) {
		return c->attack(this); 
	}
	else return -1; 
}
