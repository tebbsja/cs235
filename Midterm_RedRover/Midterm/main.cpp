//
//  main.cpp
//  Midterm
//
//  Created by Austin Tebbs on 10/26/15.
//  Copyright © 2015 Austin Tebbs. All rights reserved.
//
#include "LinkedList.h"
#include "Player.h"
#include "PlayerInterface.h"
#include "RedRover.h"
#include "RedRoverInterface.h"

#include <iostream>

using namespace std;
void menu()
{
    cout << "0 - ADD TO ROSTER\n";
    cout << "1 - VIEW SIZE\n";
    cout << "2 - VIEW ROSTER AND TEAMS\n";
    cout << "3 - Player At Roster\n";
    cout << "4 - Player At Team A\n";
    cout << "5 - Player At Team B\n";
    cout << "6 - Shuffle Roster\n";
    cout << "7 - Create Teams\n";
    cout << "8 - Send Someone Over\n";
    cout << "9 - Team Reset\n";
    cout << "10 - Roster Reset\n";
    cout << "11 - Auto Play\n";
    cout << "12 - Print from Head\n";
    cout << "13 - Print from Tail\n";
    cout << "14 - Quit\n";
    
}
int main()
{
    
    //LinkedList <Player*> chain;
    RedRover x;
    //RedRover y;
    //cout << x.getRoster() << x.getTeamB() << x.getTeamA();
    //x.addToRoster("");
    
    x.addToRoster("Juice\n20\n15\nKaylee\n25\n12\nMatt\n15\n20\nAustin\n1\n20\nAdam\n22\n18\nJeff\n15\n12\nSue\n30\n30\nRoy\n100\n100");
    
    //cout << "Hello World\n";
    
    //x.createTeams();
    //x.sendSomeoneOver(x.teamAAt(0), x.teamBAt(0));
   // x.addToRoster("Juice\n10\n15\nKate\n5\n5\nRoy\n20\n20");
   // x.rosterReset();
    //cout << x.getRoster();
    //x.addToRoster("Juice\n3\n4");
    bool testing = true;
    int input = 0;
    
while(testing)
{
    menu();
    cin >> input;
    //input = 11;
    
    switch (input)
    {
        case 0:
        {
            cin.ignore();
            string add;
            cout << "ENTER A STRING: ";
            getline(cin, add);
            x.addToRoster(add);
          break;
        }
        case 1:
        {
            cout << "Roster Size: " << x.getRosterSize() << endl;
            cout << "Team A Size: " << x.getTeamASize() << endl;
            cout << "Team B Size: " << x.getTeamBSize() << endl << endl;
           break;
        }
        case 2:
        {
            cout << "Roster: " << x.getRoster() << endl;
            cout << "Team A: " << x.getTeamA() << endl;
            cout << "Team B: " << x.getTeamB() << endl << endl;
           break;
        }
        case 3:
        {
            int index=0;
            cout << "ENTER INDEX FOR PLAYER ON ROSTER: ";
            cin >> index;
            PlayerInterface* p1 = x.rosterAt(index);
            cout << "\n At index: " << index << " - " << p1->getName() << " Str: " << p1->getStrength()
            << " Spd: " << p1->getSpeed() << endl << endl;
          break;
        }
            
        case 4:
        {
            int index=0;
            cout << "ENTER INDEX FOR PLAYER ON Team A: ";
            cin >> index;
            PlayerInterface* p1 = x.teamAAt(index);
            cout << "\n At index: " << index << " - " << p1->getName() << " Str: " << p1->getStrength()
            << " Spd: " << p1->getSpeed() << endl << endl;
           break;
        }
            
        case 5:
        {
            int index=0;
            cout << "ENTER INDEX FOR PLAYER ON Team B: ";
            cin >> index;
            PlayerInterface* p1 = x.teamBAt(index);
            cout << "\n At index: " << index << " - " << p1->getName() << " Str: " << p1->getStrength()
            << " Spd: " << p1->getSpeed() << endl << endl;
            break;
        }
            
        case 6:
        {
            cout << "SHUFFLING ROSTER***\n";
            x.shuffleRoster();
            cout << "Roster: " << x.getRoster() << endl << endl;
           break;
        }
            
        case 7:
        {
            cout << "CREATING TEAMS***\n";
            x.createTeams();
            cout << "TEAM A: " << x.getTeamA() << endl;
            cout << "TEAM B: " << x.getTeamB() << endl << endl;
           break;
        }
            
        case 8:
        {
            int run_index, def_index;
            char run_team, def_team;
            PlayerInterface* runner;
            PlayerInterface* defender;
            cout << "SEND SOMEONE OVER***\n";
            cout << "TEAM A: " << x.getTeamA() << endl;
            cout << "TEAM B: " << x.getTeamB() << endl << endl;
            cout << "ENTER INDEX FOR RUNNER: ";
            cin >> run_index;
            cout << " TEAM A OR B: ";
            cin >> run_team;
            cout << "\nENTER INDEX FOR DEFENDER: ";
            cin >> def_index;
            cout << " TEAM A OR B: ";
            cin >> def_team;
            if (run_team == 'a')
            {
                runner = x.teamAAt(run_index);
            }
            else
            {
                runner = x.teamBAt(run_index);
            }
            
            if (def_team == 'a')
            {
                defender = x.teamAAt(def_index);
            }
            else
            {
                defender = x.teamBAt(def_index);
            }
            x.sendSomeoneOver(runner, defender);
            cout << endl << "TEAM A: " << x.getTeamA() << endl;
            cout << "TEAM B: " << x.getTeamB() << endl << endl;
            break;
        }
            
        case 9:
        {
            x.teamReset();
            cout << "TEAM A: " << x.getTeamA() << endl;
            cout << "TEAM B: " << x.getTeamB() << endl << endl;
            break;
        }
        case 10:
        {
            x.rosterReset();
            cout << "ROSTER: " << x.getRoster() << endl << endl;
            break;
        }
            
        case 11:
        {
            cout << "auto play\n\n";
            x.autoPlay();
            break;
        }
            
        case 12:
        {
            x.print();
            break;
        }
            
        case 13:
        {
            x.printFromTail();
            break;
        }
            
        case 14:
        {
            testing = false;
            break;
        }
        case 15:
        {
            x.addToRoster("Juice\n20\n15\nKaylee\n25\n12\nMatt\n15\n20\nAustin\n1\n20\nAdam\n22\n18\nJeff\n15\n12\nSue\n30\n30\nRoy\n100\n100");
            break;
        }
            
    }
}
    
    return 0;
}
