#include <cstdlib>
#include "Factory.h"
#include "Human.h"
#include "Dwarf.h"
#include "Elf.h"
#include "Orcs.h"
#include "Halfing.h"
#include "Merchant.h"
#include "MerchHoard.h"
#include "SmallTreasure.h"
#include "NormalTreasure.h"
#include "DragonHoard.h"
#include "Dragon.h"
#include "RH.h"
#include "BA.h"
#include "BD.h"
#include "PH.h"
#include "WA.h"
#include "WD.h"

Treasure * Factory::createTreasure() {
	int n = rand() % 8;
	if      (n <= 4) return new NormalTreasure;
	else if (n <= 6) return new SmallTreasure;
	else             return new DragonHoard;
}

Treasure * Factory::createTreasure(char type) {
	if      (type == '6') return new NormalTreasure;
	else if (type == '7') return new SmallTreasure;
	else if (type == '8') return new MerchHoard;
	else                  return new DragonHoard;
}

Treasure * Factory::createTreasure(int val) {
	if      (val == 2) return new NormalTreasure;
	else if (val == 1) return new SmallTreasure;
	else if (val == 4) return new MerchHoard;
	else               return new DragonHoard;
}

Treasure * Factory::createNormalTreasure() {
	return new NormalTreasure;
}

Treasure * Factory::createMerchHoard() {
	return new MerchHoard;
}

Potion * Factory::createPotion() {
	int n = rand() % 6;
	if      (n == 0) return new Rh;
	else if (n == 1) return new Ba;
	else if (n == 2) return new Bd;
	else if (n == 3) return new Ph;
	else if (n == 4) return new Wa;
	else             return new Wd;
}

Potion * Factory::createPotion(char type) {
	if      (type == '0') return new Rh;
	else if (type == '1') return new Ba;
	else if (type == '2') return new Bd;
	else if (type == '3') return new Ph;
	else if (type == '4') return new Wa;
	else                  return new Wd;
}

Potion * Factory::createPotion(string type) {
	if      (type == "RH") return new Rh;
	else if (type == "BA") return new Ba;
	else if (type == "BD") return new Bd;
	else if (type == "PH") return new Ph;
	else if (type == "WA") return new Wa;
	else                   return new Wd;
}

Enemy * Factory::createEnemy() {
	int n = rand() % 18;
	if      (n <= 3)  return new Human;
	else if (n <= 6)  return new Dwarf;
	else if (n <= 11) return new Halfing;
	else if (n <= 13) return new Elf;
	else if (n <= 15) return new Orcs;
	else              return new Merchant;
}

Enemy * Factory::createEnemy(char type) {
	if      (type == 'H') return new Human;
	else if (type == 'W') return new Dwarf;
	else if (type == 'L') return new Halfing;
	else if (type == 'E') return new Elf;
	else if (type == 'O') return new Orcs;
	else if (type == 'D') return new Dragon;
	else                  return new Merchant;
}

Enemy * Factory::createDragon() {
	return new Dragon;
}

Enemy * Factory::createDragon(DragonHoard * dh) {
	return new Dragon(dh);
}
