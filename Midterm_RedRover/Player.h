//
//  Player.h
//  Midterm
//
//  Created by Austin Tebbs on 10/26/15.
//  Copyright © 2015 Austin Tebbs. All rights reserved.
//

#ifndef Player_h
#define Player_h

#include "PlayerInterface.h"

class Player : public PlayerInterface
{
    
public:
    
    Player(){};
    Player(string name, int strength, int speed);
    
   	/*
     * getName()
     *
     * returns the name of the player
     */
    virtual string getName();
    
    /*
     *getStrength()
     *
     *returns the strength of the player
     */
    virtual int getStrength();
    
    /*
     *getSpeed()
     *
     *returns the speed of the player
     */
    virtual int getSpeed();
    
    string toString();
    
private:
    string name;
    int strength;
    int speed;
};


#endif /* Player_h */
