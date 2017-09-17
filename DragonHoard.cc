#include "DragonHoard.h"
#include "Enemy.h"
DragonHoard::DragonHoard() :Treasure{6}, dragon{nullptr}, dragonDead{false} {}

DragonHoard::~DragonHoard() {}

void DragonHoard::setDragon(Enemy *d) { dragon = d; }

void DragonHoard::unlock() { dragonDead = true; }

bool DragonHoard::unlocked() { return dragonDead; }

Enemy * DragonHoard::theDragon() const { return dragon; }
