#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <iostream>
#include <memory>
#include <vector>
#include <string>
class Player;

class TextDisplay {
  //std::vector<std::vector</*std::shared_ptr<Cell>*/Cell*> > theDisplay;
  std::vector<std::string> theDisplay;
  static Player * player;
  static std::string race;
  static std::string message;
  static int floor;
  
 public:
  TextDisplay(int);
  
  void showOnMap(int, int, char);

  ~TextDisplay();
  
  void setPC(Player *);
  
  void setStair(int, int);
  
  void setRace(std::string);
  
  void setMessage(std::string);
  
  std::string getMessage() const;
  
  void setLevel(int);

  friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif
