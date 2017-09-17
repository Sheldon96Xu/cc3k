#ifndef __POTION_H__
#define __POTION_H__
#include <vector>
#include <string>
#include <map>
using namespace std;
class Player;

class Potion{
protected:
  string type;
  char Symbol;
  pair<int, int> Position;
public:
  static map<string, bool> usedList;
  Potion(string);
  string getType();
  virtual ~Potion();
  pair <int, int> getPosn() const;
  void setPosn(int x, int y);
  char getSymbol();
  virtual void usePotion(Player *) = 0;
};

#endif
