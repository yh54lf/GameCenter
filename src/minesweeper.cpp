#include <iostream>
#include <ctime>
#include <cstring>
#include "C:\Users\Benjamin\Desktop\GameCenter\include\minesweeper.h"
using namespace std;

// A function that prints the playing board
void Minesweeper::printBoard(char userBoard[][MAXSIDES])
{
    cout << "  ";
    // Prints out upper coordinates of the board
    for (int i = 0; i < Minesweeper::tempSides; i++)
    {
        cout << " " << i;
    }
    cout << endl;
    cout << endl;

    // Prints out left coordinates of the board and draws "-" on the board
    for (int i = 0; i < Minesweeper::tempSides; i++)
    {
        cout << " " << i;

        for (int j = 0; j < Minesweeper::tempSides; j++)
        {
            cout << " " << userBoard[i][j];
        }
        cout << endl;
    }
    return;
}

// A function that gets users moves
void Minesweeper::userMove(int *row, int *column)
{
    // Takes users input
    cout << "Choose a field (row, column): ";
    scanf("%d %d", row, column);
    return;
}

bool Minesweeper::validPos(int row, int col)
{
    // Returns true if row number and column number is in range
    return (row >= 0) && (row < Minesweeper::tempSides) &&
           (col >= 0) && (col < Minesweeper::tempSides);
}

// Places random mines in the fields
void Minesweeper::placeMine(int mines[][2], char realBoard[][MAXSIDES])
{
    bool mark[MAXSIDES * MAXSIDES];

    memset(mark, false, sizeof(mark));

    for (int i = 0; i < Minesweeper::tempMines;)
    {
        int random = rand() % (Minesweeper::tempSides * Minesweeper::tempSides);
        int x = random / Minesweeper::tempSides;
        int y = random % Minesweeper::tempSides;

        // Adds a mine if there is none in that position
        if (mark[random] == false)
        {
            // Row index of a mine
            mines[i][0] = x;
            // Column index of a mine
            mines[i][1] = y;

            // Place a mine

            realBoard[mines[i][0]][mines[i][1]] = '*';
            mark[random] = true;
            i++;
        }
    }
    return;
}
// Checks if there is a mine in the field
bool Minesweeper::isMine(int row, int col, char board[][MAXSIDES])
{
    if (board[row][col] == '*')
        return true;

    else
        return false;
}
// Counts adjecent mines around the chosen field
int Minesweeper::countMines(int row, int col, int mines[][2], char realBoard[][MAXSIDES])
{

    int mineCount = 0;

    // Count all the mines in all adjecent fields

    // Upper field
    if (Minesweeper::validPos(row - 1, col) == true) // checks if the adjecent field exists
    {
        if (Minesweeper::isMine(row - 1, col, realBoard) == true)
            mineCount++;
    }
    // UpperRight field
    if (Minesweeper::validPos(row - 1, col + 1) == true) // checks if the adjecent field exists
    {
        if (Minesweeper::isMine(row - 1, col + 1, realBoard) == true)
            mineCount++;
    }
    // Right field
    if (Minesweeper::validPos(row, col + 1) == true) // checks if the adjecent field exists
    {
        if (Minesweeper::isMine(row, col + 1, realBoard) == true)
            mineCount++;
    }
    // LowerRight field
    if (Minesweeper::validPos(row + 1, col + 1) == true) // checks if the adjecent field exists
    {
        if (Minesweeper::isMine(row + 1, col + 1, realBoard) == true)
            mineCount++;
    }
    // Lower field
    if (Minesweeper::validPos(row + 1, col) == true) // checks if the adjecent field exists
    {
        if (Minesweeper::isMine(row + 1, col, realBoard) == true)
            mineCount++;
    }
    // LowerLeft field
    if (Minesweeper::validPos(row + 1, col - 1) == true) // checks if the adjecent field exists
    {
        if (Minesweeper::isMine(row + 1, col - 1, realBoard) == true)
            mineCount++;
    }
    // Left field
    if (Minesweeper::validPos(row, col - 1) == true) // checks if the adjecent field exists
    {
        if (Minesweeper::isMine(row, col - 1, realBoard) == true)
            mineCount++;
    }
    // UpperLeft field
    if (Minesweeper::validPos(row - 1, col - 1) == true) // checks if the adjecent field exists
    {
        if (Minesweeper::isMine(row - 1, col - 1, realBoard) == true)
            mineCount++;
    }
    return mineCount;
}

// Intialises the game
void Minesweeper::initial(char realBoard[][MAXSIDES], char userBoard[][MAXSIDES])
{
    srand(time(NULL));

    for (int i = 0; i < Minesweeper::tempSides; i++)
    {
        for (int j = 0; j < Minesweeper::tempSides; j++)
        {
            userBoard[i][j] = realBoard[i][j] = '-';
        }
    }
}

bool Minesweeper::playUntil(char userBoard[][MAXSIDES], char realBoard[][MAXSIDES],
                            int mines[][2], int row, int col, int *movesLeft)
{

    if (userBoard[row][col] != '-')
        return false;

    int i, j;

    // Game ends if a user clicks on a mine
    if (realBoard[row][col] == '*')
    {
        userBoard[row][col] = '*';

        for (i = 0; i < Minesweeper::tempMines; i++)
            userBoard[mines[i][0]][mines[i][1]] = '*';

        Minesweeper::printBoard(userBoard);
        printf("\nYou lost!\n");
        return (true);
    }

    else
    {
        // Calculate the number of adjacent mines and put it
        // on the board
        int count = Minesweeper::countMines(row, col, mines, realBoard);
        (*movesLeft)--;

        userBoard[row][col] = count + '0';

        if (!count)
        {

            // Only process this cell if this is a valid one
            if (Minesweeper::validPos(row - 1, col) == true)
            {
                if (Minesweeper::isMine(row - 1, col, realBoard) == false)
                    Minesweeper::playUntil(userBoard, realBoard, mines, row - 1, col, movesLeft);
            }

            //----------- 2nd Neighbour (South) ------------

            // Only process this cell if this is a valid one
            if (Minesweeper::validPos(row + 1, col) == true)
            {
                if (Minesweeper::isMine(row + 1, col, realBoard) == false)
                    Minesweeper::playUntil(userBoard, realBoard, mines, row + 1, col, movesLeft);
            }

            //----------- 3rd Neighbour (East) ------------

            // Only process this cell if this is a valid one
            if (Minesweeper::validPos(row, col + 1) == true)
            {
                if (Minesweeper::isMine(row, col + 1, realBoard) == false)
                    Minesweeper::playUntil(userBoard, realBoard, mines, row, col + 1, movesLeft);
            }

            //----------- 4th Neighbour (West) ------------

            // Only process this cell if this is a valid one
            if (Minesweeper::validPos(row, col - 1) == true)
            {
                if (Minesweeper::isMine(row, col - 1, realBoard) == false)
                    Minesweeper::playUntil(userBoard, realBoard, mines, row, col - 1, movesLeft);
            }

            //----------- 5th Neighbour (North-East) ------------

            // Only process this cell if this is a valid one
            if (Minesweeper::validPos(row - 1, col + 1) == true)
            {
                if (Minesweeper::isMine(row - 1, col + 1, realBoard) == false)
                    Minesweeper::playUntil(userBoard, realBoard, mines, row - 1, col + 1, movesLeft);
            }

            //----------- 6th Neighbour (North-West) ------------

            // Only process this cell if this is a valid one
            if (Minesweeper::validPos(row - 1, col - 1) == true)
            {
                if (Minesweeper::isMine(row - 1, col - 1, realBoard) == false)
                    Minesweeper::playUntil(userBoard, realBoard, mines, row - 1, col - 1, movesLeft);
            }

            //----------- 7th Neighbour (South-East) ------------

            // Only process this cell if this is a valid one
            if (Minesweeper::validPos(row + 1, col + 1) == true)
            {
                if (Minesweeper::isMine(row + 1, col + 1, realBoard) == false)
                    Minesweeper::playUntil(userBoard, realBoard, mines, row + 1, col + 1, movesLeft);
            }

            //----------- 8th Neighbour (South-West) ------------

            // Only process this cell if this is a valid one
            if (Minesweeper::validPos(row + 1, col - 1) == true)
            {
                if (Minesweeper::isMine(row + 1, col - 1, realBoard) == false)
                    Minesweeper::playUntil(userBoard, realBoard, mines, row + 1, col - 1, movesLeft);
            }
        }

        return (false);
    }
}

bool Minesweeper::playMinesweeper()
{
    bool checkWinner;
    // Initially the game is not over
    bool gameOver = false;

    // Actual Board and User Board
    char realBoard[MAXSIDES][MAXSIDES];
    char userBoard[MAXSIDES][MAXSIDES];

    int movesLeft = Minesweeper::tempSides * Minesweeper::tempSides - Minesweeper::tempMines, x, y;
    int mines[MAXMINES][2]; // stores (x,y) coordinates of all mines.

    Minesweeper::initial(realBoard, userBoard);

    // Place the Mines randomly
    Minesweeper::placeMine(mines, realBoard);

    // Game goes on until a user clicks on a mine

    int currentMove = 0;
    while (gameOver == false)
    {
        printf("Current Status of Board : \n");
        Minesweeper::printBoard(userBoard);
        Minesweeper::userMove(&x, &y);

        currentMove++;

        gameOver = Minesweeper::playUntil(userBoard, realBoard, mines, x, y, &movesLeft);

        if ((gameOver == false) && (movesLeft == 0))
        {
            cout << "You won!" << endl;
            cout << "You earn 10 points!" << endl;
            gameOver = true;
            checkWinner = true;
        }
    }
    return checkWinner;
}
