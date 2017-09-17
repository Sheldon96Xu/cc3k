#include "Shade.h"

Shade::Shade(): Player{125, 25, 25} { Sym = 'S'; }

Shade::~Shade() {}

int Shade::attack(Character * c) { return regularDamage(c); }

int Shade::attackedBy(Character * c) { 
	srand(time(0));
	int miss = rand() % 2;
    if (miss == 0) {
		return c->attack(this); 
	}
	else return -1;
}
