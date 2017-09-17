#include "Floor5.h"
#include <vector>
#include <iostream>
using namespace std;

Floor5::Floor5() {
  type = 5;
  // chamber1
  addRowPair(chamber1, chamber1Num, 3, 8, 29, counter1);
  addRowPair(chamber1, chamber1Num, 4, 8, 29, counter1);
  addRowPair(chamber1, chamber1Num, 5, 8, 29, counter1);
  // chamber2
  addRowPair(chamber2, chamber2Num, 4, 41, 68, counter2);
  addRowPair(chamber2, chamber2Num, 5, 41, 68, counter2);
  addRowPair(chamber2, chamber2Num, 6, 41, 68, counter2);
  addRowPair(chamber2, chamber2Num, 7, 60, 68, counter2);
  // chamber3
  addRowPair(chamber3, chamber3Num, 10, 28, 42, counter3);
  addRowPair(chamber3, chamber3Num, 11, 28, 42, counter3);
  addRowPair(chamber3, chamber3Num, 12, 28, 42, counter3);
  addRowPair(chamber3, chamber3Num, 13, 28, 49, counter3);
  addRowPair(chamber3, chamber3Num, 14, 28, 49, counter3);
  // chamber4
  addRowPair(chamber4, chamber4Num, 12, 64, 72, counter4);
  addRowPair(chamber4, chamber4Num, 13, 64, 72, counter4);
  addRowPair(chamber4, chamber4Num, 14, 64, 72, counter4);
  addRowPair(chamber4, chamber4Num, 15, 56, 72, counter4);
  addRowPair(chamber4, chamber4Num, 16, 56, 72, counter4);
  addRowPair(chamber4, chamber4Num, 17, 56, 76, counter4);
  addRowPair(chamber4, chamber4Num, 18, 56, 76, counter4);
  // chamber5
  addRowPair(chamber5, chamber5Num, 19, 12, 27, counter5);
  addRowPair(chamber5, chamber5Num, 20, 12, 27, counter5);
  addRowPair(chamber5, chamber5Num, 21, 12, 27, counter5);
  // horWall
  addRowPair(horWall, horWallNum, 0, 1, 77, counter6);
  addRowPair(horWall, horWallNum, 2, 8, 29, counter6);
  addRowPair(horWall, horWallNum, 6, 8, 16, counter6);
  addRowPair(horWall, horWallNum, 6, 18, 29, counter6);
  addRowPair(horWall, horWallNum, 7, 41, 58, counter6);
  addRowPair(horWall, horWallNum, 8, 60, 66, counter6);
  addRowPair(horWall, horWallNum, 8, 68, 68, counter6);
  addRowPair(horWall, horWallNum, 9, 28, 35, counter6);
  addRowPair(horWall, horWallNum, 9, 37, 42, counter6);
  addRowPair(horWall, horWallNum, 11, 64, 66, counter6);
  addRowPair(horWall, horWallNum, 11, 68, 72, counter6);
  addRowPair(horWall, horWallNum, 12, 44, 49, counter6);
  addRowPair(horWall, horWallNum, 14, 28, 43, counter6);
  addRowPair(horWall, horWallNum, 16, 74, 76, counter6);
  addRowPair(horWall, horWallNum, 18, 12, 16, counter6);
  addRowPair(horWall, horWallNum, 18, 18, 27, counter6);
  addRowPair(horWall, horWallNum, 19, 56, 76, counter6);
  addRowPair(horWall, horWallNum, 22, 12, 27, counter6);
  addRowPair(horWall, horWallNum, 24, 1, 70, counter6);
  // verWall
  addColPair(verWall, verWallNum, 0, 0, 24, counter7);
  addColPair(verWall, verWallNum, 7, 2, 3, counter7);
  addColPair(verWall, verWallNum, 7, 5, 6, counter7);
  addColPair(verWall, verWallNum, 11, 18, 19, counter7);
  addColPair(verWall, verWallNum, 11, 21, 22, counter7);
  addColPair(verWall, verWallNum, 11, 21, 22, counter7);
  addColPair(verWall, verWallNum, 27, 9, 11, counter7);
  addColPair(verWall, verWallNum, 27, 13, 15, counter7);
  addColPair(verWall, verWallNum, 28, 18, 22, counter7);
  addColPair(verWall, verWallNum, 30, 2, 3, counter7);
  addColPair(verWall, verWallNum, 30, 5, 6, counter7);
  addColPair(verWall, verWallNum, 40, 3, 3, counter7);
  addColPair(verWall, verWallNum, 40, 5, 7, counter7);
  addColPair(verWall, verWallNum, 43, 9, 9, counter7);
  addColPair(verWall, verWallNum, 43, 11, 12, counter7);
  addColPair(verWall, verWallNum, 50, 12, 15, counter7);
  addColPair(verWall, verWallNum, 55, 14, 16, counter7);
  addColPair(verWall, verWallNum, 55, 18, 19, counter7);
  addColPair(verWall, verWallNum, 59, 7, 8, counter7);
  addColPair(verWall, verWallNum, 63, 11, 14, counter7);
  addColPair(verWall, verWallNum, 69, 3, 8, counter7);
  addColPair(verWall, verWallNum, 73, 11, 16, counter7);
  addColPair(verWall, verWallNum, 77, 16, 19, counter7);
  addColPair(verWall, verWallNum, 78, 0, 24, counter7);
  // passage
  addColPair(passage, passageNum, 4, 4, 20, counter8);
  addColPair(passage, passageNum, 17, 7, 17, counter8);
  addColPair(passage, passageNum, 36, 5, 8, counter8);
  addRowPair(passage, passageNum, 4, 5, 6, counter8);
  addRowPair(passage, passageNum, 4, 31, 39, counter8);
  addRowPair(passage, passageNum, 9, 67, 67, counter8);
  addRowPair(passage, passageNum, 10, 44, 67, counter8);
  addRowPair(passage, passageNum, 12, 5, 16, counter8);
  addRowPair(passage, passageNum, 12, 18, 26, counter8);
  addRowPair(passage, passageNum, 16, 44, 44, counter8);
  addRowPair(passage, passageNum, 17, 18, 54, counter8);
  addRowPair(passage, passageNum, 20, 5, 10, counter8);
  // door
  addRowPair(door, doorNum, 4, 7, 7, counter9);
  addRowPair(door, doorNum, 4, 30, 30, counter9);
  addRowPair(door, doorNum, 4, 40, 40, counter9);
  addRowPair(door, doorNum, 6, 17, 17, counter9);
  addRowPair(door, doorNum, 8, 67, 67, counter9);
  addRowPair(door, doorNum, 9, 36, 36, counter9);
  addRowPair(door, doorNum, 10, 43, 43, counter9);
  addRowPair(door, doorNum, 11, 67, 67, counter9);
  addRowPair(door, doorNum, 12, 27, 27, counter9);
  addRowPair(door, doorNum, 15, 44, 44, counter9);
  addRowPair(door, doorNum, 17, 55, 55, counter9);
  addRowPair(door, doorNum, 18, 17, 17, counter9);
  addRowPair(door, doorNum, 20, 11, 11, counter9);
  
}

Floor5::~Floor5() {
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


/*void Floor5::print() {
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
  Floor5 f;
  f.print();
  return 1;
}*/
