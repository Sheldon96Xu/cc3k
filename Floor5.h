#ifndef __Floor5_H__
#define __Floor5_H__
#include <vector>
#include "Floor.h"

class Floor5: public Floor {
private:
  int type;
public:
 // void print();
  Floor5();
  ~Floor5();
  Floor5& operator=(const Floor5& other) = default;
};

#endif
