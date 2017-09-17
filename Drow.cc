#include "Drow.h"

Drow::Drow(): Player{150, 25, 15} { Sym = 'D'; }

Drow::~Drow() {}

int Drow::attack(Character * c) { return regularDamage(c); }

int Drow::attackedBy(Character * c) { 
	srand(time(0));
	int miss = rand() % 2;
    if (miss == 0) {
		return c->attack(this); 
	}
	else return -1; 
}
