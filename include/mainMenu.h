#include <iostream>
#include <windows.h>

using namespace std;
class GameCenter
{
private:
    int points;

public:
    GameCenter();
    ~GameCenter(){};
    int userPoints;
    void handleUserChoiceGames();
    void printMainMenu();
    void handleUserChoiceMainMenu();
    void printGames();
    string userChoice();
    void pause(double dur);
    void play();
    int bet();
    void boundary(string load);
};
