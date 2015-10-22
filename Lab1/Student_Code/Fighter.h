#pragma once
#include "FighterInterface.h"
#include <string>

using namespace std;

class Fighter : public FighterInterface
{
    
public:
    
    Fighter(string name, int max_hp, int strength, int speed, int magic);
    
    virtual string getName();
    virtual int getMaximumHP();
    virtual int getCurrentHP();
    virtual int getStrength();
    virtual int getSpeed();
    virtual int getMagic();
    virtual int getDamage() = 0;
    void setCurrentHP(int hp);
    void setSpeed(int speed);
    void increaseSpeed();
    
    virtual void takeDamage(int damage);
    virtual void reset();
    virtual void regenerate();
    virtual bool useAbility();
    
private:
    
    string name;
    int max_hp;
    int current_hp;
    int strength;
    int speed;
    int magic;
};
