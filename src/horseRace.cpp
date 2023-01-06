#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>
#include <chrono>
#include <thread>
#include "C:\Users\Benjamin\Desktop\GameCenter\include\horseRace.h"
using namespace std;

Horse::Horse()
{
    position = 0;
}
void Horse::advance()
{
    position += rand() % 2; // move the horse a random number of steps (0-1)
}
int Horse::getPosition() const
{
    return position;
}

void Race::sleep(int millisec)
{

    this_thread::sleep_for(chrono::milliseconds(millisec));
}
int Race::start()
{
    int checkWinner;
    int userBet = horseBet();

    srand(time(NULL));

    bool continueon = true; // this keeps track whether the race is finished
    for (int n = 0; n < NUM_HORSES; n++)
    {
        printLane(n); // prints the lane of the horse that we have an n for
    }

    cout << "\nReady" << endl;
    sleep(2000);
    cout << "set" << endl;
    sleep(2000);
    cout << "go!" << endl;
    sleep(2000); // prints out before race begin

    while (continueon)
    {
        // This for loop advances the horses
        for (int number = 0; number < NUM_HORSES; number++)
        {
            horses[number].advance();
            cout << endl;
        }

        // This for loop prints the lanes
        for (int number = 0; number < NUM_HORSES; number++)
        {
            printLane(number); // prints the lane of each horse
            if (horses[number].getPosition() == (RACE_LENGTH))
            {
                continueon = false;                                     // if the horse reaches the end, this sets the variable to false and kills the while loop
                cout << "Horse " << number + 1 << " is winner" << endl; // prints which horse is the winner

                if (userBet == number + 1)
                {
                    checkWinner = 1;
                }
                else
                {
                    checkWinner = 0;
                }
            }
        }

        sleep(400); // sleep for the specified time interval
        system("cls");
    }
    if (checkWinner == 1)
    {
        cout << "You win" << endl;
        ;
    }
    else
    {
        cout << "You lost" << endl;
    }
    return checkWinner;
}
void Race::printLane(int horseNum)
{
    // prints each horses lane
    for (int i = 0; i < RACE_LENGTH; i++)
    {
        // iterates over the length of the race
        int loc = horses[horseNum].getPosition(); // returns the location of each horse
        if (i == loc)
        {
            // tests to see if the horse is at the position we're iterating through
            cout << "Horse [" << horseNum + 1 << "]"; // if yes, then prints the horse's number
        }
        else
        {
            cout << "."; // prints a period to represent empty track elsewise
        }
    }
    cout << endl; // creates a newline
}
int Race::horseBet()
{
    bool test = true;
    int bet;
    while (test)
    {
        cout << "On what horse do you wish to bet? (1, 2, 3, 4, 5): ";

        cin >> bet;
        if (bet > 5 || bet < 1)
        {
            cout << "Invalid choice!" << endl;
        }

        else
            test = false;
    }
    return bet;
}
