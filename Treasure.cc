#include "Treasure.h"

Treasure::Treasure(int val) : value{val}, Symbol{'G'} {}

Treasure::~Treasure() {}

int Treasure::getValue() const {
  return value;
}

pair<int, int> Treasure::getPosn() const {
  return Position;
}

void Treasure::setPosn(int x, int y) {
  Position.first = x;
  Position.second = y;
}

char Treasure::getSymbol() {
  return Symbol;
}
