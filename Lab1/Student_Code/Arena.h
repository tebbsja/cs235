#pragma once
#include "ArenaInterface.h"
#include "Fighter.h"
#include "Archer.h"
#include "Robot.h"
#include "Cleric.h"
#include <string>

using namespace std;


class Arena : public ArenaInterface
{
public:
    
    Arena();
    
    virtual bool addFighter(string info);
    
    virtual bool removeFighter(string name);
    
    virtual FighterInterface* getFighter(string name);
    
    virtual int getSize();
    
    void printNames();
    
private:
    
    vector<FighterInterface*> fighters;
    
};

