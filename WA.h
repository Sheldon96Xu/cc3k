#ifndef __WA_H__
#define __WA_H__
#include "Potion.h"
class Player;

class Wa: public Potion {
public:
  Wa();
  virtual ~Wa();
  virtual void usePotion(Player *player);
};

#endif
