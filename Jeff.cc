#include "Jeff.h"

Jeff::Jeff(): Player{999999, 999, 999} { Sym = 'J'; }

Jeff::~Jeff() {}

int Jeff::attack(Character * c) { return regularDamage(c); }

int Jeff::attackedBy(Character * c) { 
	srand(time(0));
	int miss = rand() % 2;
    if (miss == 0) {
		return c->attack(this); 
	}
	else return -1;
}
