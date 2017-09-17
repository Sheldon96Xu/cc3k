#include "WD.h"
#include "Player.h"

Wd::Wd() : Potion{"WD"}  {}

Wd::~Wd() {}

void Wd::usePotion(Player *player) {
  int decrement = 5;
  if (player->getSymbol() == 'D') decrement = 8;
  player->setDefense(player->getDefense() - decrement);
  if ( player->getDefense() < 0) {
    player->setDefense(0);
  } else {}
  usedList["WD"] = true;
}
