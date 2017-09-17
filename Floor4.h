#ifndef __Floor4_H__
#define __Floor4_H__
#include <vector>
#include "Floor.h"

class Floor4: public Floor {
private:
  int type;
public:
//  void print();
  Floor4();
  ~Floor4();
  Floor4& operator=(const Floor4& other) = default;
};

#endif
