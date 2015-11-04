//
//  RedRover.cpp
//  Midterm
//
//  Created by Austin Tebbs on 10/26/15.
//  Copyright © 2015 Austin Tebbs. All rights reserved.
//

#include "RedRover.h"
#include <sstream>
#include <ctime>
#include <cstdlib>

/*
	* addToRoster()
	*
	* Accepts a string containing the name, strength, and speed of several Players
	* and adds those Players to the roster.
	*
	* The string will be of the format :
	* 			"PlayerName0
	* 			PlayerStrength0
	* 			PlayerSpeed0
	* 			PlayerName1
	* 			PlayerStrength1
	* 			..."
	*
	* and so on with no trailing endline.
	*
	* In the example above, Player0 would be the first entry in the roster followed by Player1 and any other Players.
	*
	* You may assume that the format of the string and the name, strength, and speed of each player will be valid.
	*
	* Returns true if players were added to the roster, false otherwise
	*/
bool RedRover::addToRoster(string player_list)
{
    string player_stats;
    string name;
    
    stringstream ss(player_list);
    int strength, speed;
    
    if (player_list.empty())
    {
        cout << "NO PLAYERS HAVE BEEN ADDED TO ROSTER\n";
        return false;
    }
    while (!ss.eof())
    {
        if (ss.fail())
        {
            return false;
        }
        ss >> name;
        ss >> strength;
        ss >> speed;
        
        Player* p = new Player(name, strength, speed);
        roster.insertTail(p);
    }
    
    return true;
}

/*
	*getRosterSize()
	*
	* Returns the number of players in the roster.
	*/
int RedRover::getRosterSize()
{
    return roster.size();
}

/*
	*getTeamASize()
	*
	* Returns the number of players on Team A.
	*/
int RedRover::getTeamASize()
{
    return teamA.size();
}

/*
	* getTeamBSize()
	*
	* Returns the number of players on Team B.
	*/
int RedRover::getTeamBSize()
{
    return teamB.size();
}

/*
	* getRoster()
	*
	* Returns a string representing the players currently in the roster.
	* The returned string should be of the format
	* 		"Player0 Player1 Player2 ..."
	* Where Player0 is the Player located at index 0
	*
	* There should be no trailing space in the string returned
	*
	* Returns the string representation of the roster
	*/
string RedRover::getRoster()
{
    if (roster.empty())
    {
        return "Roster empty";
    }
    return roster.rosterFormat();
}

/*
	* getTeamA()
	*
	* Returns a string representing the players currently on Team A.
	* The returned string should be of the format
	* 		"Player0 Player1 Player2 ..."
	* Where Player0 is the Player located at index 0
	*
	* There should be no trailing space in the string returned
	*
	* Returns the string representation of Team A
	*/
string RedRover::getTeamA()
{
    if (teamA.empty())
    {
        return "Team A empty";
    }
    return teamA.rosterFormat();
}

/*
	* getTeamB()
	*
	* Returns a string representing the players currently on Team B.
	* The returned string should be of the format
	* 		"Player0 Player1 Player2 ..."
	* Where Player0 is the Player located at index 0
	*
	* There should be no trailing space in the string returned
	*
	* Returns the string representation of Team B
	*/
string RedRover::getTeamB()
{
    if (teamB.empty())
    {
        return "Team B empty";
    }
    return teamB.rosterFormat();
}

/*
	* rosterAt()
	*
	* Returns a pointer to the player at the given index in the roster.
	* Returns NULL if the index is out of range
	*/
PlayerInterface* RedRover::rosterAt(int index)
{
    return roster.at(index);
}

/*
	* teamAAt()
	*
	* Returns a pointer to the player at the given index in Team A.
	* Returns NULL if the index is out of range
	*/
PlayerInterface* RedRover::teamAAt(int index)
{
    return teamA.at(index);
}

/*
	* teamBAt()
	*
	* Returns a pointer to the player at the given index in Team B.
	* Returns NULL if the index is out of range
	*/
PlayerInterface* RedRover::teamBAt(int index)
{
    return teamB.at(index);
}

/*
	* shuffleRoster()
	*
	* Shuffles the players in the roster
	* Does not affect the players in Team A or Team B
	*/
void RedRover::shuffleRoster()
{
    srand(time(0));
    LinkedList<PlayerInterface*> temp_list;
    PlayerInterface* player_ptr = nullptr;
    int rand_index = 0, size = 0;
    int itr = roster.size();

    for (int i=0; i < itr; i++)
    {
        size = roster.size();
        rand_index = rand() % size;
        player_ptr = roster.at(rand_index); //grab a random player from roster
        temp_list.insertTail(player_ptr); // store in temporary list
        roster.remove(player_ptr); // remove that player from roster
    }
    
    for (int i=0; i < itr; i++)
    {
        roster.insertTail(temp_list.at(i)); // copy all players in temp list back to roster
    }
    
    temp_list.clear(); // clear temp_list
}

/*
	* createTeams()
	*
	* Divides the players in the roster into 2 teams, Team A and Team B
	*
	* The first player in the roster should be added to Team A, the second to Team B, and so on.
	* When a player is added to a team, that player is removed from the roster.
	*
	* Should not remove players from the roster or add them to a team if there are insufficient players in the roster to play the game
	* (there must be at least 2 players on each team in order to play).
	*
	* returns true if Team A and Team B are created successfully, false otherwise
	*/
bool RedRover::createTeams()
{
    int rsize = roster.size();
    //int j=0;
    if (roster.size() < 4)
    {
        cout << "NO PLAYERS HAVE BEEN ADDED TO THE TEAMS\n";
        return false;
    }
    
    if (roster.size() % 2 == 1) // if odd amount of players, leave off last player
    {
        rsize = roster.size() - 1;
    }
    
    for (int i=0; i < rsize; i++)
    {
        if (i % 2 == 0) // even amount of iterations team a insert head from roster
        {
            teamA.insertTail(roster.at(0));
            roster.remove(roster.at(0));
        }
        else // every other, so this is an odd amount of iterations
        {
            teamB.insertTail(roster.at(0));
            roster.remove(roster.at(0));
        }
    }
    return true;
}

/*
	* sendSomeoneOver()
	*
	* The Player "runner" is called over and attempts to break through the defender's defenses.
	*
	* The runner will always attempt to break the link between the defender and the next player in the defender's team.
	* If the defender is the last player in the team, the runner attempts to break the link between the last two players of the team.
	*
	* The runner is successful if the sum of his strength and speed exceeds the sum of the strengths of the defending players.
	*
	* If the runner is successful the stronger of the two players that he attempted to break through is added to the runner's team after the runner
	* If the runner does not break the link, the runner is added to the defender's team after the defender
	*
	* The names of Players will be unique, they will not exist in more than one team.
	*
	* If the runner and the defender are on the same team or if one of the players cannot be located, does nothing
	* If either the runner or the defender is NULL, does nothing
	*/
void RedRover::sendSomeoneOver(PlayerInterface* runner, PlayerInterface* defender)
{
    bool run_success = false;
    bool last_def = false;
    bool def_team_A = false;
    bool run_team_A = false;

    PlayerInterface* partner = nullptr;
    
    if (runner == NULL || defender == NULL)
    {
        //cout << "NULL\n\n";
        return;
    }
    
    if (teamA.isDuplicate(runner->getName())) // if runner is on team A
    {
        //cout << "Runner is on Team A\n\n";
        run_team_A = true;
    }
    else if (teamB.isDuplicate(runner->getName())) // else he is on team b
    {
       // cout << "Runner is on Team B\n\n";
    }
    else
    {
        //cout << "PLAYER NOT FOUND\n\n";
        return;
    }
    
    
    if (teamA.isDuplicate(defender->getName())) // is defender on team A
    {
        if (teamA.at(teamA.size() -1) == defender )// if defender is last
        {
            partner = teamA.prev_player(defender);
            last_def = true;
        }
        else
        {
            partner = teamA.next_player(defender);
        }
        def_team_A = true;
    }
    else if (teamB.isDuplicate(defender->getName())) // else defender is on team B
    {
        if (teamB.at(teamB.size() -1)->getName() == defender->getName() )// if defender is last
        {
            partner = teamB.prev_player(defender);
            last_def = true;
        }
        else
        {
            partner = teamB.next_player(defender);
        }
        def_team_A = false;
    }
    else
    {
        return;
    }
    
    if (run_team_A == def_team_A)
    {
        return;
    }
    
    if (runner->getSpeed() + runner->getStrength() > defender->getStrength() + partner->getStrength()) //if runner breaks chain
    {
        run_success = true; //run success bool will determine who is added to which roster.
    }
    
    if (run_success) //if runner broke through
    {
        //determine who was stronger
        if (defender->getStrength() >= partner->getStrength()) // defender stronger or equal strength
        {
            //add defender to runner team
            if(run_team_A) //if runner is on team A add to team A
            {
                teamA.insertAfter(defender, runner);
                teamB.remove(defender); //remove defender from team B
            }
            else // if runner is not on team A, add defender to Team B
            {
                teamB.insertAfter(defender, runner);
                teamA.remove(defender); // remove from team A
            }
        }
        else // if partner stronger
        {
            if(run_team_A) //if runner is on team A add to team A
            {
                teamA.insertAfter(partner, runner);
                teamB.remove(partner); //remove partner from team B
            }
            else // if runner is not on team A, add defender to Team B
            {
                teamB.insertAfter(partner, runner);
                teamA.remove(partner); // remove from team A
            }
        }
    }
    else // if runner didn't break through
    {
        // add runner to defenders team
        if(run_team_A) //if runner is on team A add to team B
        {
            teamB.insertAfter(runner, defender);
            teamA.remove(runner); //remove runner from team A
        }
        else // if runner is not on team A, add to Team A
        {
            teamA.insertAfter(runner, defender);
            teamB.remove(runner); // remove from team B
        }
    }
    
    if (teamA.size() == 1)
    {
        cout << "Team B wins! " << teamB.rosterFormat() << endl;
    }
    if (teamB.size() == 1)
    {
        cout << "Team A wins! " << teamA.rosterFormat() << endl;
    }
    
    
}

/*
	* teamReset()
	*
	* Empties both teams (does not affect the roster)
	*/
void RedRover::teamReset()
{
    teamA.clear();
    teamB.clear();
}

/*
	* rosterReset()
	*
	* Empties all players from the roster
	* (does nothing to Team A or Team B)
	*/
void RedRover::rosterReset()
{
    roster.clear();
}


/*
	* autoPlay()
	*
	* Simulates a game of Red Rover and notifies the user of the winning team.
	*
	* Selects a random player from one team to attempt to break through a random player from the other team until one team has won.
	*
	* Starting with Team A, teams take turns attempting to break through.
	*
	* When the function ends, both teams should be emptied.
	*
	* this function returns nothing, but it MUST print out
	* 		the name of the runner
	* 		the name of the defender and
	* 		the players on each team
	* after each attempt to break through.
	*
	* At the end of the game, print out the name of the winning team and the players on both teams.
	*/
void RedRover::autoPlay()
{
    srand(time(0));
    int rand_index_runner = 0, rand_index_defender = 0, i = 0;
    
    PlayerInterface* runner = NULL;
    PlayerInterface* defender = NULL;
    
    bool playing = true;
    if (roster.size() < 4)
    {
        cout << "INSUFFICIENT PLAYERS\n\n";
        return;
    }
    
    createTeams();
    
    //cout << "TEAM A: " << getTeamA() << endl;
    //cout << "TEAM B: " << getTeamB() << endl << endl;
    
    while (playing)
    {
        if (i % 2 == 0)
        {   //cout << "I: " << i << "rand: " << rand() % 6 << endl;
            //team a turn

            rand_index_runner = rand() % getTeamASize(); // grab random player from A as runner
            runner = teamA.at(rand_index_runner);
            
            rand_index_defender = rand() % getTeamBSize(); // grab random player from B As Defender
            defender = teamB.at(rand_index_defender);
            
        }
        else if (i % 2 == 1)
        {
            //team b turn
            rand_index_runner = rand() % getTeamBSize(); // grab random player from B as runner
            runner = teamB.at(rand_index_runner);
            
            rand_index_defender = rand() % getTeamASize(); // grab random player from A As Defender
            defender = teamA.at(rand_index_defender);
        }
        
        cout << "RUNNER: " << runner->getName() << endl;
        cout << "DEFENDER: " << defender->getName() << endl << endl;
        
        sendSomeoneOver(runner, defender);
        
        if (teamA.size() > 1 && teamB.size() > 1)
        {
            cout << "TEAM A: " << getTeamA() << endl;
            cout << "TEAM B: " << getTeamB() << endl << endl;
        }
        else if (teamA.size() == 1 || teamB.size() == 1)
        {
            if (teamA.size() == 1)
            {
                cout << "Team A lost! " << getTeamA() << endl << endl;
            }
            else if (teamB.size() == 1)
            {
                cout << "Team B lost! " << getTeamB() << endl << endl;
            }
            playing = false;
        }
        i++;
    }
    
    teamReset();

}

void RedRover::print()
{
    cout << "***PRINT FROM HEAD***\n";
    cout << "***ROSTER***\n";
    roster.print();
    cout << "\n***TEAMA***\n";
    teamA.print();
    cout << "\n***TEAMB***\n";
    teamB.print();
}
void RedRover::printFromTail()
{
    cout << "***FROM TAIL***\n";
    cout << "***ROSTER***\n";
    roster.printFromTail();
    cout << "\n***TEAMA***\n";
    teamA.printFromTail();
    cout << "\n***TEAMB***\n";
    teamB.printFromTail();
}