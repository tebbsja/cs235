#pragma once
#include "Fighter.h"

using namespace std;

class Robot : public Fighter
{
public:
    Robot(string name, int max_hp, int strength, int speed, int magic);
    
    virtual int getDamage();
    virtual void reset();
    virtual bool useAbility();
    int getCurrentEnergy();
    int getMaxEnergy();
    int getBonusDamage();
    
private:
    int current_energy;
    int max_energy;
    int bonus_damage;
};
