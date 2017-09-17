#include "Dragon.h"

class DragonHoard;

Dragon::Dragon(): Enemy{150, 20, 20}, theHoard{nullptr} { Sym = 'D'; }

Dragon::Dragon(DragonHoard *dh): Enemy{150, 20, 20}, theHoard{dh}/*, theHoard{std::make_unique<DragonHoard>()}*/ { Sym = 'D'; }

Dragon::~Dragon() { 
	if (theHoard) {
		theHoard->unlock(); 
	}
}

void Dragon::setHoard(DragonHoard * dh) { theHoard = dh; }

int Dragon::attack(Character * c) { return regularDamage(c); }

int Dragon::attackedBy(Character * c) { return c->attack(this); }
