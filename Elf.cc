#include "Elf.h"

Elf::Elf(): Enemy{140, 30, 10} { Sym = 'E'; }

Elf::~Elf() {}

int Elf::attack(Character *c) { 
	if (c->getSymbol() == 'D') return regularDamage(c);
	else return regularDamage(c) + regularDamage(c);
}

int Elf::attackedBy(Character *c) { 
	return c->attack(this); 
}
