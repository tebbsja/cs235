#include "Archer.h"
#include <iostream>

using namespace std;

Archer::Archer(string name, int max_hp, int strength, int speed, int magic)
       :Fighter(name, max_hp, strength, speed, magic)
{
    this->original_speed = speed;
}

int Archer::getDamage()
{
    return getSpeed();
}

void Archer::reset()
{
    Fighter::reset();
    Fighter::setSpeed(original_speed);
}

bool Archer::useAbility()
{
    bool used_ability = true;
    Fighter::increaseSpeed();
    
    return used_ability;
}
