#ifndef _CHARACTER_H
#define _CHARACTER_H
#include <vector>
#include <memory>
#include <cstdlib>
using namespace std;

//class TextDisplay;

class Character
{
protected:
//	TextDisplay * td;
	int MaxHP;
	int HP;
	int Attack;
	int Defense;
	char Sym;
	pair<int,int> Position;
	int regularDamage(Character *);
public:
	Character(int, int, int);
	virtual ~Character();
	bool isAlive();
//	void attach(TextDisplay *);
	int getHP() const;
	int getMax() const;
	void setHP(int);
	int getAttack() const;
	void setAttack(int);
	int getDefense() const;
	void setDefense(int);
	char getSymbol() const;
	pair<int,int> getPosn() const;
	void setPosn(int, int);
	virtual int attack(Character *) = 0;
	virtual int attackedBy(Character *) = 0;
};
#endif
