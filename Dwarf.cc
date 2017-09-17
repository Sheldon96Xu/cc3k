#include "Dwarf.h"

Dwarf::Dwarf(): Enemy{100, 20, 30} { Sym = 'W'; }

Dwarf::~Dwarf() {}

int Dwarf::attack(Character * c) { return regularDamage(c); }

int Dwarf::attackedBy(Character * c) { 
	return c->attack(this);
}

