#ifndef __BA_H__
#define __BA_H__
#include "Potion.h"
class Player;

class Ba: public Potion {
public:
  Ba();
  virtual ~Ba();
  virtual void usePotion(Player *player);
};

#endif
