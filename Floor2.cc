#include "Floor2.h"
#include <vector>
#include <iostream>
using namespace std;

Floor2::Floor2() {
	type = 2;
  // chamber1
  addRowPair(chamber1, chamber1Num, 3, 3, 18, counter1);
  addRowPair(chamber1, chamber1Num, 4, 3, 18, counter1);
  addRowPair(chamber1, chamber1Num, 5, 3, 18, counter1);
  addRowPair(chamber1, chamber1Num, 6, 3, 18, counter1);
  // chamber2
  addRowPair(chamber2, chamber2Num, 3, 29, 72, counter2);
  addRowPair(chamber2, chamber2Num, 4, 29, 72, counter2);
  addRowPair(chamber2, chamber2Num, 5, 29, 72, counter2);
  addRowPair(chamber2, chamber2Num, 6, 29, 72, counter2);
  // chamber3
  addRowPair(chamber3, chamber3Num, 14, 2, 17, counter3);
  addRowPair(chamber3, chamber3Num, 15, 2, 17, counter3);
  addRowPair(chamber3, chamber3Num, 16, 2, 11, counter3);
  addRowPair(chamber3, chamber3Num, 17, 2, 11, counter3);
  addRowPair(chamber3, chamber3Num, 18, 2, 11, counter3);
  addRowPair(chamber3, chamber3Num, 19, 2, 11, counter3);
  addRowPair(chamber3, chamber3Num, 20, 2, 11, counter3);
  // chamber4
  addRowPair(chamber4, chamber4Num, 9, 40, 53, counter4);
  addRowPair(chamber4, chamber4Num, 10, 31, 53, counter4);
  addRowPair(chamber4, chamber4Num, 11, 31, 53, counter4);
  addRowPair(chamber4, chamber4Num, 12, 46, 53, counter4);
  addRowPair(chamber4, chamber4Num, 13, 46, 53, counter4);
  // chamber5
  addRowPair(chamber5, chamber5Num, 10, 65, 75, counter5);
  addRowPair(chamber5, chamber5Num, 11, 65, 75, counter5);
  addRowPair(chamber5, chamber5Num, 12, 65, 75, counter5);
  addRowPair(chamber5, chamber5Num, 13, 65, 75, counter5);
  addRowPair(chamber5, chamber5Num, 14, 65, 75, counter5);
  addRowPair(chamber5, chamber5Num, 15, 65, 75, counter5);
  addRowPair(chamber5, chamber5Num, 16, 65, 75, counter5);
  addRowPair(chamber5, chamber5Num, 17, 65, 75, counter5);
  addRowPair(chamber5, chamber5Num, 18, 26, 75, counter5);
  addRowPair(chamber5, chamber5Num, 19, 26, 75, counter5);
  addRowPair(chamber5, chamber5Num, 20, 26, 75, counter5);  
  // horWall
  addRowPair(horWall, horWallNum, 0, 1, 77, counter6);
  addRowPair(horWall, horWallNum, 2, 3, 18, counter6);
  addRowPair(horWall, horWallNum, 2, 29, 72, counter6);
  addRowPair(horWall, horWallNum, 7, 3, 5, counter6);
  addRowPair(horWall, horWallNum, 7, 7, 18, counter6);
  addRowPair(horWall, horWallNum, 7, 29, 35, counter6);
  addRowPair(horWall, horWallNum, 7, 37, 72, counter6);
  addRowPair(horWall, horWallNum, 8, 40, 53, counter6);
  addRowPair(horWall, horWallNum, 9, 31, 35, counter6);
  addRowPair(horWall, horWallNum, 9, 37, 38, counter6);
  addRowPair(horWall, horWallNum, 9, 65, 75, counter6);
  addRowPair(horWall, horWallNum, 12, 31, 35, counter6);
  addRowPair(horWall, horWallNum, 12, 37, 44, counter6);
  addRowPair(horWall, horWallNum, 13, 2, 5, counter6);
  addRowPair(horWall, horWallNum, 13, 7, 17, counter6);
  addRowPair(horWall, horWallNum, 14, 46, 49, counter6);
  addRowPair(horWall, horWallNum, 14, 51, 53, counter6);
  addRowPair(horWall, horWallNum, 17, 26, 35, counter6);
  addRowPair(horWall, horWallNum, 17, 37, 63, counter6);
  addRowPair(horWall, horWallNum, 21, 2, 11, counter6);
  addRowPair(horWall, horWallNum, 21, 26, 75, counter6);
  addRowPair(horWall, horWallNum, 24, 1, 77, counter6);
  // verWall
  addColPair(verWall, verWallNum, 0, 0, 24, counter7);
  addColPair(verWall, verWallNum, 1, 13, 21, counter7);
  addColPair(verWall, verWallNum, 2, 2, 7, counter7);
  addColPair(verWall, verWallNum, 12, 17, 18, counter7);
  addColPair(verWall, verWallNum, 12, 20, 21, counter7);
  addColPair(verWall, verWallNum, 18, 13, 17, counter7);
  addColPair(verWall, verWallNum, 19, 2, 3, counter7);
  addColPair(verWall, verWallNum, 19, 5, 7, counter7);
  addColPair(verWall, verWallNum, 25, 17, 18, counter7);
  addColPair(verWall, verWallNum, 25, 20, 21, counter7);
  addColPair(verWall, verWallNum, 28, 2, 3, counter7);
  addColPair(verWall, verWallNum, 28, 5, 7, counter7);
  addColPair(verWall, verWallNum, 30, 9, 12, counter7);
  addColPair(verWall, verWallNum, 36, 18, 19, counter7);
  addColPair(verWall, verWallNum, 39, 8, 9, counter7);
  addColPair(verWall, verWallNum, 45, 12, 14, counter7);
  addColPair(verWall, verWallNum, 50, 9, 13, counter7);
  addColPair(verWall, verWallNum, 54, 8, 10, counter7);
  addColPair(verWall, verWallNum, 54, 12, 14, counter7);
  addColPair(verWall, verWallNum, 64, 9, 10, counter7);
  addColPair(verWall, verWallNum, 64, 12, 17, counter7);
  addColPair(verWall, verWallNum, 73, 2, 7, counter7);
  addColPair(verWall, verWallNum, 76, 9, 21, counter7);
  addColPair(verWall, verWallNum, 78, 0, 24, counter7);
  // passage
  addColPair(passage, passageNum, 6, 8, 12, counter8);
  addColPair(passage, passageNum, 24, 8, 19, counter8);
  addColPair(passage, passageNum, 36, 13, 16, counter8);
  addRowPair(passage, passageNum, 4, 20, 27, counter8);
  addRowPair(passage, passageNum, 8, 7, 23, counter8);
  addRowPair(passage, passageNum, 8, 25, 36, counter8);
  addRowPair(passage, passageNum, 11, 55, 63, counter8);
  addRowPair(passage, passageNum, 15, 25, 35, counter8);
  addRowPair(passage, passageNum, 15, 37, 50, counter8);
  addRowPair(passage, passageNum, 19, 13, 23, counter8);
  // door
  addRowPair(door, doorNum, 4, 19, 19, counter9);
  addRowPair(door, doorNum, 4, 28, 28, counter9);
  addRowPair(door, doorNum, 7, 6, 6, counter9);
  addRowPair(door, doorNum, 7, 36, 36, counter9);
  addRowPair(door, doorNum, 9, 36, 36, counter9);
  addRowPair(door, doorNum, 11, 54, 54, counter9);
  addRowPair(door, doorNum, 11, 64, 64, counter9);
  addRowPair(door, doorNum, 12, 36, 36, counter9);
  addRowPair(door, doorNum, 13, 6, 6, counter9);
  addRowPair(door, doorNum, 14, 50, 50, counter9);
  addRowPair(door, doorNum, 17, 36, 36, counter9);
  addRowPair(door, doorNum, 19, 12, 12, counter9);
  addRowPair(door, doorNum, 19, 25, 25, counter9);
}

Floor2::~Floor2() {
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


/*void Floor2::print() {
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
  Floor2 f;
  f.print();
  return 1;
}*/
