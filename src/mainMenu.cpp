#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <Windows.h>
#include <MMSystem.h>
#include "C:\Users\Benjamin\Desktop\GameCenter\include\mainMenu.h"
#include "minesweeper.cpp"
#include "horseRace.cpp"
#include "blackJack.cpp"

GameCenter::GameCenter()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0A);
    points = 100;
    userPoints = points;
}
void GameCenter::boundary(string load)
{
    cout << endl;
    short x = 0;
    while (load[x] != '\0')
    {
        cout << load[x];
        std::this_thread::sleep_for(std::chrono::milliseconds(15));

        x++;
    }
}

void GameCenter::printGames()
{
    system("cls");

    boundary("***************What game would you like to play?***************\n");
    cout << "Points: " << GameCenter::userPoints << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    cout << "\t \t \t 1. Horse Race" << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    cout << "\t \t \t 2. Minesweeper" << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    cout << "\t \t \t 3. BlackJack" << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    cout << "\t \t \t 4. Go Back " << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    boundary("****************************************************************\n");
    cout << endl;
    GameCenter::handleUserChoiceGames();
}

void GameCenter::handleUserChoiceGames()
{
    string choice = GameCenter::userChoice();
    if (choice == "1")
    {
        int userBet = GameCenter::bet();
        system("cls");

        Race start;
        bool checkWinner = start.start();
        if (checkWinner == true)
        {
            cout << "You earn " << userBet * 2 << " points!" << endl;
            userPoints += userBet;
        }
        else
            userPoints -= userBet;

        pause(4);
        GameCenter::printGames();
    }

    else if (choice == "2")
    {
        int userBet = GameCenter::bet();
        system("cls");
        Minesweeper start;
        bool checkWinner = start.playMinesweeper();
        if (checkWinner == true)
        {
            cout << "You earn " << userBet * 2 << " points!" << endl;
            userPoints += userBet;
        }
        else
            userPoints -= userBet;

        pause(4);
        GameCenter::printGames();
    }
    else if (choice == "3")
    {
        int userBet = GameCenter::bet();
        system("cls");

        Blackjack start;
        bool checkWinner = start.playGame();
        if (checkWinner == true)
        {
            cout << "You earn " << userBet * 2 << " points!" << endl;
            userPoints += userBet;
        }
        else
            userPoints -= userBet;

        pause(4);
        GameCenter::printGames();
    }

    else if (choice == "4")
    {
        // if user chooses Back option, he gets returned to main menu
        GameCenter::printMainMenu();
    }

    else
    {
        // Invalid choice
        boundary("Invalid choice\n");
        cout << endl;
        pause(2);
        system("cls");

        GameCenter::printGames();
        return;
    }
}

string GameCenter::userChoice()
{
    bool test = true;
    string choice = "t";
    // Returns the choice user enters
    while (test)
    {

        boundary("Enter your choice: ");

        getline(cin, choice);
        cout << endl;
        if (choice.length() != 1)
        {

            boundary("Please enter only one number.\n");

            pause(1);

            cout << endl;
        }
        else
            test = false;
    }

    return choice;
}
void GameCenter::printMainMenu()
{
    system("cls");

    // Display the main menu for the game center
    cout << endl;

    boundary("***************Welcome to the game center!***************\n");
    cout << "Points: " << GameCenter::userPoints << endl;
    pause(1);
    cout << "\t \t     1. Play a game" << endl;
    pause(1);
    cout << "\t \t     2. Quit" << endl;
    pause(1);
    boundary("*********************************************************\n");

    GameCenter::handleUserChoiceMainMenu();
}
void GameCenter::handleUserChoiceMainMenu()
{

    string choice = GameCenter::userChoice();

    if (choice == "1")
    {
        // List the available games in the game center

        printGames();
    }
    // if user chooses Back option, he gets returned to main menu

    else if (choice == "2")
    {

        // Quit the program
        cout << endl;
        system("cls");

        boundary("Thank you for using the game center!\n");
        pause(1);
        boundary("Points status: ");
        cout << GameCenter::userPoints;
        cout << endl;
        pause(1);

        boundary("Goodbye\n");
        pause(2);
        exit;
    }

    else
    {
        // Invalid choice
        boundary("Invalid choice\n");
        pause(2);

        cout << endl;
        GameCenter::printMainMenu();
    }
}

int GameCenter::bet()
{
    int bet;
    bool check = true;
    while (check)
    {

        boundary("How much points do you want to bet (enter 0 to go back): ");
        cin >> bet;
        if (bet > userPoints || bet < 0)

            cout << endl;

        if (bet > userPoints)

        {
            boundary("You do not have enough points!\n");
        }
        else if (bet == 0)

        {
            GameCenter::printGames();
            abort();
        }
        else if (bet == 0)

            GameCenter::printGames();
        else
        {
            check = false;
        }
    }
    return bet;
}

void GameCenter::pause(double dur)
{
    double temp = time(NULL) + dur;
    while (temp > time(NULL))
        ;
}
void GameCenter::play()
{
    printMainMenu();
}
