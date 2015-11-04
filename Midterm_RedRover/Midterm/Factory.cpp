#include "Factory.h"
#include "RedRover.h"
//You may add #include statments here
// Austin Tebbs
using namespace std;

/*
Unlike all other documents provided, you may modify this document slightly (but do not change its name)
*/
//=======================================================================================
/*
createRedRover()

Creates and returns an object whose class extends RedRoverInterface.
This should be an object of a class you have created.

Example: If you made a class called "RedRover", you might say, "return new RedRover();".
*/
RedRoverInterface* Factory::createRedRover()
{
	return new RedRover();//Modify this line

}
//================================
