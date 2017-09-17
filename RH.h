#ifndef __RH_H__
#define __RH_H__
#include "Potion.h"
class Player;

class Rh: public Potion {
public:
  Rh();
  virtual ~Rh();
  virtual void usePotion(Player *player);
};

#endif
