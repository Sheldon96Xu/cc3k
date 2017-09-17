#ifndef __Floor1_H__
#define __Floor1_H__
#include <vector>
#include "Floor.h"

class Floor1: public Floor {
private:
  int type;
public:
//  void print();
  Floor1();
  ~Floor1();
  Floor1& operator=(const Floor1& other) = default;
};

#endif
