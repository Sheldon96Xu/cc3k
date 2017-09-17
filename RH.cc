#include "RH.h"
#include "Player.h"

Rh::Rh() : Potion{"RH"}  {}

Rh::~Rh() {}
  
void Rh::usePotion(Player *player) {
  int increment = 10;
  if (player->getSymbol() == 'D') increment = 15;
  player->setHP(player->getHP() + increment);
  if (player->getHP() > player->getMax()) {
    player->setHP(player->getMax());
  } else {}
  usedList["RH"] = true;
}
