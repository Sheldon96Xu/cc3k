#include "Player.h"
using namespace std;

Player::Player(int hp, int atk, int def): 
	Character{hp, atk, def}, Gold{0} {}

Player::~Player() {}

int Player::getGold() const { return Gold; }

void Player::addGold(int n) { Gold += n; }
