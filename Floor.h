#ifndef __Floor_H__
#define __Floor_H__
#include <vector>

void addRowPair(std::vector <std::pair <int, int>> &unit, std::vector <int> &unitNum, 
                  int row, int start, int end, int &counter);
void addColPair(std::vector <std::pair <int, int>> &unit, std::vector <int> &unitNum,
                  int col, int start, int end, int &counter);
class Floor {
private:
  int type;
protected:
  static int counter1, counter2, counter3, counter4, counter5,
			 counter6, counter7, counter8, counter9;
  std::vector <std::pair <int, int>> chamber1;
  std::vector <int> chamber1Num;
  std::vector <std::pair <int, int>> chamber2;
  std::vector <int> chamber2Num;
  std::vector <std::pair <int, int>> chamber3;
  std::vector <int> chamber3Num;
  std::vector <std::pair <int, int>> chamber4;
  std::vector <int> chamber4Num;
  std::vector <std::pair <int, int>> chamber5;
  std::vector <int> chamber5Num;
  std::vector <std::pair <int, int>> horWall;
  std::vector <int> horWallNum;
  std::vector <std::pair <int, int>> verWall;
  std::vector <int> verWallNum;
  std::vector <std::pair <int, int>> passage;
  std::vector <int> passageNum;
  std::vector <std::pair <int, int>> door;
  std::vector <int> doorNum;
//  bool getChamber1Pair(int pos);
//  bool getChamber2Pair(int pos);
//  bool getChamber3Pair(int pos);
//  bool getChamber4Pair(int pos);
//  bool getChamber5Pair(int pos);
public:
  Floor();
  ~Floor();
  int getType();
  bool isChamber(std::pair<int, int> p);
  bool isPassage(std::pair<int,int> p);
  bool isDoor(std::pair<int,int> p);
  std::pair <int, int> randomPos(int chamber);
//  void print();
  Floor& operator=(const Floor& other) = default;
};

#endif
