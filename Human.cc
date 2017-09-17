#include "Human.h"

Human::Human(): Enemy{140, 20, 20} { Sym = 'H'; }

Human::~Human() {}

int Human::attack(Character * c) { return regularDamage(c); }

int Human::attackedBy(Character * c) { 
	return c->attack(this); 
}
