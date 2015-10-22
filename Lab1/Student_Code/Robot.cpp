#include "Robot.h"
#include <math.h>

Robot::Robot(string name, int max_hp, int strength, int speed, int magic)
:Fighter(name, max_hp, strength, speed, magic)
{
    this->max_energy = (magic*2);
    this->current_energy = (magic*2);
    this->bonus_damage = 0;
}

int Robot::getDamage()
{
    int damage = getStrength() + bonus_damage;
    bonus_damage = 0;
    
    return damage;
}

int Robot::getCurrentEnergy()
{
    return current_energy;
}

int Robot::getMaxEnergy()
{
    return max_energy;
}

int Robot::getBonusDamage()
{
    return bonus_damage;
}

void Robot::reset()
{
    Fighter::reset();
    current_energy = max_energy;
    bonus_damage = 0;
}

bool Robot::useAbility()
{
    bool used_ability = false;
    if (current_energy >= ROBOT_ABILITY_COST)
    {
        bonus_damage = (getStrength() * ( pow((current_energy/(max_energy * 1.0)), 4.0 )));
        current_energy -= ROBOT_ABILITY_COST;
        used_ability = true;
    }
    return used_ability;
}
