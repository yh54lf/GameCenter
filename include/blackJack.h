#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;

class Blackjack
{
private:
    int playerTot;
    int dealerTot;
    char playAgain;

public:
    Blackjack();
    bool playGame();
    void dealCards();
    void playerTurn();
    void dealerTurn();
    bool determineWinner();
    void pause(int dur);
};
