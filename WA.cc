#include "WA.h"
#include "Player.h"

Wa::Wa() : Potion{"WA"}  {}

Wa::~Wa() {}

void Wa::usePotion(Player *player) {
  int decrement = 5;
  if (player->getSymbol() == 'D') decrement = 8;
  player->setAttack(player->getAttack() - decrement);
  if ( player->getAttack() < 0) {
    player->setAttack(0);
  } else {}
  usedList["WA"] = true;
}
