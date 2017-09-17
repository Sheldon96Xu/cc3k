#ifndef _ENEMY_H
#define _ENEMY_H
#include "Character.h"
using namespace std;

class Player;

class Enemy : public Character 
{
public:
	Enemy(int, int, int);
	virtual ~Enemy();
};
#endif
