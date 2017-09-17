#ifndef __Floor3_H__
#define __Floor3_H__
#include <vector>
#include "Floor.h"

class Floor3: public Floor {
private:
  int type;
public:
//  void print();
  Floor3();
  ~Floor3();
  Floor3& operator=(const Floor3& other) = default;
};

#endif
