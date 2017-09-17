#include "Halfing.h"

Halfing::Halfing(): Enemy{100, 15, 20} { Sym = 'L'; }

Halfing::~Halfing() {}

int Halfing::attack(Character * c) { return regularDamage(c); }

int Halfing::attackedBy(Character * c) {
	srand(time(0));
	int miss = rand() % 2;
    if (miss == 0) {
		return c->attack(this); 
	}
	else return -1;
}
