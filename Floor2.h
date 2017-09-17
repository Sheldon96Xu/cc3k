#ifndef __Floor2_H__
#define __Floor2_H__
#include <vector>
#include "Floor.h"

class Floor2: public Floor {
private:
  int type;
public:
//  void print();
  Floor2();
  ~Floor2();
  Floor2& operator=(const Floor2& other) = default;
};

#endif
