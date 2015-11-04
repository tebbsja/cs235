//
//  Player.cpp
//  Midterm
//
//  Created by Austin Tebbs on 10/26/15.
//  Copyright © 2015 Austin Tebbs. All rights reserved.
//

#include "Player.h"
#include <sstream>

Player::Player(string name, int strength, int speed)
{
    this->name = name;
    this->strength = strength;
    this->speed = speed;
}

string Player::getName()
{
    return name;
}

int Player::getStrength()
{
    return strength;
}

int Player::getSpeed()
{
    return speed;
}

string Player::toString()
{
    stringstream ss;
    ss << "Name: " << getName() << "\nStrength: " << getStrength() << "\nSpeed: " << getSpeed() << endl;

    return ss.str();
}