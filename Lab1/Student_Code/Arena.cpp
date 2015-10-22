#include "Arena.h"
#include <string>
#include <sstream>
#include <vector>

Arena::Arena(){}

int Arena::getSize()
{
    int size = fighters.size();
    
    return size;
}

bool Arena::addFighter(string info)
{
    stringstream ss(info);
    bool added = false;
    bool correct_format = true;
    string name, type;
    int max_hp, strength, speed, magic;
    
    //parse info
    ss >> name >> type >> max_hp >> strength >> speed >> magic;
    
    //if there is more in info
    if (!ss.eof())
    {
      
        correct_format = false;
    }
    //if ints were give in place of strings vice versa
    if (ss.fail())
    {
       
        correct_format = false;
        
    }
    //if type isn't A, C, or R
    if (type != "A" && type != "C" && type != "R")
    {
        correct_format = false;
       
    }
    //if stats are less than or equal to 0
    if (max_hp <= 0 || strength <= 0 || speed <= 0 || magic <= 0)
    {
        correct_format = false;
    
    }
    //if fighter already exists
    for (int i=0; i < fighters.size(); i++)
    {
        if (name == fighters[i]->getName())
        {
            correct_format = false;
        }
    }
    
    if (correct_format == true)
    {
        if (type == "A")
        {
            Archer* fighter_ptr = new Archer(name, max_hp, strength, speed, magic);
            fighters.push_back(fighter_ptr);
        }
        else if (type =="C")
        {
            Cleric* fighter_ptr = new Cleric(name, max_hp, strength, speed, magic);
            fighters.push_back(fighter_ptr);
        }
        else if (type =="R")
        {
            Robot* fighter_ptr = new Robot(name, max_hp, strength, speed, magic);
            fighters.push_back(fighter_ptr);
        }
        
        added = true;
    }
    
    return added;
}

bool Arena::removeFighter(string name)
{
    bool removed = true;
    
    int index= -1, last_pos=0;
    
    for (int i=0; i<fighters.size() ;i++)
    {
        if (name == fighters[i]->getName())
        {
            index = i;
        }
    }
    if (index == -1)
    {
        removed = false;
    }
    else
    {
        last_pos = fighters.size() - 1;
        fighters[index] = fighters[last_pos];
        fighters.pop_back();
    }
    
    
    return removed;
}

FighterInterface* Arena::getFighter(string name)
{
    FighterInterface* fighter_ptr = NULL;
    
    for (int i=0; i < fighters.size(); i++)
    {
        if (name == fighters[i]->getName())
        {
            fighter_ptr = this->fighters[i];
        }
    }

    return fighter_ptr;
}


void Arena::printNames()
{
    for (int i=0; i<fighters.size();i++)
    {
        cout << fighters[i]->getName() << endl;
    }
    
}
