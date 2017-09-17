#include "BD.h"
#include "Player.h"

Bd::Bd() : Potion{"BD"} {}

Bd::~Bd() {}

void Bd::usePotion(Player *player) {
  int increment = 5;
  if (player->getSymbol() == 'D') increment = 8;
  player->setDefense(player->getDefense() + increment);
  usedList["BD"] = true;
}
