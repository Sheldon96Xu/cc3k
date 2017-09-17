#ifndef _PLAYER_H
#define _PLAYER_H
#include "Character.h"
using namespace std;

class Enemy;

class Player : public Character 
{
protected:
	int Gold;
public:
	Player(int, int, int);
	int getGold() const;
	void addGold(int);
	virtual ~Player();
};
#endif
