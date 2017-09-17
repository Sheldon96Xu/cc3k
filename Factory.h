#ifndef __FACTORY_H__
#define __FACTORY_H__
#include <string>
class Treasure;
//class NormalTreasure;
class DragonHoard;
class Potion;
class Enemy;

class Factory {
public:
  Treasure * createTreasure();
  Treasure * createTreasure(char);
  Treasure * createTreasure(int);
  Treasure * createNormalTreasure();
  Treasure * createMerchHoard();
  Potion * createPotion();
  Potion * createPotion(char);
  Potion * createPotion(std::string);
  Enemy * createEnemy();
  Enemy * createEnemy(char);
  Enemy * createDragon();
  Enemy * createDragon(DragonHoard *);
};


#endif
