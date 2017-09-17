 #include "Vampire.h"

Vampire::Vampire(): Player{50, 25, 25} { Sym = 'V'; }

Vampire::~Vampire() {}

int Vampire::attack(Character * c) {
	if (c->getSymbol() == 'W') {
		HP -= 5;
		if (HP < 0) HP = 0;
	}
	else HP += 5;
	return regularDamage(c);
}

int Vampire::attackedBy(Character * c) { 
	srand(time(0));
	int miss = rand() % 2;
    if (miss == 0) {
		return c->attack(this); 
	}
	else return -1; 
}
