#include "Fighter.h"
#include "FighterInterface.h"
#include <string>
#include <sstream>

using namespace std;


Fighter::Fighter(string name, int max_hp, int strength, int speed, int magic)
{
    this->name = name;
    this->max_hp = max_hp;
    this->strength = strength;
    this->speed = speed;
    this->magic = magic;
    this->current_hp = max_hp;
}

string Fighter::getName()
{
    return name;
}

int Fighter::getMaximumHP()
{
    return max_hp;
}

int Fighter::getCurrentHP()
{
    return current_hp;
}

int Fighter::getStrength()
{
    return strength;
}

int Fighter::getSpeed()
{
    return speed;
}

int Fighter::getMagic()
{
    return magic;
}

void Fighter::takeDamage(int damage)
{
    int total_damage_taken = damage - (speed / 4);
    
    if (total_damage_taken < 1)
    {
        total_damage_taken = 1;
    }
    
    current_hp -= total_damage_taken;
}

void Fighter::reset()
{
    current_hp = max_hp;
}

void Fighter::regenerate()
{
    int bonus_hp = (strength / 6);
    if (bonus_hp < 1)
    {
        bonus_hp = 1;
    }
    current_hp += bonus_hp;
    if (current_hp > max_hp)
    {
        current_hp = max_hp;
    }
}

bool Fighter::useAbility()
{
    bool used = false;
    return used;
}

void Fighter::setCurrentHP(int hp)
{
    current_hp = hp;
}
void Fighter::setSpeed(int speed)
{
	this->speed = speed;
}
void Fighter::increaseSpeed()
{
	speed++;
}

