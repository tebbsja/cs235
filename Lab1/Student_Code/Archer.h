#pragma once
#include <string>
#include <iostream>
#include "Fighter.h"

using namespace std;

class Archer : public Fighter
{
public:
    Archer(string name, int max_hp, int strength, int speed, int magic);
    
    virtual int getDamage();
    virtual void reset();
    virtual bool useAbility();
    
    
private:
    int original_speed;
};
