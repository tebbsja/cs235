//Austin Tebbs
#pragma once
#include "Player.h"


template<class T>
class Node {

public:

    Node* next;
    Node* prev;
    string name;
    int strength;
    int speed;
    PlayerInterface* player;
    
    /*Node(Player* player, Node* next_ptr, Node* prev_ptr)
    {
        next = next_ptr;
        prev = prev_ptr;
        name = player->getName();
        strength = player->getStrength();
        speed = player->getSpeed();
    }
     */
            
            Node(PlayerInterface* player_ptr, Node* next_ptr = NULL, Node* prev_ptr = NULL) :
            player(player_ptr), name(player_ptr->getName()), strength(player_ptr->getStrength()),
            speed(player_ptr->getSpeed()), next(next_ptr), prev(prev_ptr){}
};
