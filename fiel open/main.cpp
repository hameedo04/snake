//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- 
// Program description:   Plays a tic tac toe game with two players until one wins
// Program author:  Muhammad Reed
// Class and term:   CS2010, fall 2022 
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- 



#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <iomanip>
using namespace std;
// Declares global variables
const int rows = 6;
const int columns = 13;
const char X = 'X';
const char O = 'O';

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- 
 // Function name:   readIntialGrid
 // Function description: Reads the file to make the grid
 // Function parameters: Holds the array that holds the grid and the file as parameters
 // Funcrion return value: Does not return value
// Function author:  Muhammad Reed
// Class and term:   CS2010, fall 2022 
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-  

void readInitialGrid(char grid[][columns], ifstream& infile) {
    int i;
    int j;
    int move;
    // Reads file
    for (i = 0; i < rows; ++i) {
        for (j = 0; j < columns; ++j) {
            infile >> move;
            grid[i][j] = move;
        }
    }
}

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- 
 // Function name:   initializeGrid
 // Function description: Initializes the grid including spaces where X's and O's go
 // Function parameters: The grid array
 // Funcrion return value: Does not return value
// Function author:  Muhammad Reed
// Class and term:   CS2010, fall 2022 
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-  
void initializeGrid(char grid[][columns]) {

    // Initializes spots with spaces
    grid[1][3] = ' ';
    grid[1][7] = ' ';
    grid[1][11] = ' ';
    grid[3][3] = ' ';
    grid[3][7] = ' ';
    grid[3][11] = ' ';
    grid[5][3] = ' ';
    grid[5][7] = ' ';
    grid[5][11] = ' ';
}

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- 
 // Function name:   displayGrid
 // Function description: Outputs the grid
 // Function parameters: Grid array
 // Funcrion return value: Does not return value
// Function author:  Muhammad Reed
// Class and term:   CS2010, fall 2022 
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-  

void displayGrid(char grid[][columns]) {
    int i;
    int j;
    // Outputs grid
    for (i = 0; i < rows; ++i) {
        for (j = 0; j < columns; ++j) {
            cout << grid[i][j];
        }
        cout << endl;
    }
}
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- 
 // Function name:   isWin
 // Function description: Checks if a player has won
 // Function parameters: Holds the array and moves
 // Funcrion return value: Returns true if a player has won, else returns false
// Function author:  Muhammad Reed
// Class and term:   CS2010, fall 2022 
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-  

bool isWin(char grid[][columns], int moves) {

    // Each checks vertical, horizontal, and diagonal wins
    if (grid[1][3] == grid[1][7] && grid[1][7] == grid[1][11] && grid[1][3] != ' ') {
        displayGrid(grid);
        cout << "The winner is " << grid[1][3] << "'s!" << endl;
        return true;
    }
    else if (grid[3][3] == grid[3][7] && grid[3][7] == grid[3][11] && grid[3][3] != ' ') {
        displayGrid(grid);
        cout << "The winner is " << grid[3][3] << "'s!" << endl;
        return true;
    }
    else if (grid[5][3] == grid[5][7] && grid[5][7] == grid[5][11] && grid[5][3] != ' ') {
        displayGrid(grid);
        cout << "The winner is " << grid[5][3] << "'s!" << endl;
        return true;
    }
    else if (grid[1][3] == grid[3][3] && grid[3][3] == grid[5][3] && grid[1][3] != ' ') {
        displayGrid(grid);
        cout << "The winner is " << grid[1][3] << "'s!" << endl;
        return true;
    }
    else if (grid[1][7] == grid[3][7] && grid[3][7] == grid[5][7] && grid[1][7] != ' ') {
        displayGrid(grid);
        cout << "The winner is " << grid[1][7] << "'s!" << endl;
        return true;
    }
    else if (grid[1][11] == grid[3][11] && grid[3][11] == grid[5][11] && grid[1][11] != ' ') {
        displayGrid(grid);
        cout << "The winner is " << grid[1][11] << "'s!" << endl;
        return true;
    }
    else if (grid[1][3] == grid[3][7] && grid[3][7] == grid[5][11] && grid[1][3] != ' ') {
        displayGrid(grid);
        cout << "The winner is " << grid[1][3] << "'s!" << endl;
        return true;
    }
    else if (grid[1][11] == grid[3][7] && grid[3][7] == grid[5][3] && grid[1][11] != ' ') {
        displayGrid(grid);
        cout << "The winner is " << grid[1][11] << "'s!" << endl;
        return true;
    }
    else {
        return false;
    }
}
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- 
 // Function name:   main
 // Function description: Calls the other functions to go through the entire game
 // Function parameters: None
 // Funcrion return value: Returns 0
// Function author:  Muhammad Reed
// Class and term:   CS2010, fall 2022 
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-  

int main() {
    char grid[rows][columns];
    int move = 0;
    int pickRow;
    char pickColumn;
    int newGame;

    ifstream infile;

    infile.open("pgm7-input.txt");

    // Cheks if file is open

    if (!infile.is_open()) {
        cout << "ERROR: File not found" << endl;
        return 1;
    }

    if (infile.is_open()) {
        readInitialGrid(grid, infile);
        initializeGrid(grid);


        while (true) {

            do {
                int newRow;
                int newColumn;
                displayGrid(grid);

                // Gets user input
                while (true) {
                    cout << "Your move. Enter columns [A, B, or C] follwed by rpw [1, 2, or 3]. =>";
                    cin >> pickColumn >> pickRow;

                    if ((pickColumn == 'A' || pickColumn == 'a' || pickColumn == 'B' || pickColumn == 'b' || pickColumn == 'C' || pickColumn == 'c')) {
                        break;
                    }
                    else {
                        cout << "ERROR: Please select columns [A, B, or C] follwed by row [1, 2, or 3]. =>";
                        cout << endl;
                        continue;
                    }
                }

                // Assigns input with column and row value
                switch (pickColumn) {
                case 'A':
                case 'a':
                    newColumn = 3;
                    break;
                case 'B':
                case 'b':
                    newColumn = 7;
                    break;
                case 'C':
                case 'c':
                    newColumn = 11;
                    break;
                default:
                    cout << "ERROR: Please select columns [A, B, or C] follwed by row [1, 2, or 3]. =>";
                    break;
                }

                switch (pickRow) {
                case 1:
                    newRow = 1;
                    break;
                case 2:
                    newRow = 3;
                    break;
                case 3:
                    newRow = 5;
                    break;
                default:
                    cout << "ERROR: Please select columns [A, B, or C] follwed by row [1, 2, or 3]. =>";
                    break;
                }

                // Checks if X wins
                if (move % 2 == 0) {
                    if (grid[newRow][newColumn] != X && grid[newRow][newColumn] != O) {
                        grid[newRow][newColumn] = X;
                        ++move;
                    }
                    else if (grid[newRow][newColumn] != ' ') {
                        cout << "ERROR: Spot " << pickColumn << pickRow << " is already taken! Try again.";
                    }
                }
                // Checks if O wins
                else if (move % 2 != 0) {
                    if (grid[newRow][newColumn] != X && grid[newRow][newColumn] != O) {
                        grid[newRow][newColumn] = O;
                        ++move;
                    }
                    else if (grid[newRow][newColumn] != ' ') {
                        cout << "ERROR: Spot " << pickColumn << pickRow << " is already taken! Try again.";
                    }
                }
                system("cls");
            } while (!isWin(grid, move));

            // Asks players if they would like to play another game
            cout << "Play another game? 1-Yes  2-No";
            cin >> newGame;
            if (newGame != 1) {
                break;
            }
            initializeGrid(grid);
            move = 0;
            system("clcs");
        }
    }

    return 0;

}
