#ifndef __DRAGONHOARD_H__
#define __DRAGONHOARD_H__
#include "Treasure.h"

class Enemy;

class DragonHoard: public Treasure {
  Enemy *dragon;
  bool dragonDead;
public:
  DragonHoard();
  virtual ~DragonHoard();
  void setDragon(Enemy *);
  void unlock();
  bool unlocked();
  Enemy * theDragon() const;
};

#endif
