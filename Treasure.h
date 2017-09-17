#ifndef __TREASURE_H__
#define __TREASURE_H__
#include <vector>
using namespace std;

class Treasure {
protected:
  int value;
  pair <int, int> Position;
  char Symbol;
public:
  Treasure(int);
  virtual ~Treasure();
  virtual int getValue() const;
  virtual pair<int, int> getPosn() const;
  virtual void setPosn(int x, int y);	
  virtual char getSymbol();
};

#endif
