#ifndef __WD_H__
#define __WD_H__
#include "Potion.h"
//class Potion;
class Player;

class Wd: public Potion {
public:
  Wd();
  virtual ~Wd();
  virtual void usePotion(Player *player);
};

#endif
