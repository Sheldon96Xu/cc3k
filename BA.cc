#include "BA.h"
#include "Player.h"

Ba::Ba() : Potion{"BA"}  {}

Ba::~Ba() {}
 
void Ba::usePotion(Player *player) {
  int increment = 5;
  if (player->getSymbol() == 'D') increment = 8;
  player->setAttack(player->getAttack() + increment);
  usedList["BA"] = true;
}
