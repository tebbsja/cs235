//
//  Station.cpp
//  Lab4
//
//  Created by Austin Tebbs on 10/17/15.
//  Copyright © 2015 Austin Tebbs. All rights reserved.
//

#include "Station.h"

Station::Station()
{
    current_car = -1;
}

//Part 1--------------------------------------------------------------
/**
 * Let another car arrive at the station and become the current car.
 * Do not allow a new car to arrive if any of the following conditions apply:
 * 1.	There is already a current car
 * 2.	The new car's ID already exists in any structure
 * 3.	The new car's ID is negative
 *
 * @param car the ID of the car arriving at the station
 * @return true if the car successfully arrived; false otherwise
 */

bool Station::addToStation(int car)
{

	cout << "Car Input: " << car << endl;
    if (current_car != -1 && car > 0)
    {
        cout << "ALREADY CURRENT CAR\n\n";
        return false;
    }
    else if (current_car == -1 && car > 0)// 0 included?
    {
	if (car <= 0)
	{
	    cout << "DOES NOT ACCEPT NEGATIVE OR 0 VALUES\n\n";
	    return false;
	}
        else if (car_stack.exists(car) || car_queue.exists(car) || car_deque.exists(car) ||car_irdeque.exists(car) 			 || car_ordeque.exists(car))
        {
            cout <<"THAT CAR ALREADY EXISTS\n\n";
            return false;
        }
        current_car = car;
        cout << "CURRENT CAR: " << current_car << endl << endl;
    }
    else if (car < 0)
    {
        cout << "FALSE - less than -1\n\n";
        return false;
    }
    else
    {
	cout << "CAR INPUT: " << car << endl << endl;
    }

    
    return true;
}

/**
 * Returns the ID of the current car.
 * Return -1 if there is no current car.
 *
 * @return the ID of the current car; -1 if there is no current car
 */
int Station::showCurrentCar()
{
    cout << "Current Car is " << current_car << endl << endl;
    return current_car;
}

/**
 * Removes the current car from the station.
 * Does nothing if there is no current car.
 *
 * @return true if the current car successfully left; false otherwise
 */
bool Station::removeFromStation()
{
    if (current_car != -1)
    {
        current_car = -1;
        return true;
    }
    return false;
}

//Part 2--------------------------------------------------------------
/**
 * Adds the current car to the stack.  After this operation, there should be no current car.
 * Does nothing if there is no current car or if the stack is already full.
 *
 * @return true if the car is successfully added to the stack; false otherwise
 */
bool Station::addToStack()
{
    if (current_car == -1)
    {
        cout << "NO CURRENT CAR\n\n";
        return false;
    }
    else if (car_stack.size() == 5)
    {
        cout << "STACK IS FULL\n\n";
        return false;
    }
    else
    {
        cout << "ADDING CURRENT CAR: " << current_car << " TO STACK\n\n";
        car_stack.push(current_car);
        current_car = -1;
        return true;
    }
}

/**
 * Removes the first car in the stack and makes it the current car.
 * Does nothing if there is already a current car or if the stack already empty.
 *
 * @return true if the car is successfully removed from the stack; false otherwise
 */
bool Station::removeFromStack()
{
	cout << "CURRENT CAR: " << current_car << "\nTOP OF STACK: " << car_stack.top() << endl;
    if (current_car != -1)
    {
        cout << "ALREADY A CURRENT CAR\n\n";
        return false;
    }
    else if (car_stack.empty())
    {
	cout << "STACK IS EMPTY\n\n";
	return false;
    }
    else
    {
        current_car = car_stack.top();
	cout << "CURRENT CAR NOW: " << current_car << endl;
        car_stack.pop();
	cout << "AFTER POP, TOP OF STACK NOW: " << car_stack.top() << endl;
	return true;
    }
        return false;
}

/**
 * Returns the ID of the first car in the stack.
 *
 * @return the ID of the first car in the stack; -1 if the stack is empty
 */
int Station::showTopOfStack()
{
    if (car_stack.empty())
    {
	cout << "STACK IS EMPTY\n\n";
        return -1;
    }
    return car_stack.top();
}

/**
 * Returns the number of cars in the stack.
 *
 * @return the number of cars in the stack
 */
int Station::showSizeOfStack()
{
    return car_stack.size();
}

//Part 3--------------------------------------------------------------
/**
 * Adds the current car to the queue.  After this operation, there should be no current car.
 * Does nothing if there is no current car or if the queue is already full.
 *
 * @return true if the car is successfully added to the queue; false otherwise
 */
bool Station::addToQueue()
{
    if (current_car == -1)
    {
        cout << "NO CURRENT CAR\n\n";
        return false;
    }
    else if (car_queue.size() == 5)
    {
        cout << "QUEUE IS FULL\n\n";
        return false;
    }
    else
    {
        cout << "ADDED CAR " << current_car << " TO QUEUE\n\n";
        car_queue.push(current_car);
        current_car = -1;
        return true;
    }
}

/**
 * Removes the first car in the queue and makes it the current car.
 * Does nothing if there is already a current car or if the queue already empty.
 *
 * @return true if the car is successfully removed from the queue; false otherwise
 */
bool Station::removeFromQueue()
{
    if (current_car != -1)
    {
        cout << "CAR ALREADY IN STATION\n\n";
        return false;
    }
    else if (car_queue.empty())
    {
        cout << "QUEUE IS EMPTY\n\n";
        return false;
    }
    else
    {
        current_car = car_queue.top();
        car_queue.pop();
        return true;
    }
}

/**
 * Returns the ID of the first car in the queue.
 *
 * @return the ID of the first car in the queue; -1 if the queue is empty
 */
int Station::showTopOfQueue()
{
    if (car_queue.empty())
    {
	cout << "QUEUE IS EMPTY\n\n";
        return -1;
    }
    else
    {
        return car_queue.top();
    }
}

/**
 * Returns the number of cars in the queue.
 *
 * @return the number of cars in the queue
 */

int Station::showSizeOfQueue()
{
    return car_queue.size();
}

//Part 4--------------------------------------------------------------
/**
 * Adds the current car to the deque on the left side.  After this operation, there should be no current car.
 * Does nothing if there is no current car or if the deque is already full.
 *
 * @return true if the car is successfully added to the deque; false otherwise
 */
bool Station::addToDequeLeft()
{
    if (current_car == -1)
    {
        cout << "NO CAR IN STATION\n\n";
        return false;
    }
    else if (car_deque.size() == 5)
    {
        cout << "DEQUE IS FULL\n\n";
        return false;
    }
    else
    {
        car_deque.pushLeft(current_car);
        current_car = -1;
        return true;
    }
    return true;
}

/**
 * Adds the current car to the deque on the right side.  After this operation, there should be no current car.
 * Does nothing if there is no current car or if the deque is already full.
 *
 * @return true if the car is successfully added to the deque; false otherwise
 */
bool Station::addToDequeRight()
{
    if (current_car == -1)
    {
        cout << "NO CAR IN STATION\n\n";
        return false;
    }
    else if (car_deque.size() == 5)
    {
        cout << "DEQUE IS FULL\n\n";
        return false;
    }
    else
    {
        car_deque.pushRight(current_car);
        current_car = -1;
        return true;
    }
    return true;
}

/**
 * Removes the leftmost car in the deque and makes it the current car.
 * Does nothing if there is already a current car or if the deque already empty.
 *
 * @return true if the car is successfully removed from the deque; false otherwise
 */
bool Station::removeFromDequeLeft()
{
    if (current_car != -1)
    {
        cout << "CAR ALREADY IN STATION\n\n";
        return false;
    }
    else if (car_deque.empty())
    {
        cout << "DEQUE IS EMPTY\n\n";
        return false;
    }
    else
    {
        current_car = car_deque.left();
        car_deque.popLeft();
        return true;
    }
    return true;
}

/**
 * Removes the rightmost car in the deque and makes it the current car.
 * Does nothing if there is already a current car or if the deque already empty.
 *
 * @return true if the car is successfully removed from the deque; false otherwise
 */
bool Station::removeFromDequeRight()
{
    if (current_car != -1)
    {
        cout << "CAR ALREADY IN STATION\n\n";
        return false;
    }
    else if (car_deque.empty())
    {
        cout << "DEQUE IS EMPTY\n\n";
        return false;
    }
    else
    {
        current_car = car_deque.right();
        car_deque.popRight();
    }
    return true;
}

/**
 * Returns the ID of the leftmost car in the deque.
 *
 * @return the ID of the leftmost car in the deque; -1 if the deque is empty
 */
int Station::showTopOfDequeLeft()
{
    if (car_deque.empty())
    {
	cout << "DEQUE IS EMPTY\n\n";
	return -1;
    }
    return car_deque.left();
}

/**
 * Returns the ID of the rightmost car in the deque.
 *
 * @return the ID of the rightmost car in the deque; -1 if the deque is empty
 */
int Station::showTopOfDequeRight()
{
    if (car_deque.empty())
    {
	cout << "DEQUE IS EMPTY\n\n";
	return -1;
    }
    return car_deque.right();
}

/**
 * Returns the number of cars in the deque.
 *
 * @return the number of cars in the deque
 */
int Station::showSizeOfDeque()
{
    return car_deque.size();
}

//Input-Restricted Deque----------------------------------------------
/**
 * Adds the current car to the IRDeque on the left side.  After this operation, there should be no current car.
 * Does nothing if there is no current car or if the IRDeque is already full.
 *
 * @return true if the car is successfully added to the IRDeque; false otherwise
 */

bool Station::addToIRDequeLeft()
{
    if (current_car == -1)
    {
        cout << "NO CAR IN STATION\n\n";
        return false;
    }
    else if (car_irdeque.size() == 5)
    {
        cout << "IRDEQUE IS FULL\n\n";
        return false;
    }
    else
    {
        car_irdeque.pushLeft(current_car);
        current_car = -1;
        return true;
    }
    return true;
}

/**
 * Removes the leftmost car in the IRDeque and makes it the current car.
 * Does nothing if there is already a current car or if the IRDeque already empty.
 *
 * @return true if the car is successfully removed from the IRDeque; false otherwise
 */
bool Station::removeFromIRDequeLeft()
{
    if (current_car != -1)
    {
        cout << "CAR ALREADY IN STATION\n\n";
        return false;
    }
    else if (car_irdeque.empty())
    {
        cout << "IRDEQUE IS EMPTY\n\n";
        return false;
    }
    else
    {
        current_car = car_irdeque.left();
        car_irdeque.popLeft();
        return true;
    }
    return true;
}

/**
 * Removes the rightmost car in the IRDeque and makes it the current car.
 * Does nothing if there is already a current car or if the IRDeque already empty.
 *
 * @return true if the car is successfully removed from the IRDeque; false otherwise
 */
bool Station::removeFromIRDequeRight()
{
    if (current_car != -1)
    {
        cout << "CAR ALREADY IN STATION\n\n";
        return false;
    }
    else if (car_irdeque.empty())
    {
        cout << "IRDEQUE IS EMPTY\n\n";
        return false;
    }
    else
    {
        current_car = car_irdeque.right();
        car_irdeque.popRight();
        return true;
    }
    return true;
}

/**
 * Returns the ID of the leftmost car in the IRDeque.
 *
 * @return the ID of the leftmost car in the IRDeque; -1 if the IRDeque is empty
 */
int Station::showTopOfIRDequeLeft()
{
    if (car_irdeque.empty())
    {
        return -1;
    }
    return car_irdeque.left();
}

/**
 * Returns the ID of the rightmost car in the IRDeque.
 *
 * @return the ID of the rightmost car in the IRDeque; -1 if the IRDeque is empty
 */
int Station::showTopOfIRDequeRight()
{
    if (car_irdeque.empty())
    {
        return -1;
    }
    return car_irdeque.right();
}

/**
 * Returns the number of cars in the IRDeque.
 *
 * @return the number of cars in the IRDeque
 */
int Station::showSizeOfIRDeque()
{
    return car_irdeque.size();
}




//Output-Restricted Deque---------------------------------------------
/**
 * Adds the current car to the ORDeque on the left side.  After this operation, there should be no current car.
 * Does nothing if there is no current car or if the ORDeque is already full.
 *
 * @return true if the car is successfully added to the ORDeque; false otherwise
 */
bool Station::addToORDequeLeft()
{
    if (current_car == -1)
    {
        cout << "NO CAR IN STATION\n\n";
        return false;
    }
    else if (car_ordeque.size() == 5)
    {
        cout << "ORDEQUE IS FULL\n\n";
        return false;
    }
    else
    {
        car_ordeque.pushLeft(current_car);
        current_car = -1;
        return true;
    }
    return true;
}

/**
 * Adds the current car to the ORDeque on the right side.  After this operation, there should be no current car.
 * Does nothing if there is no current car or if the ORDeque is already full.
 *
 * @return true if the car is successfully added to the ORDeque; false otherwise
 */
bool Station::addToORDequeRight()
{
    if (current_car == -1)
    {
        cout << "NO CAR IN STATION\n\n";
        return false;
    }
    else if (car_ordeque.size() == 5)
    {
        cout << "ORDEQUE IS FULL\n\n";
        return false;
    }
    else
    {
        car_ordeque.pushRight(current_car);
        current_car = -1;
        return true;
    }
    return true;
}

/**
 * Removes the leftmost car in the ORDeque and makes it the current car.
 * Does nothing if there is already a current car or if the ORDeque already empty.
 *
 * @return true if the car is successfully removed from the ORDeque; false otherwise
 */
bool Station::removeFromORDequeLeft()
{
    if (current_car != -1)
    {
        cout << "CAR ALREADY IN STATION\n\n";
        return false;
    }
    else if (car_ordeque.empty())
    {
        cout << "ORDEQUE IS EMPTY\n\n";
        return false;
    }
    else
    {
        current_car = car_ordeque.left();
        car_ordeque.popLeft();
        return true;
    }
    return true;
}

/**
 * Returns the ID of the leftmost car in the ORDeque.
 *
 * @return the ID of the leftmost car in the ORDeque; -1 if the ORDeque is empty
 */
int Station::showTopOfORDequeLeft()
{
    if (car_ordeque.empty())
    {
        return -1;
    }
    return car_ordeque.left();
}

/**
 * Returns the number of cars in the ORDeque.
 *
 * @return the number of cars in the ORDeque
 */
int Station::showSizeOfORDeque()
{
    return car_ordeque.size();
}
