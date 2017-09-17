#include <iostream>
#include "ChamberCrawler.h"
#include "Floor.h"
#include "Floor1.h"
#include "Floor2.h"
#include "Floor3.h"
#include "Floor4.h"
#include "Floor5.h"
#include "TextDisplay.h"
#include "Shade.h"
#include "Drow.h"
#include "Vampire.h"
#include "Troll.h"
#include "Goblin.h"
#include "Jeff.h"
#include "Enemy.h"
#include "Factory.h"
#include "RH.h"
#include "Treasure.h"
#include "DragonHoard.h"
#include "Dragon.h"
using namespace std;

bool CC3K::dynamic = true;

CC3K::CC3K(): factory{nullptr}, PC{nullptr}, Map{nullptr}, td{nullptr}, temp{new Rh}, 
			  level{0}, over{false}, random{false} {floorType = vector<int>{1,2,3,4,5};}

CC3K::~CC3K() {
	if (readMode) clearBackups();
	clearObjects();
	delete PC;
	delete factory;
	delete Map;
	delete td;
	delete temp;
}

void CC3K::resetAtkDef() {
	PC->setAttack(basePC.first);
	PC->setDefense(basePC.second);
}

void CC3K::clearUsage() {
	for (auto &i : temp->usedList) {
		i.second = false;
	}
}

void CC3K::setRandom() { random = true; }

void CC3K::setFile(string filename) {
	ifs.open(filename);
	readMode = true;
}

string CC3K::word(string dir) {
	if      (dir == "no") return "North";
	else if (dir == "so") return "South";
	else if (dir == "we") return "West";
	else if (dir == "ea") return "East";
	else if (dir == "ne") return "Northeast";
	else if (dir == "nw") return "Northwest";
	else if (dir == "se") return "Southeast";
	else                  return "Southwest";
}

bool CC3K::isPotion(pair<int, int> pos) const {
	for (unsigned int i = 0; i < potions.size(); ++i) { 
		if (potions[i]->getPosn().first == pos.first 
			&& potions[i]->getPosn().second == pos.second) {
			return true;
		}
	}
	return false;
}

bool CC3K::isGold(pair<int, int> pos) const {
	for (unsigned int i = 0; i < golds.size(); ++i) { 
		if (golds[i]->getPosn().first == pos.first 
			&& golds[i]->getPosn().second == pos.second) {
			return true;
		}
	}
	return false;
}

bool CC3K::isEnemy(pair<int, int> pos) const {
	for (unsigned int i = 0; i < enemies.size(); ++i) { 
		if (enemies[i]->getPosn().first == pos.first 
			&& enemies[i]->getPosn().second == pos.second) {
			return true;
		}
	}
	return false;
}

pair<int,int> CC3K::getDest(pair<int,int>curPos, string dir) {
	pair<int,int>nextPos;
	if (dir == "no") {
		nextPos.first = curPos.first - 1;
		nextPos.second = curPos.second;
	}
	else if (dir == "so") {
		nextPos.first = curPos.first + 1;
		nextPos.second = curPos.second;
	}
	else if (dir == "ea") {
		nextPos.first = curPos.first;
		nextPos.second = curPos.second + 1;
	}
	else if (dir == "we") {
		nextPos.first = curPos.first;
		nextPos.second = curPos.second - 1;
	}
	else if (dir == "ne") {
		nextPos.first = curPos.first - 1;
		nextPos.second = curPos.second + 1;
	}
	else if (dir == "nw") {
		nextPos.first = curPos.first - 1;
		nextPos.second = curPos.second - 1;
	}
	else if (dir == "se") {
		nextPos.first = curPos.first + 1;
		nextPos.second = curPos.second + 1;
	}
	else if (dir == "sw") {
		nextPos.first = curPos.first + 1;
		nextPos.second = curPos.second - 1;
	}
	return nextPos;
}

pair<int,int> CC3K::radiusOneRand(pair<int,int> pos) {
	while (true) {
		int n = rand() % 8;
		string dir;
		if      (n == 0) dir = "no";
		else if (n == 1) dir = "so";
		else if (n == 2) dir = "ea";
		else if (n == 3) dir = "we";
		else if (n == 4) dir = "ne";
		else if (n == 5) dir = "nw";
		else if (n == 6) dir = "se";
		else             dir = "sw";
		pair<int, int> randPos = getDest(pos, dir);
		if (emptyTile(randPos)) {
			return randPos;
		}
	}
}

void CC3K::clearBackups() {
	for (unsigned int i = 0; i < potionsBackup.size(); ++i) {
		delete potionsBackup[i]; 
	}
	potionsBackup.clear();
	for (unsigned int i = 0; i < goldsBackup.size(); ++i) {
		delete goldsBackup[i]; 
	}
	goldsBackup.clear();
	for (unsigned int i = 0; i < enemiesBackup.size(); ++i) {
		delete enemiesBackup[i]; 
	}
	enemiesBackup.clear();
}

void CC3K::clearObjects() {
	for (unsigned int i = 0; i < potions.size(); ++i) {
		delete potions[i]; 
	}
	potions.clear();
	for (unsigned int i = 0; i < golds.size(); ++i) {
		delete golds[i]; 
	}
	golds.clear();
	for (unsigned int i = 0; i < enemies.size(); ++i) {
		delete enemies[i]; 
	}
	enemies.clear();
}

void CC3K::generateObjects(int enemyNum) {
	srand(time(0));
	for (int i = 0; i < 10; ++i) {
		Potion *p = factory->createPotion();
		int chamber = rand() % 5;
		pair<int,int> pos = Map->randomPos(chamber + 1); 
		p->setPosn(pos.first, pos.second);
		td->showOnMap(pos.first, pos.second, p->getSymbol());
		potions.emplace_back(p);
	}
	for (int i = 0; i < 10; ++i) {
		Treasure *t = factory->createTreasure();
		int chamber = rand() % 5;
		pair<int,int> pos = Map->randomPos(chamber + 1); 
		t->setPosn(pos.first, pos.second);
		td->showOnMap(pos.first, pos.second, t->getSymbol());
		golds.emplace_back(t);
		if (t->getValue() == 6) {
			DragonHoard *dh = static_cast<DragonHoard*>(t);
			Enemy *e = factory->createDragon(dh);
			pair<int,int> dragonPos =radiusOneRand(pos); 
			e->setPosn(dragonPos.first, dragonPos.second);
			dh->setDragon(e);
			td->showOnMap(dragonPos.first, dragonPos.second, e->getSymbol());
			enemies.emplace_back(e);
		}
	}
	for (int i = 0; i < enemyNum; ++i) {
		Enemy *e = factory->createEnemy();
		int chamber = rand() % 5;
		pair<int,int> pos = Map->randomPos(chamber + 1);
		e->setPosn(pos.first, pos.second);
		td->showOnMap(pos.first, pos.second, e->getSymbol());
		enemies.emplace_back(e);
	}
}

void CC3K::initPC(string race) {
	if      (race == "Shade")   PC = new Shade;
	else if (race == "Drow")    PC = new Drow;
	else if (race == "Vampire") PC = new Vampire;
	else if (race == "Troll")   PC = new Troll;
	else if (race == "Goblin")  PC = new Goblin;
	else if (race == "Jeff")    PC = new Jeff;
	basePC.first = PC->getAttack();
	basePC.second = PC->getDefense();
	srand(time(0));
	playerChamber = rand() % 5;
	pair<int,int> pos = Map->randomPos(playerChamber + 1);
	PC->setPosn(pos.first, pos.second);
	td->setRace(race);
	td->setPC(PC);
	td->showOnMap(pos.first, pos.second, '@');
	td->setMessage("Player character has spawned, at (" + 
				   to_string(pos.first) + ", " + to_string(pos.second) + ").");
}

void CC3K::spawnPC() {
	srand(time(0));
	playerChamber = rand() % 5;
	pair<int,int> pos = Map->randomPos(playerChamber + 1);
	PC->setPosn(pos.first, pos.second);
	td->showOnMap(pos.first, pos.second, '@');
	td->setMessage("Player character has spawned in a new level, at (" + 
				   to_string(pos.first) + ", " + to_string(pos.second) + ").");
}

void CC3K::initStair() {
	int stairChamber = rand() % 5;
	while (stairChamber == playerChamber) { stairChamber = rand() % 5; }
	stair = Map->randomPos(stairChamber + 1);
	td->setStair(stair.first, stair.second);
}

void CC3K::controlEnemies() { dynamic = !dynamic; }

void CC3K::movePC(string dir) {
	pair<int, int> curPos = PC->getPosn();
	pair<int, int> nextPos = getDest(curPos, dir);
	if (PC->getSymbol() == 'T') {
		int newHP = PC->getHP() + 5;
		int maxHP = PC->getMax();
		if (newHP > maxHP) newHP = maxHP;
		PC->setHP(newHP);
	}
	if (!(Map->isChamber(nextPos)||Map->isPassage(nextPos)||Map->isDoor(nextPos))) {
		td->setMessage("Unable to move " + word(dir));
		return;
	}
	if (isPotion(nextPos)) {
		td->setMessage("Unable to move into potions.");
		return;
	}
	if (isEnemy(nextPos)) {
		td->setMessage("Unable to move into enemies.");
		return;
	}
	for (unsigned int i = 0; i < golds.size(); ++i) { // collect gold
		if (golds[i]->getPosn().first == nextPos.first 
			&& golds[i]->getPosn().second == nextPos.second) {
			if (golds[i]->getValue() == 6) {
				DragonHoard * dh = static_cast<DragonHoard*>(golds[i]);
				if (!dh->unlocked()) {
					if (isGold(curPos)) td->showOnMap(curPos.first, curPos.second, 'G');
					else td->showOnMap(curPos.first, curPos.second, '.');
					td->showOnMap(nextPos.first, nextPos.second, '@');
					td->setMessage("PC moves " + word(dir) +
									" but cannot collect DragonHoard.");
					PC->setPosn(nextPos.first, nextPos.second);
					return;
				}
			}
			PC->addGold(golds[i]->getValue());
			td->setMessage("PC moves "+word(dir)+" and collects a treasure.");
			if (isGold(curPos)) td->showOnMap(curPos.first, curPos.second, 'G');
			else td->showOnMap(curPos.first, curPos.second, '.');
			td->showOnMap(nextPos.first, nextPos.second, '@');
			PC->setPosn(nextPos.first, nextPos.second);
			delete golds[i];
			golds.erase(golds.begin() + i);
			return;
		}
	}
	if (nextPos.first == stair.first && nextPos.second == stair.second) {
		levelUp(); 
		return;
	}
	if (Map->isChamber(curPos)) {
		if (isGold(curPos)) td->showOnMap(curPos.first, curPos.second, 'G');
		else td->showOnMap(curPos.first, curPos.second, '.');
		td->showOnMap(nextPos.first, nextPos.second, '@');
		PC->setPosn(nextPos.first, nextPos.second);
	}
	if (Map->isPassage(curPos)) {
		td->showOnMap(curPos.first, curPos.second, '#');
		td->showOnMap(nextPos.first, nextPos.second, '@');
		PC->setPosn(nextPos.first, nextPos.second);
	}
	if (Map->isDoor(curPos)) {
		td->showOnMap(curPos.first, curPos.second, '+');
		td->showOnMap(nextPos.first, nextPos.second, '@');
		PC->setPosn(nextPos.first, nextPos.second);
	}
	td->setMessage("PC moves " + word(dir));
	
	int unknownPotion = 0;
	int unknownTreasure = 0;
	for (unsigned int i = 0; i < potions.size(); ++i) {
		if (inRange(potions[i])) {
			if (potions[i]->usedList[potions[i]->getType()]) {
				string dir;
				int diffX = potions[i]->getPosn().first - PC->getPosn().first;
				int diffY = potions[i]->getPosn().second - PC->getPosn().second;
				if (diffX == 1) {
					if      (diffY == 1) dir = "Southeast";
					else if (diffY == 0) dir = "South";
					else if (diffY == -1) dir = "Southwest";
				}
				else if     (diffX == 0) {
					if      (diffY == 1) dir = "East";
					else if (diffY == -1) dir = "West";
				}
				else if (diffX == -1) {
					if      (diffY == 1) dir = "Northeast";
					else if (diffY == 0) dir = "North";
					else if (diffY == -1) dir = "Northwest";
				}
				td->setMessage(td->getMessage() + ", recognizes " + 
							   potions[i]->getType() + " on " + dir);
			}
			else ++unknownPotion;
		}
	}
	for (unsigned int i = 0; i < golds.size(); ++i) {
		if (inRange(golds[i])) ++unknownTreasure;
	}
	if (unknownPotion || unknownTreasure) td->setMessage(td->getMessage() + " and sees ");
	if (unknownPotion == 1) {
		td->setMessage(td->getMessage() + "an unknown potion");
	}
	else if (unknownPotion > 1) {
		td->setMessage(td->getMessage() + to_string(unknownPotion) + " unknown potions");
	}
	if (unknownPotion && unknownTreasure) td->setMessage(td->getMessage() + " and ");
	if (unknownTreasure == 1) {
		td->setMessage(td->getMessage() + "a treasure");
	}
	else if (unknownTreasure > 1) {
		td->setMessage(td->getMessage() + to_string(unknownTreasure) + " treasures");
	}
	td->setMessage(td->getMessage() + ".");
}

void CC3K::moveEnemy(Enemy *e) {
	pair<int, int> curPos = e->getPosn();
	pair<int, int> nextPos = radiusOneRand(curPos);
	td->showOnMap(curPos.first, curPos.second, '.');
	e->setPosn(nextPos.first, nextPos.second);
	td->showOnMap(nextPos.first, nextPos.second, e->getSymbol());
}

bool CC3K::emptyTile(pair<int, int> pos) {
	if (!Map->isChamber(pos)) return false;
	if (isPotion(pos)) return false;
	if (isGold(pos)) return false;
	if (isEnemy(pos)) return false;
	if (pos.first == stair.first && pos.second == stair.second) return false;
	/*if (pos.first == PC->getPosn().first &&
		pos.second == PC->getPosn().second) return false;*/
	return true;
}

bool CC3K::inRange(Enemy *e) {
	int diffX = e->getPosn().first - PC->getPosn().first;
	int diffY = e->getPosn().second - PC->getPosn().second;
	if (diffX >= -1 && diffX <= 1 && diffY >= -1 && diffY <= 1) return true;
	return false;
}

bool CC3K::inRange(Treasure *t) {
	int diffX = t->getPosn().first - PC->getPosn().first;
	int diffY = t->getPosn().second - PC->getPosn().second;
	if (diffX >= -1 && diffX <= 1 && diffY >= -1 && diffY <= 1) return true;
	return false;
}

bool CC3K::inRange(Potion *p) {
	int diffX = p->getPosn().first - PC->getPosn().first;
	int diffY = p->getPosn().second - PC->getPosn().second;
	if (diffX >= -1 && diffX <= 1 && diffY >= -1 && diffY <= 1) return true;
	return false;
}

void CC3K::attack(string dir) {
	pair<int, int> curPos = PC->getPosn();
	pair<int, int> target = getDest(curPos, dir);
	td->setMessage("Nothing to attack.");
	srand(time(0));
	for (unsigned int i = 0; i < enemies.size(); ++i) {
		if (enemies[i]->getPosn().first == target.first &&
			enemies[i]->getPosn().second == target.second) {
			string sym(1, enemies[i]->getSymbol());
			cout << i << sym << endl;
			int damage = enemies[i]->attackedBy(PC);
			string HP = to_string(enemies[i]->getHP());
			if (damage > 0) {
				td->setMessage("PC deals " + to_string(damage) + " damage to " +
								sym + " (" + HP + " HP).");
			}
			else if (damage < 0) {
				td->setMessage("PC's attack to " +
								sym + " (" + HP + " HP) missed.");
			}
			if (enemies[i]->getHP() == 0) {
				if (enemies[i]->getSymbol() == 'M') {
					Treasure * t = factory->createMerchHoard();
					t->setPosn(target.first, target.second);
					golds.emplace_back(t);
					td->showOnMap(target.first, target.second, t->getSymbol());
				}
				else if (enemies[i]->getSymbol() == 'H') {
					Treasure * t = factory->createNormalTreasure();
					t->setPosn(target.first, target.second);
					golds.emplace_back(t);
					td->showOnMap(target.first, target.second, t->getSymbol());
					t = factory->createNormalTreasure();
					pair<int, int> nextPos = radiusOneRand(curPos);
					t->setPosn(nextPos.first, nextPos.second);
					golds.emplace_back(t);
					td->showOnMap(nextPos.first, nextPos.second, t->getSymbol());
				}
				else if (enemies[i]->getSymbol() != 'D') {
					int goldNum = rand() % 2 + 1;
					PC->addGold(goldNum);	
					td->showOnMap(target.first, target.second, '.');
				}
				else {
					td->showOnMap(target.first, target.second, '.');
				}
				delete enemies[i];
				enemies[i] = nullptr;
				enemies.erase(enemies.begin() + i);
				td->setMessage(td->getMessage() + " And slained it!");
			}
			if (PC->getHP() == 0) {
				td = new TextDisplay(6);
				over = true;
				td->setMessage(td->getMessage() + "\nPC was killed...");
			}
			return;
		}
	}
}

void CC3K::usePotion(string dir) {
	pair<int, int> curPos = PC->getPosn();
	pair<int, int> target = getDest(curPos, dir);
	for (unsigned int i = 0; i < potions.size(); ++i) {
		if (potions[i]->getPosn().first == target.first &&
			potions[i]->getPosn().second == target.second) {
			potions[i]->usePotion(PC);
			td->setMessage("PC uses " + potions[i]->getType() + ".");
			delete potions[i];
			td->showOnMap(target.first, target.second, '.');
			potions.erase(potions.begin() + i);
			if (PC->getHP() == 0) {
				td = new TextDisplay(6);
				over = true;
				td->setMessage(td->getMessage() + "\nPC was killed...");
			}
			break;
		}
	}
}

void CC3K::enemyAction() {
	for (unsigned int i = 0; i < enemies.size(); ++i) {
		if (inRange(enemies[i]) && enemies[i]->getSymbol() != 'D') {
			int damage = PC->attackedBy(enemies[i]);
			if (damage > 0) {
				string sym(1, enemies[i]->getSymbol());
				td->setMessage(td->getMessage() + " " + sym +
							   " deals " + to_string(damage) + " damage to PC.");
			}
			else if (damage == -1) {
				string sym(1, enemies[i]->getSymbol());
			}
			if (PC->getHP() == 0) {
				td = new TextDisplay(6);
				over = true;
				td->setMessage(td->getMessage() + "\nPC was killed...");
				return;
			}
		}
		else if (dynamic) {
			if (enemies[i]->getSymbol() != 'D') moveEnemy(enemies[i]);
		}
	}
	for (unsigned int i = 0; i < golds.size(); ++i) {
		if (golds[i]->getValue() == 6) {
			DragonHoard *dh = static_cast<DragonHoard*>(golds[i]);
			if (!dh->unlocked()) {
				if (inRange(dh->theDragon()) || inRange(golds[i])) {
					int damage = PC->attackedBy(dh->theDragon());
						if (damage > 0) {
					  td->setMessage(td->getMessage() + " D deals " +
							 to_string(damage) + " damage to PC.");
					 	}
				}
			}
			if (PC->getHP() == 0) {
				td = new TextDisplay(6);
				over = true;
				td->setMessage(td->getMessage() + "\nPC was killed...");
				return;
			}
		}
	}
}

void CC3K::match(vector<DragonHoard *> dhs, vector<Enemy *> ds) {
	for (unsigned int i = 0; i < dhs.size(); ++i) {
		for (unsigned int j = 0; j < ds.size(); ++j) {
			int diffX = dhs[i]->getPosn().first - ds[j]->getPosn().first;
			int diffY = dhs[i]->getPosn().second - ds[j]->getPosn().second;
			if (diffX >= -1 && diffX <= 1 && diffY >= -1 && diffY <= 1) {
				Dragon *d = static_cast<Dragon*>(ds[j]);
				d->setHoard(dhs[i]);
				dhs[i]->setDragon(d);
			}
		}
	}
}

void CC3K::useBackup() {
	vector<DragonHoard *> dragonhoards;
	vector<Enemy *> dragons;
	PC->setPosn(PCBackup.first, PCBackup.second);
	td->showOnMap(PCBackup.first, PCBackup.second, '@');
	td->setMessage("Player character has spawned.");
	td->setStair(stair.first, stair.second);
	for (unsigned int i = 0; i < potionsBackup.size(); ++i) {
		Potion * p = factory->createPotion(potionsBackup[i]->getSymbol()); 
		p->setPosn(potionsBackup[i]->getPosn().first,
				   potionsBackup[i]->getPosn().second);
		potions.emplace_back(p); 
		td->showOnMap(p->getPosn().first,
					  p->getPosn().second,
					  p->getSymbol());
	}
	for (unsigned int i = 0; i < goldsBackup.size(); ++i) {
		Treasure * t = factory->createTreasure(goldsBackup[i]->getValue());
		t->setPosn(goldsBackup[i]->getPosn().first,
				   goldsBackup[i]->getPosn().second);
		golds.emplace_back(t); 
		if (t->getValue() == 6) {
			DragonHoard *dh = static_cast<DragonHoard*>(t);
			dragonhoards.emplace_back(dh);
		}
		td->showOnMap(t->getPosn().first,
					  t->getPosn().second,
					  t->getSymbol());
	}
	for (unsigned int i = 0; i < enemiesBackup.size(); ++i) {
		Enemy * e = factory->createEnemy(enemiesBackup[i]->getSymbol());
		e->setPosn(enemiesBackup[i]->getPosn().first,
				   enemiesBackup[i]->getPosn().second);
		enemies.emplace_back(e); 
		if (enemiesBackup[i]->getSymbol() == 'D') {
			dragons.emplace_back(e);
		}
		td->showOnMap(e->getPosn().first,
					  e->getPosn().second,
					  e->getSymbol());
	}
	match(dragonhoards, dragons);
}

void CC3K::readLevel(string race) {
	string line;
	vector<DragonHoard *> dragonhoards;
	vector<Enemy *> dragons;
	if (ifs.peek() != EOF) {
		clearBackups();
		int playerCount;
		for (int row = 0; row < 25; ++row) {
			getline(ifs, line);
			for (int col = 0; col < 79; ++col) {	
				if (line[col] == '@') {
				        ++playerCount;
					if (level == 1) {
						if      (race == "j") {
							race = "Jeff";
							PC = new Jeff;
						}							
						else if (race == "d") {
							race = "Drow";
							PC = new Drow;
						}
						else if (race == "v") {
							race = "Vampire";
							PC = new Vampire;
						}
						else if (race == "t") {
							race = "Troll";
							PC = new Troll;
						}
						else if (race == "g") {
							race = "Goblin";
							PC = new Goblin;
						}
						else {
							race = "Shade";
							PC = new Shade;
						}
						td->setRace(race);
						td->setPC(PC);
						basePC.first = PC->getAttack();
						basePC.second = PC->getDefense();
					}
					PC->setPosn(row, col);
					PCBackup.first = row;
					PCBackup.second = col;
					td->showOnMap(row, col, '@');
					td->setMessage("Player character has spawned.");
				}
				else if (line[col] == '\\') {					
					td->setStair(row, col);
					stair.first = row;
					stair.second = col;
					stairBackup.first = row;
					stairBackup.second = col;
				}
				else if (line[col] >= '0' && line[col] <= '5') {					
					Potion * p = factory->createPotion(line[col]);
					Potion * p1 = factory->createPotion(line[col]);
					p->setPosn(row, col);
					p1->setPosn(row, col);
					td->showOnMap(row, col, p->getSymbol());
					potions.emplace_back(p);
					potionsBackup.emplace_back(p1);
				}
				else if (line[col] >= '6' && line[col] <= '9') {					
					Treasure * t = factory->createTreasure(line[col]);
					Treasure * t1 = factory->createTreasure(line[col]);
					t->setPosn(row, col);
					t1->setPosn(row, col);
					td->showOnMap(row, col, t->getSymbol());
					golds.emplace_back(t);
					goldsBackup.emplace_back(t1);
					if (t->getValue() == 6) {
						DragonHoard *dh = static_cast<DragonHoard*>(t);
						dragonhoards.emplace_back(dh);
					}
				}
				else if (line[col] >= 'A' && line[col] <= 'Z') {					
					Enemy * e = factory->createEnemy(line[col]);
					Enemy * e1 = factory->createEnemy(line[col]);
					e->setPosn(row, col);
					e1->setPosn(row, col);
					td->showOnMap(row, col, e->getSymbol());
					enemies.emplace_back(e);
					enemiesBackup.emplace_back(e1);
					if (e->getSymbol() == 'D') dragons.emplace_back(e);
				}
				match(dragonhoards, dragons);
			}
		}
		if (playerCount != 1) over = true;
	}
	else useBackup();
}

bool CC3K::gameOver() { return over; }

void CC3K::levelUp(string race) {
	if (level == 5) {
		over = true; 
		int score = PC->getGold();
		if (PC->getSymbol() == 'S') score = 3 * score / 2;
		td = new TextDisplay(7);
		td->setMessage(td->getMessage() +
		"\nCongratulations!!! You win.\nYour score: " + to_string(score));
		return;
	}
	++level;
	delete Map;
	delete td;
	if (level == 1) clearUsage();
	if (random) {
		int n;
		bool flag = false;
		srand(time(0));
		while (true) {
			n = rand() % 5 + 1;
			for (unsigned int i = 0; i < floorType.size(); ++i) {
				if (floorType[i] == n) {
					if (n == 1) {Map = new Floor1;}
					else if (n == 2) {Map = new Floor2;}
					else if (n == 3) {Map = new Floor3;}
					else if (n == 4) {Map = new Floor4;}
					else {Map = new Floor5;}
				floorType.erase(floorType.begin() + i);
				flag = true;
				} else {}
			}
			if (flag){break;}
		}
		td = new TextDisplay(n);
		clearObjects();
		if (level > 1) spawnPC();
		else initPC(race);
		initStair();
		generateObjects(20);
	}
	else {
		Map = new Floor1;
		td = new TextDisplay(1);
		clearObjects();
		if (readMode) {
			readLevel(race);
			if (over == true) return;
		}
		else {
			if (level > 1) spawnPC();
			else initPC(race);
			initStair();
			generateObjects(20);
		}
	}
	if (level > 1) resetAtkDef();
	td->setLevel(level); 
}

ostream &operator<<(ostream &out, const CC3K &g) {
  return out << *(g.td);
}

