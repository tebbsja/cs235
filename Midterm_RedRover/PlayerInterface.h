#pragma once
#include <string>
using namespace std;

class PlayerInterface {
public:
	PlayerInterface(void) {}
	virtual ~PlayerInterface(void) {}


	/*
	* getName()
	*
	* returns the name of the player
	*/
	virtual string getName() = 0;

	/*
	*getStrength()
	*
	*returns the strength of the player
	*/
	virtual int getStrength() = 0;

	/*
	*getSpeed()
	*
	*returns the speed of the player
	*/
	virtual int getSpeed() = 0;
};