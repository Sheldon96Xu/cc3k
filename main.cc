#include "ChamberCrawler.h"
using namespace std;

int main(int argc, char *argv[]) {
	cin.exceptions(ios::eofbit|ios::failbit);
	string cmd;
	CC3K *game = nullptr;

	try {
		while (true) {
			game = new CC3K;
			string race;
			cout << "Choose your race:" << endl
				 << "(default): Shade" << endl
				 << "d: Drow" << endl
				 << "v: Vampire" << endl
				 << "t: Troll" << endl
				 << "g: Goblin" << endl
				 << "j: Jeff(immortal)" << endl;
			cin >> race;
			if (argc == 1) {
				cout << "Want random chamber? y(yes)/n(no)" << endl; 
				string random;
				while (true) {
					cin >> random;
					if (random == "n") {
						break;
					}
					if (random == "y") {
						game->setRandom();
						break;
					}
				}
				if      (race == "d") game->levelUp("Drow");
				else if (race == "v") game->levelUp("Vampire");
				else if (race == "t") game->levelUp("Troll");
				else if (race == "g") game->levelUp("Goblin");
				else if (race == "j") game->levelUp("Jeff");
				else                  game->levelUp("Shade");
			}
			else {
				game->setFile(argv[1]);
				game->levelUp(race);
				if (game->gameOver()) {
				  cout << "No Player read." << endl;
				  delete game;
				  return 0;
				}
			} 
			cout << *game;
			while (true) {
				cin >> cmd;
				if (cmd == "q") {
					delete game;
					return 0;
				}
				else if (cmd == "r") {
					delete game;
					break;
				}
				else if (cmd == "up") {
					game->levelUp();
					cout << *game;
				}
				else if (cmd == "u") {
					string dir;
					cin >> dir;
					game->usePotion(dir);
					game->enemyAction();
					cout << *game;
				}
				else if (cmd == "a") {
					string dir;
					cin >> dir;
					game->attack(dir);
					game->enemyAction();
					cout << *game;
				}
				else if (cmd == "f") {
					game->controlEnemies();
				}
				else if (cmd == "no" || cmd == "so" || cmd == "ea" || cmd == "we"
						|| cmd == "ne"|| cmd == "nw"|| cmd == "se"|| cmd == "sw") {
					game->movePC(cmd);
					game->enemyAction();
					cout << *game;
				}
				if (game->gameOver()) {
					cout << "Start again? y(yes)/n(no)" << endl;
					string yesNo;
					while (true) {
						cin >> yesNo;
						if (yesNo == "n") {
							delete game;
							return 0;
						}
						if (yesNo == "y") {
							cmd = "r";
							delete game;
							break;
						}
					}
					break;
				}
			}
		}
	}
  catch (ios::failure &) {}
}
