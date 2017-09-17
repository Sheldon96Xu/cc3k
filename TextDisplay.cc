#include <iostream>
#include <utility>
#include "TextDisplay.h"
#include "Player.h"
#include "Floor.h"
#include "Floor1.h"
#include "Floor2.h"
#include "Floor3.h"
#include "Floor4.h"
#include "Floor5.h"

#include <cstdlib>
using namespace std;

Player *TextDisplay::player = nullptr;

string TextDisplay::race = "";

string TextDisplay::message = "";

int TextDisplay::floor = 0;

TextDisplay::TextDisplay(int type){
  if (type == 1) {
	theDisplay.emplace_back("|-----------------------------------------------------------------------------|");
	theDisplay.emplace_back("|                                                                             |");
	theDisplay.emplace_back("| |--------------------------|        |-----------------------|               |");
	theDisplay.emplace_back("| |..........................|        |.......................|               |");
	theDisplay.emplace_back("| |..........................+########+.......................|-------|       |");
	theDisplay.emplace_back("| |..........................|   #    |...............................|--|    |");
	theDisplay.emplace_back("| |..........................|   #    |..................................|--| |");
	theDisplay.emplace_back("| |----------+---------------|   #    |----+----------------|...............| |");
	theDisplay.emplace_back("|            #                 #############                |...............| |");
	theDisplay.emplace_back("|            #                 #     |-----+------|         |...............| |");
	theDisplay.emplace_back("|            #                 #     |............|         |...............| |");
	theDisplay.emplace_back("|            ###################     |............|   ######+...............| |");
	theDisplay.emplace_back("|            #                 #     |............|   #     |...............| |");
	theDisplay.emplace_back("|            #                 #     |-----+------|   #     |--------+------| |");
	theDisplay.emplace_back("|  |---------+-----------|     #           #          #              #        |");
	theDisplay.emplace_back("|  |.....................|     #           #          #         |----+------| |");
	theDisplay.emplace_back("|  |.....................|     ########################         |...........| |");
	theDisplay.emplace_back("|  |.....................|     #           #                    |...........| |");
	theDisplay.emplace_back("|  |.....................|     #    |------+--------------------|...........| |");
	theDisplay.emplace_back("|  |.....................|     #    |.......................................| |");
	theDisplay.emplace_back("|  |.....................+##########+.......................................| |");
	theDisplay.emplace_back("|  |.....................|          |.......................................| |");
	theDisplay.emplace_back("|  |---------------------|          |---------------------------------------| |");
	theDisplay.emplace_back("|                                                                             |");
	theDisplay.emplace_back("|-----------------------------------------------------------------------------|");
  }
  else if (type == 2) {
	theDisplay.emplace_back("|-----------------------------------------------------------------------------|");
	theDisplay.emplace_back("|                                                                             |");
	theDisplay.emplace_back("| |----------------|        |--------------------------------------------|    |");
	theDisplay.emplace_back("| |................|        |............................................|    |");
	theDisplay.emplace_back("| |................+########+............................................|    |");
	theDisplay.emplace_back("| |................|        |............................................|    |");
	theDisplay.emplace_back("| |................|        |............................................|    |");
	theDisplay.emplace_back("| |---+------------|        |-------+------------------------------------|    |");
	theDisplay.emplace_back("|     ###############################  |--------------|                       |");
	theDisplay.emplace_back("|     #                 #     |-----+--|..............|         |-----------| |");
	theDisplay.emplace_back("|     #                 #     |.......................|         |...........| |");
	theDisplay.emplace_back("|     #                 #     |.......................+#########+...........| |");
	theDisplay.emplace_back("|     #                 #     |-----+--------|........|         |...........| |");
	theDisplay.emplace_back("||----+-----------|     #           #        |........|         |...........| |");
	theDisplay.emplace_back("||................|     #           #        |----+---|         |...........| |");
	theDisplay.emplace_back("||................|     ###########################             |...........| |");
	theDisplay.emplace_back("||................|     #           #                           |...........| |");
	theDisplay.emplace_back("||..........|-----|     #|----------+---------------------------|...........| |");
	theDisplay.emplace_back("||..........|           #|..................................................| |");
	theDisplay.emplace_back("||..........+############+..................................................| |");
	theDisplay.emplace_back("||..........|            |..................................................| |");
	theDisplay.emplace_back("||----------|            |--------------------------------------------------| |");
	theDisplay.emplace_back("|                                                                             |");
	theDisplay.emplace_back("|                                                                             |");
	theDisplay.emplace_back("|-----------------------------------------------------------------------------|");
  }
  else if (type == 3) {
	theDisplay.emplace_back("|-----------------------------------------------------------------------------|");
	theDisplay.emplace_back("|     |-------------|                          |--------------------|         |");
	theDisplay.emplace_back("|     |.............|    |-------------|       |....................|         |");
	theDisplay.emplace_back("| ####+.............|    |.............+#######+....................|         |");
	theDisplay.emplace_back("| #   |.............|    |.............|       |....................|         |");
	theDisplay.emplace_back("| #   |.............+####+.............|       |---------------+----|         |");
	theDisplay.emplace_back("| #   |.............|    |.............|        ################              |");
	theDisplay.emplace_back("| #   |-----+-------|    |.............|        #     |--------+----------|   |");
	theDisplay.emplace_back("| #         #            |.............|        #     |...................|   |");
	theDisplay.emplace_back("| #  |------+------------|.............|        #     |...................|   |");
	theDisplay.emplace_back("| #  |.................................|--------+--|  |...................|   |");
	theDisplay.emplace_back("| #  |.............................................+##+...................|   |");
	theDisplay.emplace_back("| #  |--------+-------------------+----------------|  |...................|   |");
	theDisplay.emplace_back("| #           #                   #                   |...................|   |");
	theDisplay.emplace_back("| #           #         |---------+-------------------|...................|   |");
	theDisplay.emplace_back("| #           #         |.................................................|   |");
	theDisplay.emplace_back("| #           ##########+.................................................|   |");
	theDisplay.emplace_back("| #           #         |.................................................|   |");
	theDisplay.emplace_back("| #           #         |-------------------------------------------------|   |");
	theDisplay.emplace_back("| ##################                |---------------------------------------| |");
	theDisplay.emplace_back("||-----------------+----------------|.......................................| |");
	theDisplay.emplace_back("||..........................................................................| |");
	theDisplay.emplace_back("||--------------------------------------------------------------------------| |");
	theDisplay.emplace_back("|                                                                             |");
	theDisplay.emplace_back("|-----------------------------------------------------------------------------|");
  }
  else if (type == 4) {
	theDisplay.emplace_back("|-----------------------------------------------------------------------------|");
	theDisplay.emplace_back("|                                                                             |");
	theDisplay.emplace_back("|  |-------------------|                |------------------|                  |");
	theDisplay.emplace_back("|  |...................+################+..................|     |---------|  |");
	theDisplay.emplace_back("|  |...................|  |-------------|..................|     |.........|  |");
	theDisplay.emplace_back("|  |...................|  |................................+#####+.........|  |");
	theDisplay.emplace_back("|  |.............|-----|  |................................|     |.........|  |");
	theDisplay.emplace_back("|  |.............|        |................................|     |.........|  |");
	theDisplay.emplace_back("|  |---+---------|        |---------------------+----------|     |.........|  |");
	theDisplay.emplace_back("|      #                                        #                |.........|  |");
	theDisplay.emplace_back("|      ##########################################################+.........|  |");
	theDisplay.emplace_back("|      #                 #                                       |.........|  |");
	theDisplay.emplace_back("|      #                 #                                       |---+-----|  |");
	theDisplay.emplace_back("|      #     |-----------+---------|                      ############        |");
	theDisplay.emplace_back("|      #     |.....................+#######################                   |");
	theDisplay.emplace_back("|      #     |.....................|            |---------+------------|      |");
	theDisplay.emplace_back("|      #     |.....................|            |......................|      |");
	theDisplay.emplace_back("|      #     |.....................|            |......................|      |");
	theDisplay.emplace_back("|      #     |.....................|            |......................|      |");
	theDisplay.emplace_back("|      #     |.....................|---|      |-|......................|      |");
	theDisplay.emplace_back("|      ######+.........................|      |........................|      |");
	theDisplay.emplace_back("|            |.........................+######+........................|      |");
	theDisplay.emplace_back("|            |.........................|      |........................|      |");
	theDisplay.emplace_back("|            |-------------------------|      |------------------------|      |");
	theDisplay.emplace_back("|-----------------------------------------------------------------------------|");
  }
  else if (type == 5){
    theDisplay.emplace_back("|-----------------------------------------------------------------------------|");
	theDisplay.emplace_back("|                                                                             |");
	theDisplay.emplace_back("|      |----------------------|                                               |");
	theDisplay.emplace_back("|      |......................|         |----------------------------|        |");
	theDisplay.emplace_back("|   ###+......................+#########+............................|        |");
	theDisplay.emplace_back("|   #  |......................|     #   |............................|        |");
	theDisplay.emplace_back("|   #  |---------+------------|     #   |............................|        |");
	theDisplay.emplace_back("|   #            #                  #   |------------------|.........|        |");
	theDisplay.emplace_back("|   #            #                  #                      |-------+-|        |");
	theDisplay.emplace_back("|   #            #         |--------+------|                       #          |");
	theDisplay.emplace_back("|   #            #         |...............+########################          |");
	theDisplay.emplace_back("|   #            #         |...............|                   |---+-----|    |");
	theDisplay.emplace_back("|   #######################+...............|------|            |.........|    |");
	theDisplay.emplace_back("|   #            #         |......................|            |.........|    |");
	theDisplay.emplace_back("|   #            #         |......................|    |-------|.........|    |");
	theDisplay.emplace_back("|   #            #         |----------------+-----|    |.................|    |");
	theDisplay.emplace_back("|   #            #                          #          |.................|---||");
	theDisplay.emplace_back("|   #            ######################################+.....................||");
	theDisplay.emplace_back("|   #      |-----+----------|                          |.....................||");
	theDisplay.emplace_back("|   #      |................|                          |---------------------||");
	theDisplay.emplace_back("|   #######+................|                                                 |");
	theDisplay.emplace_back("|          |................|                                                 |");
	theDisplay.emplace_back("|          |----------------|                                                 |");
	theDisplay.emplace_back("|                                                                             |");
	theDisplay.emplace_back("|-----------------------------------------------------------------------------|");
  } else if (type == 6) {
	theDisplay.emplace_back("|-----------------------------------------------------------------------------|");
	theDisplay.emplace_back("|                                                                             |");
	theDisplay.emplace_back("|       ||-||        ||-   ||------||     ||------||    ||||------||          |");
	theDisplay.emplace_back("|       ||  ||       ||   ||        ||   ||        ||   ||         ||         |");
	theDisplay.emplace_back("|       ||   ||      ||   ||        ||   ||        ||   ||        ||          |");
	theDisplay.emplace_back("|       ||    ||     ||   ||        ||   ||        ||   |||-------||          |");
	theDisplay.emplace_back("|       ||     ||    ||   ||        ||   ||        ||   ||         ||         |");
	theDisplay.emplace_back("|       ||      ||   ||   ||        ||   ||        ||   ||         ||         |");
	theDisplay.emplace_back("|       ||       ||  ||   ||        ||   ||        ||   ||         ||         |");
	theDisplay.emplace_back("|      -||        ||-||    ||------||     ||------||    |||-------||          |");
	theDisplay.emplace_back("|                                                                             |");
	theDisplay.emplace_back("|                                                                             |");
	theDisplay.emplace_back("|                                                                             |");
	theDisplay.emplace_back("|                                                                             |");
	theDisplay.emplace_back("|        ||||-------||    |||--------||   -||      ||   ||----------||        |");
	theDisplay.emplace_back("|        ||          ||   ||               ||    ||           ||              |");
	theDisplay.emplace_back("|        ||          ||   ||               ||  ||             ||              |");
	theDisplay.emplace_back("|        ||||-------||    ||               ||||               ||              |");
	theDisplay.emplace_back("|        ||     ||        |||-------||     ||||               ||              |");
	theDisplay.emplace_back("|        ||      ||       ||               ||  ||             ||              |");
	theDisplay.emplace_back("|        ||       ||      ||               ||    ||           ||              |");
	theDisplay.emplace_back("|        ||        ||     ||               ||      ||         ||              |");
	theDisplay.emplace_back("|       -||         ||--  |||---------||  -||        ||      -||-             |");
	theDisplay.emplace_back("|                                                                             |");
	theDisplay.emplace_back("|-----------------------------------------------------------------------------|");
  } else {
	theDisplay.emplace_back("|-----------------------------------------------------------------------------|");
	theDisplay.emplace_back("|                                                                             |");
	theDisplay.emplace_back("|                                                                             |");
	theDisplay.emplace_back("|                                                                             |");
	theDisplay.emplace_back("|                                                                             |");
	theDisplay.emplace_back("|                                                                             |");
	theDisplay.emplace_back("|                                                                             |");
	theDisplay.emplace_back("|  ||      ||   ||-----||   ||      ||   ||    ||-||    ||  ----  ||-||   ||  |");
	theDisplay.emplace_back("|   ||    ||   |||     |||  ||      ||   ||    || ||    ||   ||   ||  ||  ||  |");
	theDisplay.emplace_back("|    ||  ||    |||     |||  ||      ||   ||    || ||    ||   ||   ||  ||  ||  |");
	theDisplay.emplace_back("|     ||||     |||     |||  ||      ||   ||    || ||    ||   ||   ||  ||  ||  |");
	theDisplay.emplace_back("|      ||      |||     |||  ||      ||   ||    || ||    ||   ||   ||  ||  ||  |");
	theDisplay.emplace_back("|      ||      |||     |||  ||      ||   ||    || ||    ||   ||   ||  ||  ||  |");
	theDisplay.emplace_back("|      ||      |||     |||  ||      ||   ||    || ||    ||   ||   ||  ||  ||  |");
	theDisplay.emplace_back("|      ||      |||     |||  ||      ||   ||    || ||    ||   ||   ||  ||  ||  |");
	theDisplay.emplace_back("|      ||      |||     |||  ||      ||   ||    || ||    ||   ||   ||  ||  ||  |");
	theDisplay.emplace_back("|      ||      |||     |||  ||      ||    ||  ||   ||  ||    ||   ||  ||  ||  |");
	theDisplay.emplace_back("|      ||       ||-----||    ||----||      ||||     ||||    ----  ||   ||-||  |");
	theDisplay.emplace_back("|                                                                             |");
	theDisplay.emplace_back("|                                                                             |");
	theDisplay.emplace_back("|                                                                             |");
	theDisplay.emplace_back("|                                                                             |");
	theDisplay.emplace_back("|                                                                             |");
	theDisplay.emplace_back("|                                                                             |");
	theDisplay.emplace_back("|-----------------------------------------------------------------------------|");
  }
}


void TextDisplay::showOnMap(int row, int col, char c) {	theDisplay[row][col] = c; }

TextDisplay::~TextDisplay() {
}


void TextDisplay::setPC(Player * p) { player = p; }

void TextDisplay::setStair(int row, int col) { theDisplay[row][col] = '\\'; }

void TextDisplay::setRace(string r) { race = r; }

void TextDisplay::setMessage(string m) { message = m; }

string TextDisplay::getMessage() const { return message; }

void TextDisplay::setLevel(int lv) { floor = lv; }

ostream &operator<<(ostream &out, const TextDisplay &td) {
  for (unsigned int i = 0; i < td.theDisplay.size(); ++i) {
    out << td.theDisplay[i] << endl;
  }
  // 1st line of info
  out << "Race: " << td.race << " Gold: " << td.player->getGold()
  << "                                              Floor " 
  << td.floor << endl;
  
  // 2nd line of info
  out << "HP: " << td.player->getHP() << endl;
  
  // 3rd line of info
  out << "Atk: " << td.player->getAttack() << endl;
  
  // 4th line of info
  out << "Def: " << td.player->getDefense() << endl;
  
  // 5th line of info
  out << "Action: " << td.message << endl;
  return out;
}

