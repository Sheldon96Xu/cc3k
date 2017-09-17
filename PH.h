#ifndef __PH_H__
#define __PH_H__
#include "Potion.h"
class Player;

class Ph: public Potion {
public:
  Ph();
  virtual ~Ph();
  virtual void usePotion(Player *player);
};

#endif
