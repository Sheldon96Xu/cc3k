#include "Floor3.h"
#include <vector>
#include <iostream>
using namespace std;

Floor3::Floor3() {
  type = 3;
  // chamber1
  addRowPair(chamber1, chamber1Num, 2, 7, 19, counter1);
  addRowPair(chamber1, chamber1Num, 3, 7, 19, counter1);
  addRowPair(chamber1, chamber1Num, 4, 7, 19, counter1);
  addRowPair(chamber1, chamber1Num, 5, 7, 19, counter1);
  addRowPair(chamber1, chamber1Num, 6, 7, 19, counter1);
  // chamber2
  addRowPair(chamber2, chamber2Num, 3, 26, 38, counter2);
  addRowPair(chamber2, chamber2Num, 4, 26, 38, counter2);
  addRowPair(chamber2, chamber2Num, 5, 26, 38, counter2);
  addRowPair(chamber2, chamber2Num, 6, 26, 38, counter2);
  addRowPair(chamber2, chamber2Num, 7, 26, 38, counter2);
  addRowPair(chamber2, chamber2Num, 8, 26, 38, counter2);
  addRowPair(chamber2, chamber2Num, 9, 26, 38, counter2);
  addRowPair(chamber2, chamber2Num, 10, 6, 38, counter2);
  addRowPair(chamber2, chamber2Num, 11, 6, 50, counter2);
  // chamber3
  addRowPair(chamber3, chamber3Num, 2, 48, 67, counter3);
  addRowPair(chamber3, chamber3Num, 3, 48, 67, counter3);
  addRowPair(chamber3, chamber3Num, 4, 48, 67, counter3);
  // chamber4
  addRowPair(chamber4, chamber4Num, 8, 55, 73, counter4);
  addRowPair(chamber4, chamber4Num, 9, 55, 73, counter4);
  addRowPair(chamber4, chamber4Num, 10, 55, 73, counter4);
  addRowPair(chamber4, chamber4Num, 11, 55, 73, counter4);
  addRowPair(chamber4, chamber4Num, 12, 55, 73, counter4);
  addRowPair(chamber4, chamber4Num, 13, 55, 73, counter4);
  addRowPair(chamber4, chamber4Num, 14, 55, 73, counter4);
  addRowPair(chamber4, chamber4Num, 15, 25, 73, counter4);
  addRowPair(chamber4, chamber4Num, 16, 25, 73, counter4);
  addRowPair(chamber4, chamber4Num, 17, 25, 73, counter4);
  // chamber5
  addRowPair(chamber5, chamber5Num, 20, 37, 75, counter5);
  addRowPair(chamber5, chamber5Num, 21, 2, 75, counter5);
  // horWall
  addRowPair(horWall, horWallNum, 0, 1, 77, counter6);
  addRowPair(horWall, horWallNum, 1, 7, 19, counter6);
  addRowPair(horWall, horWallNum, 1, 48, 67, counter6);
  addRowPair(horWall, horWallNum, 2, 26, 38, counter6);
  addRowPair(horWall, horWallNum, 5, 48, 62, counter6);
  addRowPair(horWall, horWallNum, 5, 64, 67, counter6);
  addRowPair(horWall, horWallNum, 7, 7, 11, counter6);
  addRowPair(horWall, horWallNum, 7, 13, 19, counter6);
  addRowPair(horWall, horWallNum, 7, 55, 62, counter6);
  addRowPair(horWall, horWallNum, 7, 64, 72, counter6);
  addRowPair(horWall, horWallNum, 9, 6, 11, counter6);
  addRowPair(horWall, horWallNum, 9, 13, 24, counter6);
  addRowPair(horWall, horWallNum, 10, 40, 47, counter6);
  addRowPair(horWall, horWallNum, 10, 49, 50, counter6);
  addRowPair(horWall, horWallNum, 12, 6, 13, counter6);
  addRowPair(horWall, horWallNum, 12, 15, 33, counter6);
  addRowPair(horWall, horWallNum, 12, 35, 50, counter6);
  addRowPair(horWall, horWallNum, 14, 25, 33, counter6);
  addRowPair(horWall, horWallNum, 14, 35, 53, counter6);
  addRowPair(horWall, horWallNum, 18, 25, 73, counter6);
  addRowPair(horWall, horWallNum, 19, 37, 75, counter6);
  addRowPair(horWall, horWallNum, 20, 2, 18, counter6);
  addRowPair(horWall, horWallNum, 20, 20, 35, counter6);
  addRowPair(horWall, horWallNum, 22, 2, 75, counter6);
  addRowPair(horWall, horWallNum, 24, 1, 78, counter6);
  // verWall
  addColPair(verWall, verWallNum, 0, 0, 24, counter7);
  addColPair(verWall, verWallNum, 1, 20, 22, counter7);
  addColPair(verWall, verWallNum, 5, 9, 12, counter7);
  addColPair(verWall, verWallNum, 6, 1, 2, counter7);
  addColPair(verWall, verWallNum, 6, 4, 7, counter7);
  addColPair(verWall, verWallNum, 20, 1, 4, counter7);
  addColPair(verWall, verWallNum, 20, 6, 7, counter7);
  addColPair(verWall, verWallNum, 24, 14, 15, counter7);
  addColPair(verWall, verWallNum, 24, 17, 18, counter7);
  addColPair(verWall, verWallNum, 25, 2, 4, counter7);
  addColPair(verWall, verWallNum, 25, 6, 9, counter7);
  addColPair(verWall, verWallNum, 36, 19, 20, counter7);
  addColPair(verWall, verWallNum, 39, 2, 2, counter7);
  addColPair(verWall, verWallNum, 39, 4, 10, counter7);
  addColPair(verWall, verWallNum, 47, 1, 2, counter7);
  addColPair(verWall, verWallNum, 47, 4, 5, counter7);
  addColPair(verWall, verWallNum, 51, 10, 10, counter7);
  addColPair(verWall, verWallNum, 51, 12, 12, counter7);
  addColPair(verWall, verWallNum, 54, 7, 10, counter7);
  addColPair(verWall, verWallNum, 54, 12, 14, counter7);
  addColPair(verWall, verWallNum, 68, 1, 5, counter7);
  addColPair(verWall, verWallNum, 74, 7, 18, counter7);
  addColPair(verWall, verWallNum, 76, 19, 22, counter7);
  addColPair(verWall, verWallNum, 78, 0, 24, counter7);
  // passage
  addColPair(passage, passageNum, 2, 3, 19, counter8);
  addRowPair(passage, passageNum, 8, 12, 12, counter8);
  addColPair(passage, passageNum, 14, 13, 19, counter8);
  addColPair(passage, passageNum, 48, 6, 9, counter8);
  addRowPair(passage, passageNum, 3, 3, 5, counter8);
  addRowPair(passage, passageNum, 3, 40, 46, counter8);
  addRowPair(passage, passageNum, 5, 21, 24, counter8);
  addRowPair(passage, passageNum, 6, 49, 63, counter8);
  addRowPair(passage, passageNum, 11, 52, 53, counter8);
  addRowPair(passage, passageNum, 13, 34, 34, counter8);
  addRowPair(passage, passageNum, 16, 15, 23, counter8);
  addRowPair(passage, passageNum, 19, 3, 13, counter8);
  addRowPair(passage, passageNum, 19, 15, 19, counter8);
  // door
  addRowPair(door, doorNum, 3, 6, 6, counter9);
  addRowPair(door, doorNum, 3, 39, 39, counter9);
  addRowPair(door, doorNum, 3, 47, 47, counter9);
  addRowPair(door, doorNum, 5, 20, 20, counter9);
  addRowPair(door, doorNum, 5, 25, 25, counter9);
  addRowPair(door, doorNum, 5, 63, 63, counter9);
  addRowPair(door, doorNum, 7, 12, 12, counter9);
  addRowPair(door, doorNum, 7, 63, 63, counter9);
  addRowPair(door, doorNum, 9, 12, 12, counter9);
  addRowPair(door, doorNum, 10, 48, 48, counter9);
  addRowPair(door, doorNum, 11, 51, 51, counter9);
  addRowPair(door, doorNum, 11, 54, 54, counter9);
  addRowPair(door, doorNum, 12, 14, 14, counter9);
  addRowPair(door, doorNum, 12, 34, 34, counter9);
  addRowPair(door, doorNum, 14, 34, 34, counter9);
  addRowPair(door, doorNum, 20, 19, 19, counter9);
  addRowPair(door, doorNum, 16, 24, 24, counter9);
}

Floor3::~Floor3() {
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


/*void Floor3::print() {
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
  Floor3 f;
  f.print();
  return 1;
}*/
