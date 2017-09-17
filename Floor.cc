#include "Floor.h"
#include <vector>
#include <iostream>
using namespace std;

int Floor::counter1 = 0; // count position of chamber1
int Floor::counter2 = 0; // count position of chamber2
int Floor::counter3 = 0; // count position of chamber3
int Floor::counter4 = 0; // count position of chamber4
int Floor::counter5 = 0; // count position of chamber5
int Floor::counter6 = 0; // count position of horWall
int Floor::counter7 = 0; // count position of verWall
int Floor::counter8 = 0; // count position of passage
int Floor::counter9 = 0; // count position of door

int Floor::getType() { return type;}

void addRowPair(std::vector <std::pair <int, int>> &unit,std::vector <int> &unitNum,
                        int row, int start, int end, int &counter) {
  for (int i = start; i <= end; ++i) {
	unit.emplace_back(std::make_pair(row,i));
	unitNum.emplace_back(counter);
	++counter;
  }
}

void addColPair(std::vector <std::pair <int, int>> &unit,std::vector <int> &unitNum,
                        int col, int start, int end, int &counter) {
  for (int i = start; i <= end; ++i) {
	unit.emplace_back(std::make_pair(i, col));
	unitNum.emplace_back(counter);
	++counter;
  }
}

Floor::Floor() {type = 0;}

/*void Floor::print() {
  std::cout <<chamber1[0].second << std::endl;
}*/

Floor::~Floor() {
  counter1 = 0; // count position of chamber1
  counter2 = 0; // count position of chamber2
  counter3 = 0; // count position of chamber3
  counter4 = 0; // count position of chamber4
  counter5 = 0; // count position of chamber5
  counter6 = 0; // count position of horWall
  counter7 = 0; // count position of verWall
  counter8 = 0; // count position of passage
  counter9 = 0; // count position of door
}

/*int main() {
  Floor f;
  f.print();
  return 1;
}*/

bool Floor::isChamber(std::pair<int, int> p) {
  for (unsigned int i = 0; i < chamber1.size(); ++i) {
    if (chamber1[i].first == p.first && 
        chamber1[i].second == p.second ) {
      return true;
    }
  }

  for (unsigned int i = 0; i < chamber2.size(); ++i) {
    if (chamber2[i].first == p.first &&
        chamber2[i].second == p.second ) {
      return true;
    }
  }

  for (unsigned int i = 0; i < chamber3.size(); ++i) {
    if (chamber3[i].first == p.first &&
        chamber3[i].second == p.second ) {
      return true;
    }
  }

  for (unsigned int i = 0; i < chamber4.size(); ++i) {
    if (chamber4[i].first == p.first &&
        chamber4[i].second == p.second ) {
      return true;
    }
  }

  for (unsigned int i = 0; i < chamber5.size(); ++i) {
    if (chamber5[i].first == p.first &&
        chamber5[i].second == p.second ) {
      return true;
    }
  }
  return false;
}
 
bool Floor::isPassage(std::pair<int,int> p) {
  for (unsigned int i = 0; i < passage.size(); ++i) {
    if (passage[i].first == p.first && passage[i].second == p.second) return true;
  }
  return false;
}

bool Floor::isDoor(std::pair<int,int> p) {
  for (unsigned int i = 0; i < door.size(); ++i) {
    if (door[i].first == p.first && door[i].second == p.second) return true;
  }
  return false;
}


std::pair<int, int> Floor::randomPos(int chamber) {
  int temp = 0;
  std::pair <int, int> tempPair;
  if (chamber == 1) {
    temp = rand()%chamber1Num.size();
    tempPair = chamber1[chamber1Num[temp]];
    chamber1Num.erase(chamber1Num.begin() + temp);
  }
  
  if (chamber == 2) {
	//////////////////cout << chamber << chamber2Num.size() << endl;
    temp = rand()%chamber2Num.size();
	//////////////////////cout << temp << endl;;
    tempPair = chamber2[chamber2Num[temp]];
	/////////////////cout << "first: "<<tempPair.first <<"second: "<< tempPair.second << endl;
    chamber2Num.erase(chamber2Num.begin() + temp);
	/////for (unsigned int i = 0; i < chamber2Num.size(); ++i) {
	/////cout << chamber2Num[i] << " ";
	/////}
  }

  if (chamber == 3) {
    temp = rand()%chamber3Num.size();
    tempPair = chamber3[chamber3Num[temp]];
    chamber3Num.erase(chamber3Num.begin() + temp);
  }

  if (chamber == 4) {
    temp = rand()%chamber4Num.size();
    tempPair = chamber4[chamber4Num[temp]];
    chamber4Num.erase(chamber4Num.begin() + temp);
  }

  if (chamber == 5) {
    temp = rand()%chamber5Num.size();
    tempPair = chamber5[chamber5Num[temp]];
    chamber5Num.erase(chamber5Num.begin() + temp);
  }

  return tempPair;
}
