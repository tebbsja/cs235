#pragma once
#include "RedRoverInterface.h"
using namespace std;

/*
WARNING: It is expressly forbidden to modify any part of this document, including its name
*/
//=======================================================================================
/*
createRedRover()

Creates and returns an object whose class extends RedRoverInterface.
This should be an object of a class you have created.

Example: If you made a class called "RedRover", you might say, "return new RedRover();".
*/
class Factory
{
public:
	static RedRoverInterface * createRedRover();
};
//=======================================================================================
