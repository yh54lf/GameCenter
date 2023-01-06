#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;

const int NUM_HORSES = 5;      // number of horses in the race
const int RACE_LENGTH = 30;    // length of the race
const int TURN_DELAY = 500000; // time interval between turns in microseconds

class Horse
{
public:
    Horse();
    void advance();
    int getPosition() const;

private:
    int position;
};

class Race
{
public:
    void sleep(int millisec);

    int start();
    int horseBet();

private:
    Horse horses[NUM_HORSES];

    void printLane(int horseNum);
};
