#ifndef __BD_H__
#define __BD_H__
#include "Potion.h"
class Player;

class Bd: public Potion {
public:
  Bd();
  virtual ~Bd();
  virtual void usePotion(Player *player);
};

#endif
