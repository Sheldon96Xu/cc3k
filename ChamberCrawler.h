#ifndef __CHAMBERCRAWLER_H__
#define __CHAMBERCRAWLER_H__
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Player;
class Enemy;
class Potion;
class Treasure;
class TextDisplay;
class Floor;
class Factory;
class DragonHoard;

class CC3K {
	Factory * factory;
	ifstream ifs;
	Player * PC;
	Floor * Map;//std::shared_ptr<Floor> Map;  // The actual map.
	TextDisplay * td;//std::shared_ptr<TextDisplay> td; 	// The text display.
	Potion * temp;
	int level;	// Level of game
	vector<Potion *> potions;
	vector<Potion *> potionsBackup;
	vector<Treasure *> golds;
	vector<Treasure *> goldsBackup;
	vector<Enemy *> enemies;
	vector<Enemy *> enemiesBackup;
	pair<int, int> stair;
	pair<int, int> stairBackup;
	pair<int, int> PCBackup;
	pair<int, int> basePC;
	pair<int, int> getDest(pair<int,int>, string);
	pair<int, int> radiusOneRand(pair<int, int>);
	static bool dynamic;
	bool readMode;
	bool over;
	bool random;
	void clearUsage();
	string word(string);
	int playerChamber;
	void resetAtkDef();
	void clearObjects();
	void clearBackups();
	bool emptyTile(pair<int,int>);
	bool inRange(Enemy *);
	bool inRange(Treasure *);
	bool inRange(Potion *);
	bool isPotion(pair<int,int>) const;
	bool isGold(pair<int,int>) const;
	bool isEnemy(pair<int,int>) const;
	void moveEnemy( Enemy *);
	void generateObjects(int);
	void spawnPC();
	void match(vector<DragonHoard *>, vector<Enemy *>);
	void useBackup();
	void readLevel(string s = "");
        void initPC(string);
	void initStair();
        vector <int> floorType; ///////////
public:
	CC3K();
	~CC3K();
	void setRandom();
	void setFile(string);
//	void initPC(string);
//	void initStair();
	void attack(string);
	void usePotion(string);
	void movePC(string);
	void controlEnemies();
	void enemyAction();
	void levelUp(string s = ""); // Sets up the floor at the new level.
	bool gameOver();
	friend std::ostream &operator<<(std::ostream &out, const CC3K &g);
};

#endif

