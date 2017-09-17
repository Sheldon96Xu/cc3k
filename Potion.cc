#include "Potion.h"

map<string, bool> Potion::usedList = {{"RH", false}, {"RH", false}, {"BA", false},
 {"BD", false}, {"PH", false}, {"WA", false}, {"WD", false}};

Potion::Potion (string s) : type{s} {
  Symbol = 'P';
}

Potion::~Potion() {
}

pair<int, int> Potion::getPosn() const {
  return Position;
}

string Potion::getType() { return type; }

void Potion::setPosn(int x, int y) {
  Position.first = x;
  Position.second = y;
}

char Potion::getSymbol() {
  return Symbol;
}
