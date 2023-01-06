
using namespace std;
#define MAXSIDES 25
#define MAXMINES 99
#define MOVESIZE 526 // (25 * 25 - 99)
class Minesweeper
{
private:
    int sides = 9;
    int mines = 10;

public:
    int tempSides = sides;
    int tempMines = mines;
    Minesweeper(){};
    bool validPos(int row, int col);
    bool isMine(int row, int col, char board[][MAXSIDES]);
    void userMove(int *row, int *column);
    void printBoard(char userBoard[][MAXSIDES]);
    int countMines(int row, int col, int mines[][2], char realBoard[][MAXSIDES]);
    bool playUntil(char userBoard[][MAXSIDES], char realBoard[][MAXSIDES],
                   int mines[][2], int row, int col, int *movesLeft);
    void placeMine(int mines[][2], char realBoard[][MAXSIDES]);
    void initial(char realBoard[][MAXSIDES], char userBoard[][MAXSIDES]);
    bool playMinesweeper();
};
