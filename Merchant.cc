#include "Merchant.h"

Merchant::Merchant(): Enemy{30, 70, 5} { Sym = 'M'; }

Merchant::~Merchant() {}

bool Merchant::Hostile = false;

bool Merchant::isHostile() { return Hostile; }

int Merchant::attack(Character * c) { 
	if (Hostile) return regularDamage(c); 
	else return 0;
}

int Merchant::attackedBy(Character * c) { 
	int damage = c->attack(this); 
	Hostile = true; 
	return damage;
}
