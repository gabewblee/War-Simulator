#ifndef UNIT
#define UNIT

#include "Entity.h"
#include <algorithm>
#include <iostream>

class Unit : public Entity {
public:
    int HP;
    int range;
    int damagePoints;
    int movementCost;

    Unit(int ID, int team, int x, int y, int HP, int range, int damagePoints, int movementCost) : Entity(ID, team, position) {
        this->HP = HP;
        this->range = range;
        this->damagePoints = damagePoints;
        this->movementCost = movementCost;
    }

    int distance(Unit * target) {
        int horDiff = std::abs(this->x - target->x);
        int verDiff = std::abs(this->y - target->y);
        return horDiff + verDiff;
    }

    bool inRange(Unit * target) {
        if (distance(target) <= this->range) {
            return true;
        }
        return false;
    }

    int attack(Unit * target) {
        int damage = std::min(this->damagePoints, target->HP);
        if (inRange(target)) {
            target->HP -= damage;
        }
        return damage;
    }

    std::string getType() {
        return "Unit";
    }
};

#endif