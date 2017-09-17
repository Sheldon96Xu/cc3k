#include "Character.h"
//#include "TextDisplay.h"
using namespace std;

Character::Character(int hp, int atk, int def): 
	/*td{nullptr},*/ MaxHP{hp}, HP{hp}, Attack{atk}, Defense{def}, Position{pair<int,int>()} {}

Character::~Character() {}

int Character::regularDamage(Character * c) {
    int def = c->getDefense();
    int damage = 100 * Attack / (100 + def) + (100 * Attack % (100 + def) > 0);
    int objectHP = c->getHP();
    if (damage < objectHP) c->setHP(objectHP - damage);
    else c->setHP(0);
	return damage;
}

bool Character::isAlive() { return HP > 0; }

//void Character::attach(TextDisplay * p) { td = p; }

int Character::getHP() const { return HP; }

int Character::getMax() const { return MaxHP; }

void Character::setHP(int hp) { HP = hp; }

int Character::getAttack() const { return Attack; }

void Character::setAttack(int atk) { Attack = atk; }

int Character::getDefense() const { return Defense; }

void Character::setDefense(int def) { Defense = def; }

char Character::getSymbol() const { return Sym; }

pair<int,int> Character::getPosn() const { return Position; }

void Character::setPosn(int x, int y) {
	Position.first = x;
	Position.second = y;
}
