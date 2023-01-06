#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "C:\Users\Benjamin\Desktop\GameCenter\include\blackJack.h"
using namespace std;

Blackjack::Blackjack()
{
    playerTot = 0;
    dealerTot = 0;
}

bool Blackjack::playGame()
{

    srand(time(0));
    bool checkWinner;

    dealCards();

    // Check for blackjack
    if (playerTot == 21)
    {
        cout << "Blackjack! You win!" << endl;

        checkWinner = true;
        return checkWinner;
    }
    else if (dealerTot == 21)
    {
        cout << "Dealer has blackjack. You lose." << endl;

        checkWinner = false;
        return checkWinner;
    }

    playerTurn();

    // Check if player has busted
    if (playerTot > 21)
    {
        cout << "You busted. You lose." << endl;
        checkWinner = false;
        return checkWinner;
    }

    dealerTurn();

    // Check if dealer has busted
    if (dealerTot > 21)
    {
        cout << "Dealer busted. You win!" << endl;

        checkWinner = true;
        return checkWinner;
    }

    checkWinner = determineWinner();
    return checkWinner;
}

void Blackjack::dealCards()
{
    // Deal the initial cards
    int playerCard1 = rand() % 10 + 1;
    int playerCard2 = rand() % 10 + 1;
    int dealerCard1 = rand() % 10 + 1;
    int dealerCard2 = rand() % 10 + 1;

    playerTot = playerCard1 + playerCard2;
    dealerTot = dealerCard1 + dealerCard2;

    cout << endl;
    pause(3);
    cout << "You have been dealt: " << playerCard1 << " and " << playerCard2 << endl;
    pause(1);
    cout << "Your total is: " << playerTot << endl;
    cout << endl;
    pause(3);
    cout << "The dealer has been dealt: " << dealerCard1 << " and " << dealerCard2 << endl;
    pause(1);
    cout << "The dealer's total is: " << dealerTot << endl;
    cout << endl;
}

void Blackjack::playerTurn()
{
    while (playerTot < 21)
    {
        cout << "Hit or stand (h/s)? ";
        string choice;
        cin >> choice;

        if (choice == "h" || choice == "H")
        {
            int newCard = rand() % 10 + 1;
            pause(2);
            cout << endl;
            cout << "You were dealt: " << newCard << endl;
            playerTot += newCard;
            pause(1);
            cout << "your total is: " << playerTot << endl;
            cout << endl;
        }
        else if (choice == "s" || choice == "S")
        {
            break;
        }

        else if (choice.length() != 1)
            cout << "Invalid choice" << endl;

        else
            cout << "Invalid choice " << endl;
    }
}
void Blackjack::dealerTurn()
{
    while (dealerTot < 21)
    {
        if (dealerTot < 17)
        {
            int newCard = rand() % 10 + 1;
            pause(2);
            cout << endl;
            cout << "Dealer was dealt: " << newCard << endl;
            dealerTot += newCard;
            pause(1);
            cout << "Dealer's total is now: " << dealerTot << endl;
            cout << endl;
        }
        else
        {
            break;
        }
    }
}

bool Blackjack::determineWinner()
{
    if (playerTot > dealerTot)
    {
        cout << "Dealer busted. You win!" << endl;

        return true;
    }
    else if (playerTot > dealerTot)
    {
        cout << "You win!" << endl;

        return true;
    }
    else if (dealerTot > playerTot)
    {
        cout << "Dealer wins." << endl;
        return false;
    }
    else
    {
        cout << "It's a tie." << endl;
        return false;
    }
}

void Blackjack::pause(int dur)
{
    int temp = time(NULL) + dur;
    while (temp > time(NULL))
        ;
}
