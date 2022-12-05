#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <iomanip>
#include <random>
#include <windows.h>

using namespace std;

const int rows = 6;
const int columns = 13;
const char X = 'X';
const char O = 'O';

void readInitialGrid(char grid[][columns], ifstream& inFS) {
    int i;
    int j;
    int move;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                inFS >> move;
                grid[i][j] = move;
            }
        }
}

void initializeGrid(char grid[][columns]) {
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

void displayGrid(char grid[][columns]) {
    int i;
    int j;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cout << grid[i][j];
        }
        cout << endl;
    }
}

bool isWin(char grid[][columns], int moves) {
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
    else if (grid[1][11] == grid[3][7] && grid[3][7] == grid [5][3] && grid[1][11] != ' ') {
        displayGrid(grid);
        cout << "The winner is " << grid[1][11] << "'s!" << endl;
        return true;
    }
    else {
        return false;
    }
}

int main() {
    char grid[rows][columns];
    int move = 0;
    int pickRow;
    char pickColumn;
    int newGame;
    
    ifstream infile;
    
    infile.open("pgrm7-input.txt");
    
    if (!infile) {
        cout << "Error: File cannot open" << endl;
        return 1;
    }
    if (infile.is_open()) {
        readInitialGrid(grid, infile);
        initializeGrid(grid);
        
        
        while (true) {
            while (!isWin(grid, move)) {
                int newRow;
                int newColumn;
                displayGrid(grid);
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
                switch(pickRow) {
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
                
                
                if (move % 2 == 0) {
                    if (grid[newRow][newColumn] != X && grid[newRow][newColumn] != O) {
                        grid[newRow][newColumn] = X;
                        ++move;
                    }
                    else if (grid[newRow][newColumn] != ' ') {
                        cout << "ERROR: Spot " << pickColumn << pickRow << " is already taken! Try again.";
                    }
                }
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
            }
            cout << "Play another game? 1-Yes  2-No" ;
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
