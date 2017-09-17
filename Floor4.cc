#include "Floor4.h"
#include <vector>
#include <iostream>
using namespace std;

Floor4::Floor4(){
  type = 4;
  // chamber1
  addRowPair(chamber1, chamber1Num, 3, 4, 22, counter1);
  addRowPair(chamber1, chamber1Num, 4, 4, 22, counter1);
  addRowPair(chamber1, chamber1Num, 5, 4, 16, counter1);
  addRowPair(chamber1, chamber1Num, 6, 4, 16, counter1);
  addRowPair(chamber1, chamber1Num, 7, 4, 16, counter1);
  // chamber2
  addRowPair(chamber2, chamber2Num, 3, 41, 58, counter2);
  addRowPair(chamber2, chamber2Num, 4, 41, 58, counter2);
  addRowPair(chamber2, chamber2Num, 5, 27, 58, counter2);
  addRowPair(chamber2, chamber2Num, 6, 27, 58, counter2);
  addRowPair(chamber2, chamber2Num, 7, 27, 58, counter2);
  // chamber3
  addRowPair(chamber3, chamber3Num, 4, 66, 74, counter3);
  addRowPair(chamber3, chamber3Num, 5, 66, 74, counter3);
  addRowPair(chamber3, chamber3Num, 6, 66, 74, counter3);
  addRowPair(chamber3, chamber3Num, 7, 66, 74, counter3);
  addRowPair(chamber3, chamber3Num, 8, 66, 74, counter3);
  addRowPair(chamber3, chamber3Num, 9, 66, 74, counter3);
  addRowPair(chamber3, chamber3Num, 10, 66, 74, counter3);
  addRowPair(chamber3, chamber3Num, 11, 66, 74, counter3);
  // chamber4
  addRowPair(chamber4, chamber4Num, 14, 14, 34, counter4);
  addRowPair(chamber4, chamber4Num, 15, 14, 34, counter4);
  addRowPair(chamber4, chamber4Num, 16, 14, 34, counter4);
  addRowPair(chamber4, chamber4Num, 17, 14, 34, counter4);
  addRowPair(chamber4, chamber4Num, 18, 14, 34, counter4);
  addRowPair(chamber4, chamber4Num, 19, 14, 34, counter4);
  addRowPair(chamber4, chamber4Num, 20, 14, 38, counter4);
  addRowPair(chamber4, chamber4Num, 21, 14, 38, counter4);
  addRowPair(chamber4, chamber4Num, 22, 14, 38, counter4);
  // chamber5
  addRowPair(chamber5, chamber5Num, 16, 49, 70, counter5);
  addRowPair(chamber5, chamber5Num, 17, 49, 70, counter5);
  addRowPair(chamber5, chamber5Num, 18, 49, 70, counter5);
  addRowPair(chamber5, chamber5Num, 19, 49, 70, counter5);
  addRowPair(chamber5, chamber5Num, 20, 47, 70, counter5);
  addRowPair(chamber5, chamber5Num, 21, 47, 70, counter5);
  addRowPair(chamber5, chamber5Num, 22, 47, 70, counter5);
  // horWall
  addRowPair(horWall, horWallNum, 0, 1, 77, counter6);
  addRowPair(horWall, horWallNum, 2, 4, 22, counter6);
  addRowPair(horWall, horWallNum, 2, 41, 58, counter6);
  addRowPair(horWall, horWallNum, 3, 66, 74, counter6);
  addRowPair(horWall, horWallNum, 4, 27, 39, counter6);
  addRowPair(horWall, horWallNum, 6, 18, 22, counter6);
  addRowPair(horWall, horWallNum, 6, 18, 22, counter6);
  addRowPair(horWall, horWallNum, 8, 4, 6, counter6);
  addRowPair(horWall, horWallNum, 8, 8, 16, counter6);
  addRowPair(horWall, horWallNum, 8, 27, 47, counter6);
  addRowPair(horWall, horWallNum, 8, 49, 58, counter6);
  addRowPair(horWall, horWallNum, 12, 66, 68, counter6);
  addRowPair(horWall, horWallNum, 12, 70, 74, counter6);
  addRowPair(horWall, horWallNum, 13, 14, 24, counter6);
  addRowPair(horWall, horWallNum, 13, 26, 34, counter6);
  addRowPair(horWall, horWallNum, 15, 49, 57, counter6);
  addRowPair(horWall, horWallNum, 15, 59, 70, counter6);
  addRowPair(horWall, horWallNum, 19, 36, 38, counter6);
  addRowPair(horWall, horWallNum, 23, 14, 38, counter6);
  addRowPair(horWall, horWallNum, 23, 47, 38, counter6);
  addRowPair(horWall, horWallNum, 24, 1, 70, counter6);
  // verWall
  addColPair(verWall, verWallNum, 0, 0, 24, counter7);
  addColPair(verWall, verWallNum, 3, 2, 8, counter7);
  addColPair(verWall, verWallNum, 13, 13, 19, counter7);
  addColPair(verWall, verWallNum, 13, 21, 23, counter7);
  addColPair(verWall, verWallNum, 17, 6, 8, counter7);
  addColPair(verWall, verWallNum, 23, 2, 2, counter7);
  addColPair(verWall, verWallNum, 23, 4, 6, counter7);
  addColPair(verWall, verWallNum, 26, 4, 8, counter7);
  addColPair(verWall, verWallNum, 35, 13, 13, counter7);
  addColPair(verWall, verWallNum, 35, 17, 21, counter7);
  addColPair(verWall, verWallNum, 39, 19, 20, counter7);
  addColPair(verWall, verWallNum, 39, 22, 23, counter7);
  addColPair(verWall, verWallNum, 40, 2, 2, counter7);
  addColPair(verWall, verWallNum, 40, 4, 4, counter7);
  addColPair(verWall, verWallNum, 40, 2, 2, counter7);
  addColPair(verWall, verWallNum, 46, 19, 20, counter7);
  addColPair(verWall, verWallNum, 46, 22, 23, counter7);
  addColPair(verWall, verWallNum, 48, 15, 19, counter7);
  addColPair(verWall, verWallNum, 59, 2, 4, counter7);
  addColPair(verWall, verWallNum, 59, 6, 8, counter7);
  addColPair(verWall, verWallNum, 65, 3, 4, counter7);
  addColPair(verWall, verWallNum, 65, 6, 9, counter7);
  addColPair(verWall, verWallNum, 65, 11, 12, counter7);
  addColPair(verWall, verWallNum, 71, 15, 23, counter7);
  addColPair(verWall, verWallNum, 75, 3, 12, counter7);
  addColPair(verWall, verWallNum, 78, 0, 24, counter7);
  // passage
  addColPair(passage, passageNum, 7, 11, 19, counter8);
  addColPair(passage, passageNum, 25, 11, 12, counter8);
  addRowPair(passage, passageNum, 3, 24, 39, counter8);
  addRowPair(passage, passageNum, 5, 60, 64, counter8);
  addRowPair(passage, passageNum, 9, 7, 7, counter8);
  addRowPair(passage, passageNum, 9, 48, 48, counter8);
  addRowPair(passage, passageNum, 10, 7, 64, counter8);
  addRowPair(passage, passageNum, 13, 58, 69, counter8);
  addRowPair(passage, passageNum, 14, 36, 58, counter8);
  addRowPair(passage, passageNum, 20, 7, 12, counter8);
  addRowPair(passage, passageNum, 21, 40, 45, counter8);
  // door
  addRowPair(door, doorNum, 3, 23, 23, counter9);
  addRowPair(door, doorNum, 3, 40, 40, counter9);
  addRowPair(door, doorNum, 5, 59, 59, counter9);
  addRowPair(door, doorNum, 5, 65, 65, counter9);
  addRowPair(door, doorNum, 8, 7, 7, counter9);
  addRowPair(door, doorNum, 8, 48, 48, counter9);
  addRowPair(door, doorNum, 10, 65, 65, counter9);
  addRowPair(door, doorNum, 12, 69, 69, counter9);
  addRowPair(door, doorNum, 13, 25, 25, counter9);
  addRowPair(door, doorNum, 14, 35, 35, counter9);
  addRowPair(door, doorNum, 15, 58, 58, counter9);
  addRowPair(door, doorNum, 20, 13, 13, counter9);
  addRowPair(door, doorNum, 21, 39, 39, counter9);
  addRowPair(door, doorNum, 21, 46, 46, counter9);
}

Floor4::~Floor4() {
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


/*void Floor4::print() {
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
  Floor4 f;
  f.print();
  return 1;
}*/
