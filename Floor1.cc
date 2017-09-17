#include "Floor1.h"
#include <vector>
#include <iostream>
using namespace std;

Floor1::Floor1() {
  type = 1;
  // chamber1
  addRowPair(chamber1, chamber1Num, 3, 3, 28, counter1);
  addRowPair(chamber1, chamber1Num, 4, 3, 28, counter1);
  addRowPair(chamber1, chamber1Num, 5, 3, 28, counter1);
  addRowPair(chamber1, chamber1Num, 6, 3, 28, counter1);
  // chamber2
  addRowPair(chamber2, chamber2Num, 3, 39, 61, counter2);
  addRowPair(chamber2, chamber2Num, 4, 39, 61, counter2);
  addRowPair(chamber2, chamber2Num, 5, 39, 69, counter2);
  addRowPair(chamber2, chamber2Num, 6, 39, 72, counter2);
  addRowPair(chamber2, chamber2Num, 7, 61, 75, counter2);
  addRowPair(chamber2, chamber2Num, 8, 61, 75, counter2);
  addRowPair(chamber2, chamber2Num, 9, 61, 75, counter2);
  addRowPair(chamber2, chamber2Num, 10, 61, 75, counter2);
  addRowPair(chamber2, chamber2Num, 11, 61, 75, counter2);
  addRowPair(chamber2, chamber2Num, 12, 61, 75, counter2);
  // chamber3
  addRowPair(chamber3, chamber3Num, 15, 4, 24, counter3);
  addRowPair(chamber3, chamber3Num, 16, 4, 24, counter3);
  addRowPair(chamber3, chamber3Num, 17, 4, 24, counter3);
  addRowPair(chamber3, chamber3Num, 18, 4, 24, counter3);
  addRowPair(chamber3, chamber3Num, 19, 4, 24, counter3);
  addRowPair(chamber3, chamber3Num, 20, 4, 24, counter3);
  addRowPair(chamber3, chamber3Num, 21, 4, 24, counter3);
  // chamber4
  addRowPair(chamber4, chamber4Num, 10, 38, 49, counter4);
  addRowPair(chamber4, chamber4Num, 11, 38, 49, counter4);
  addRowPair(chamber4, chamber4Num, 12, 38, 49, counter4);
  // chamber5
  addRowPair(chamber5, chamber5Num, 16, 65, 75, counter5);
  addRowPair(chamber5, chamber5Num, 17, 65, 75, counter5);
  addRowPair(chamber5, chamber5Num, 18, 65, 75, counter5);
  addRowPair(chamber5, chamber5Num, 19, 37, 75, counter5);
  addRowPair(chamber5, chamber5Num, 20, 37, 75, counter5);
  addRowPair(chamber5, chamber5Num, 21, 37, 75, counter5);
  // horWall
  addRowPair(horWall, horWallNum, 0, 1, 77, counter6);
  addRowPair(horWall, horWallNum, 2, 3, 28, counter6);
  addRowPair(horWall, horWallNum, 2, 39, 61, counter6);
  addRowPair(horWall, horWallNum, 4, 63, 69, counter6);
  addRowPair(horWall, horWallNum, 5, 71, 72, counter6);
  addRowPair(horWall, horWallNum, 6, 74, 75, counter6);
  addRowPair(horWall, horWallNum, 7, 3, 12, counter6);
  addRowPair(horWall, horWallNum, 7, 14, 28, counter6);
  addRowPair(horWall, horWallNum, 7, 39, 42, counter6);
  addRowPair(horWall, horWallNum, 7, 44, 59, counter6);
  addRowPair(horWall, horWallNum, 9, 38, 42, counter6);
  addRowPair(horWall, horWallNum, 9, 44, 49, counter6);
  addRowPair(horWall, horWallNum, 13, 38, 42, counter6);
  addRowPair(horWall, horWallNum, 13, 44, 49, counter6);
  addRowPair(horWall, horWallNum, 13, 61, 68, counter6);
  addRowPair(horWall, horWallNum, 13, 70, 75, counter6);
  addRowPair(horWall, horWallNum, 14, 4, 12, counter6);
  addRowPair(horWall, horWallNum, 14, 14, 24, counter6);
  addRowPair(horWall, horWallNum, 15, 65, 69, counter6);
  addRowPair(horWall, horWallNum, 15, 70, 75, counter6);
  addRowPair(horWall, horWallNum, 18, 37, 42, counter6);
  addRowPair(horWall, horWallNum, 18, 44, 63, counter6);
  addRowPair(horWall, horWallNum, 22, 4, 24, counter6);
  addRowPair(horWall, horWallNum, 22, 37, 75, counter6);
  addRowPair(horWall, horWallNum, 24, 1, 77, counter6);
  // verWall
  addColPair(verWall, verWallNum, 0, 0, 24, counter7);
  addColPair(verWall, verWallNum, 2, 2, 7, counter7);
  addColPair(verWall, verWallNum, 3, 14, 22, counter7);
  addColPair(verWall, verWallNum, 25, 14, 19, counter7);
  addColPair(verWall, verWallNum, 25, 21, 22, counter7);
  addColPair(verWall, verWallNum, 29, 2, 3, counter7);
  addColPair(verWall, verWallNum, 29, 5, 7, counter7);
  addColPair(verWall, verWallNum, 36, 18, 19, counter7);
  addColPair(verWall, verWallNum, 36, 21, 22, counter7);
  addColPair(verWall, verWallNum, 37, 9, 13, counter7);
  addColPair(verWall, verWallNum, 38, 2, 3, counter7);
  addColPair(verWall, verWallNum, 38, 5, 7, counter7);
  addColPair(verWall, verWallNum, 50, 9, 13, counter7);
  addColPair(verWall, verWallNum, 60, 7, 10, counter7);
  addColPair(verWall, verWallNum, 60, 12, 13, counter7);
  addColPair(verWall, verWallNum, 62, 2, 4, counter7);
  addColPair(verWall, verWallNum, 64, 15, 18, counter7);
  addColPair(verWall, verWallNum, 70, 4, 5, counter7);
  addColPair(verWall, verWallNum, 73, 5, 6, counter7);
  addColPair(verWall, verWallNum, 76, 6, 13, counter7);
  addColPair(verWall, verWallNum, 76, 15, 22, counter7);
  addColPair(verWall, verWallNum, 78, 0, 24, counter7);
  // passage
  addColPair(passage, passageNum, 13, 8, 13, counter8);
  addColPair(passage, passageNum, 31, 8, 20, counter8);
  addColPair(passage, passageNum, 33, 4, 8, counter8);
  addColPair(passage, passageNum, 43, 14, 17, counter8);
  addColPair(passage, passageNum, 54, 11, 16, counter8);
  addColPair(passage, passageNum, 69, 14, 14, counter8);
  addRowPair(passage, passageNum, 4, 30, 32, counter8);
  addRowPair(passage, passageNum, 4, 34, 37, counter8);
  addRowPair(passage, passageNum, 8, 32, 32, counter8);
  addRowPair(passage, passageNum, 8, 34, 43, counter8);
  addRowPair(passage, passageNum, 11, 14, 30, counter8);
  addRowPair(passage, passageNum, 11, 55, 59, counter8);
  addRowPair(passage, passageNum, 16, 32, 42, counter8);
  addRowPair(passage, passageNum, 16, 44, 53, counter8);
  addRowPair(passage, passageNum, 20, 26, 30, counter8);
  addRowPair(passage, passageNum, 20, 32, 35, counter8);
  // door
  addRowPair(door, doorNum, 4, 29, 29, counter9);
  addRowPair(door, doorNum, 4, 38, 38, counter9);
  addRowPair(door, doorNum, 7, 13, 13, counter9);
  addRowPair(door, doorNum, 7, 43, 43, counter9);
  addRowPair(door, doorNum, 9, 43, 43, counter9);
  addRowPair(door, doorNum, 11, 60, 60, counter9);
  addRowPair(door, doorNum, 13, 43, 43, counter9);
  addRowPair(door, doorNum, 13, 69, 69, counter9);
  addRowPair(door, doorNum, 14, 13, 13, counter9);
  addRowPair(door, doorNum, 15, 69, 69, counter9);
  addRowPair(door, doorNum, 18, 43, 43, counter9);
  addRowPair(door, doorNum, 20, 25, 25, counter9);
  addRowPair(door, doorNum, 20, 36, 36, counter9);
}

Floor1::~Floor1() {
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


/*void Floor1::print() {
  std::cout <<"chamber1[0]'s x is " << chamber1[0].first << ", and chamber1[0]'s y is "<<chamber1[0].second <<std::endl;
  std::cout <<"chamber1[last]'s x is " << chamber1[chamber1.size()-1].first << ", and chamber1[last]'s y is "<<chamber1[chamber1.size()-1].second <<std::endl;
  std::cout <<"counter1 is " << counter1 << std::endl;
  std::cout <<"chamber2[0]'s x is " << chamber2[0].first << ", and chamber2[0]'s y is "<<chamber2[0].second <<std::endl;
  std::cout <<"chamber2[last]'s x is " << chamber2[chamber2.size()-1].first << ", and chamber2[last]'s y is "<<chamber2[chamber2.size()-1].second <<std::endl;
  std::cout <<"counter2 is " << counter2 << std::endl;
  std::cout <<"chamber3[0]'s x is " << chamber3[0].first << ", and chamber3[0]'s y is "<<chamber3[0].second <<std::endl;
  std::cout <<"chamber3[last]'s x is " << chamber3[chamber3.size()-1].first << ", and chamber3[last]'s y is "<<chamber3[chamber3.size()-1].second <<std::endl;
  std::cout <<"counter3 is " << counter3 << std::endl;
  std::cout <<"chamber4[0]'s x is " << chamber4[0].first << ", and chamber4[0]'s y is "<<chamber4[0].second <<std::endl;
  std::cout <<"chamber4[last]'s x is " << chamber4[chamber4.size()-1].first << ", and chamber4[last]'s y is "<<chamber4[chamber4.size()-1].second <<std::endl;
  std::cout <<"counter4 is " << counter4 << std::endl;
  std::cout <<"chamber5[0]'s x is " << chamber5[0].first << ", and chamber5[0]'s y is "<<chamber5[0].second <<std::endl;
  std::cout <<"chamber5[last]'s x is " << chamber5[chamber5.size()-1].first << ", and chamber5[last]'s y is "<<chamber5[chamber5.size()-1].second <<std::endl;
  std::cout <<"counter5 is " << counter5 << std::endl;
}

int main() {
  Floor1 f;
  f.print();
  return 1;
}*/
