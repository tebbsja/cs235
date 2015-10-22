#include "Cleric.h"

Cleric::Cleric(string name, int max_hp, int strength, int speed, int magic)
:Fighter(name, max_hp, strength, speed, magic)
{
    this->max_mana = (magic*5);
    this->current_mana = max_mana;

}

int Cleric::getDamage()
{
    return getMagic();
}

void Cleric::reset()
{
    Fighter::reset();
    current_mana = max_mana;
}

void Cleric::regenerate()
{
    Fighter::regenerate();
    
    int bonus_mana = (getMagic()/5);
    if (bonus_mana < 1)
    {
        bonus_mana = 1;
    }
    
    current_mana += bonus_mana;
    if ( current_mana > max_mana)
    {
        current_mana = max_mana;
    }
}

bool Cleric::useAbility()
{
    bool used_ability = false;
    
    if (current_mana >= CLERIC_ABILITY_COST)
    {
        int hp = (getCurrentHP() + (getMagic()/3));
        if (hp < 1)
        {
            hp = 1;
        }
        if (getCurrentHP() == getMaximumHP())
        {
            hp = getMaximumHP();
        }
        Fighter::setCurrentHP(hp);
        
        current_mana -= CLERIC_ABILITY_COST;
        
        used_ability = true;
    }
    
    
    return used_ability;
}
