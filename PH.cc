#include "PH.h"
#include "Player.h"

Ph::Ph() : Potion{"PH"}  {}

Ph::~Ph() {}

void Ph::usePotion(Player *player) {
  int decrement = 10;
  if (player->getSymbol() == 'D') decrement = 15;
  player->setHP(player->getHP() - decrement);
  if (player->getHP() < 0) {
    player->setHP(0);
  } else {}
  usedList["PH"] = true;
}
