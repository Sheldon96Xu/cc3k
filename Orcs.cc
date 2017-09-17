#include "Orcs.h"

Orcs::Orcs(): Enemy{180, 30, 25} { Sym = 'O'; }

Orcs::~Orcs() {}

int Orcs::attack(Character * c) { 
	if (c->getSymbol() == 'G' ) {
		int def = c->getDefense();
		int damage = (100 * Attack / (100 + def) + (100 * Attack % (100 + def) > 0)) * 3 / 2;
		int hp = c->getHP();
		if (damage < hp) c->setHP(hp - damage);
		else c->setHP(0);
		return damage;
	}
	else return regularDamage(c); 
}

int Orcs::attackedBy(Character * c) {
	return c->attack(this); 
}
