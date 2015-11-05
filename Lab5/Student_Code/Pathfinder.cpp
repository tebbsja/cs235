//
//  Pathfinder.cpp
//  Lab5
//
//  Created by Austin Tebbs on 11/3/15.
//  Copyright © 2015 Austin Tebbs. All rights reserved.
//

#include "Pathfinder.h"
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <ctime>

Pathfinder::Pathfinder()
{
    srand((unsigned int)(time(0)));
    for (int z=0; z < 5; z++)
    {
        for (int y=0; y < 5; y++)
        {
            for (int x=0; x < 5; x++)
            {
                current_maze[x][y][z] = 1;
            }
        }
    }
}

bool Pathfinder::isValid(string maze)
{
    if (maze[0] != '1')
    {
        return false;
    }
    unsigned long last = maze.size() - 2;
    
    if (maze[last] != '1')
    {
        return false;
    }
    for (int i=0; i < maze.size() -1; i++)
    {
        if (maze[i] != '0' && maze[i] != '1' && maze[i] != '\n' && maze[i] != ' ')
        {
            return false;
        }
    }
    return true;
}

//Part 1-----------------------------------------------------------------------------------
/*
 * getMaze
 *
 * Returns a string representation of the current maze. Returns a maze of all 1s if no maze
 * has yet been generated or imported.
 *
 * A valid string representation of a maze consists only of 125 1s and 0s (each separated
 * by spaces) arranged in five 5x5 grids (each separated by newlines). A valid maze must
 * also have 1s in the entrance cell (0, 0, 0) and in the exit cell (4, 4, 4).
 
 // 1 0 0 0 1
 // 0 1 0 1 0
 // 0 1 0 0 1
 // 0 1 1 0 1
 // 1 0 0 1 0  (* 5)
 *
 * Cell (0, 0, 0) is represented by the first number in the string representation of the
 * maze. Increasing in x means moving toward the east, meaning cell (1, 0, 0) is the second
 * number. Increasing in y means moving toward the south, meaning cell (0, 1, 0) is the
 * sixth number. Increasing in z means moving downward to a new grid, meaning cell
 * (0, 0, 1) is the twenty-sixth number. Cell (4, 4, 4) is represented by the last number.
 *
 * Returns:		string
 *				A single string representing the current maze
 */


string Pathfinder::getMaze()
{
    stringstream ss;
    for (int z = 0; z < 5; z++)
    {
        for (int y = 0; y < 5; y++)
        {
            for (int x = 0; x < 5; x++)
            {
                if (x != 4)
                {
                    ss << current_maze[x][y][z] << " ";
                }
                else
                {
                    ss << current_maze[x][y][z];
                }
                
            }
            ss << "\n";
        }
        if (z != 4)
        {
            ss << "\n";
        }
    }
    
    return ss.str();
}

/*
 * createRandomMaze
 *
 * Generates a random maze and stores it as the current maze.
 *
 * The generated maze must contain a roughly equal number of 1s and 0s and must have a 1
 * in the entrance cell (0, 0, 0) and in the exit cell (4, 4, 4).  The generated maze may be
 * solvable or unsolvable, and this method should be able to produce both kinds of mazes.
 */
void Pathfinder::createRandomMaze()
{
    int zcount=0, ocount=0;
    
    
    for (int z=0; z < 5; z++)
    {
        for (int y=0; y < 5; y++)
        {
            for (int x=0; x < 5; x++)
            {
                current_maze[x][y][z] = rand() % 2;
                if (current_maze[x][y][z] == 1)
                {
                    ocount++;
                }
                else
                {
                    zcount++;
                }
            }
        }
    }
    
    current_maze[0][0][0] = 1;
    current_maze[4][4][4] = 1;
    
}
//-----------------------------------------------------------------------------------------

//Part 2-----------------------------------------------------------------------------------
/*
 * importMaze
 *
 * Reads in a maze from a file with the given file name and stores it as the current maze.
 * Does nothing if the file does not exist or if the file's data does not represent a valid
 * maze.
 *
 * The file's contents must be of the format described above to be considered valid.
 *
 * Parameter:	file_name
 *				The name of the file containing a maze
 * Returns:		bool
 *				True if the maze is imported correctly; false otherwise
 */
bool Pathfinder::importMaze(string file_name)
{
    int temp = 0;
    int temp_maze[5][5][5];
    ifstream file;
    file.open(file_name);
    
    if (file.bad() || file.fail()) //if cant find file, or there is an error
    {
        return false; // return false, do nothing
    }
    
    for (int z=0; z < 5; z++)
    {
        for (int y=0; y < 5; y++)
        {
            for (int x=0; x < 5; x++)
            {
                
                if (file >> temp && (temp == 1 || temp == 0)) // as long as file is reading in either 1 or 0
                {							// put in our temporary maze
                    temp_maze[x][y][z] = temp;
                }
                else
                {
                    return false;
                }
                
            }
        }
    }
    
    
    if (file >> temp) // the 3 nested for loops grab 125 digits, if we read any after that, there are too many
    {			// return false
        return false;
    }
    if (temp_maze[0][0][0] != 1) // if opening is blocked
    {				// return false
        return false;
    }
    if (temp_maze[4][4][4] != 1) // if exit is blocked
    {				// return false
        return false;
    }
    
    for (int z=0; z < 5; z++)
    {
        for (int y=0; y < 5; y++)
        {
            for (int x=0; x < 5; x++) // after we have checked to make sure it is valid
            {				// set current maze = temporary maze
                current_maze[x][y][z] = temp_maze[x][y][z];
            }
        }
    }
    
    return true;
}
//-----------------------------------------------------------------------------------------

//Part 3-----------------------------------------------------------------------------------
/*
 * solveMaze
 *
 * Attempts to solve the current maze and returns a solution if one is found.
 *
 * A solution to a maze is a list of coordinates for the path from the entrance to the exit
 * (or an empty vector if no solution is found). This list cannot contain duplicates, and
 * any two consecutive coordinates in the list can only differ by 1 for only one
 * coordinate. The entrance cell (0, 0, 0) and the exit cell (4, 4, 4) should be included
 * in the solution. Each string in the solution vector must be of the format "(x, y, z)",
 * where x, y, and z are the integer coordinates of a cell.
 *
 * Understand that most mazes will contain multiple solutions
 *
 * Returns:		vector<string>
 *				A solution to the current maze, or an empty vector if none exists
 */
bool Pathfinder::findSolution(vector<string>& solution, vector<string>& temp, int x, int y, int z)
{
    stringstream ss;
    string current_tile;
    
    if (current_maze[x][y][z] == 0)
    {
        return false; //can't go there
    }
    if ( x < 0 || x > 4 || y < 0 || y > 4 || z < 0 || z > 4) // out of range of maze
    {
        return false;
    }
    
    if ( x == 4 && y == 4 && z == 4) // if we make it to the last tile, include in our solution vector
    {
        ss << "(" << x << ", " << y << ", " << z << ")";
        solution.push_back(ss.str());
        return true;
    }
    
    ss << "(" << x << ", " << y << ", " << z << ")"; // if it is not a 0 and is in range, we can step on it
    current_tile = ss.str(); 				//set it to our current tile
    
    for (int i = 0; i < temp.size(); i++)
    {
        if (current_tile == temp[i]) // if this current tile is already in our vector, we've already been here
        {				// so return false
            return false;
        }
    }
    temp.push_back(current_tile); // otherwise put tile in our temporary vector
    solution.push_back(current_tile); // and the solution vector
    
    if (findSolution(solution, temp, x + 1, y, z) == true) // look at tile to the right
    {
        return true;
    }
    if (findSolution(solution, temp, x, y + 1, z) == true) // look at tile down
    {
        return true;
    }
    if (findSolution(solution, temp, x, y, z + 1) == true) // look at tile on next level
    {
        return true;
    }
    if (findSolution(solution, temp, x - 1, y, z) == true) // look at tile to the left
    {
        return true;
    }
    if (findSolution(solution, temp, x, y - 1, z) == true) // look at tile above
    {
        return true;
    }
    if (findSolution(solution, temp, x, y, z - 1) == true) // look at tile on previous level
    {
        return true;
    }
    
    solution.pop_back(); // if tile gets here, it is not a possible solution because you cant go any further
    // so take it out solution vector and return false
    return false;
    
}

vector<string> Pathfinder::solveMaze()
{
    vector<string> solution;
    vector<string> temp;
    if (isValid(getMaze()))
    {
        findSolution(solution, temp, 0, 0, 0);
    }
    
    return solution;
}
