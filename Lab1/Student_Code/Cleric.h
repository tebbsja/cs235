#pragma once
#include "Fighter.h"

using namespace std;

class Cleric : public Fighter
{
public:
    Cleric(string name, int max_hp, int strength, int speed, int magic);
    
    virtual int getDamage();
    virtual void reset();
    virtual void regenerate();
    virtual bool useAbility();
    
private:
    int max_mana;
    int current_mana;
    
};
