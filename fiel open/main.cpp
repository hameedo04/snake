#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <iomanip>
#include <random>

using namespace std;

string player1;
string player2;
int pos1 = 1;
int pos2 = 1;

bool checkWin(int pos1, int pos2) {
    bool win = false;
    if (pos1 >= 100 || pos2 >= 100) {
        win = true;
    }
    return win;
}

void printOneMove(string player, int dice, int pos, int newpos, int movenum) {
    cout << player << setfill(' ') << setw(14);
    cout << movenum << setfill(' ') << setw(13);
    cout << pos << setfill(' ') << setw(16);
    cout << dice << setfill(' ') << setw(13);
    cout << newpos << endl;
}

int rollDice() {
    int dice;
    dice = (rand() % 8) + 1;
    return dice;
}

int CheckLadders(int pos) {
    
    if (pos == 7) {
        pos = 19;
    }
    else if (pos == 12) {
        pos = 27;
    }
    else if (pos == 28) {
        pos = 41;
    }
    else if (pos == 39) {
        pos = 50;
    }
    else if (pos == 53) {
        pos = 62;
    }
    else if (pos == 66) {
        pos = 78;
    }
    else if (pos == 75) {
        pos = 91;
    }
    return pos;
}

int CheckChutes(int pos) {
    if (pos == 8) {
        pos = 1;
    }
    if (pos == 13) {
        pos = 3;
    }
    if (pos == 24) {
        pos = 18;
    }
    if (pos == 36) {
        pos = 29;
    }
    if (pos == 51) {
        pos = 37;
    }
    if (pos == 64) {
        pos = 54;
    }
    if (pos == 86) {
        pos = 44;
    }
    return pos;
}

int movePlayer(int pos, int dice) {
    int newpos;
    pos += dice;
    newpos = CheckLadders(pos);
    newpos = CheckChutes(pos);
    
    return newpos;
    
}

void printHeader() {
    cout << "Player     Move Number   Curr Position      Die      New Position" << endl;
    cout << setfill('*') << setw(65) << endl;
}

int main() {
    srand(time(NULL));
    string player1;
    string player2;
    int pos1 = 1;
    int pos2 = 1;
    int roll1;
    int roll2;
    int movenum = 1;
    int newpos1;
    int newpos2;
    
    cout << "Player 1: ";
    cin >> player1;
    cout << endl;
    cout << "Player 2: ";
    cin >> player2;
    cout << endl;
    
    printHeader();
    
    while (!checkWin(pos1, pos2)) {
        roll1 = rollDice();
        newpos1 = movePlayer(pos1, roll1);
        printOneMove(player1, roll1, pos1, newpos1, movenum);
        pos1 = newpos1;
        
        if (pos1 >= 100) {
            break;
        }
        
        roll2 = rollDice();
        newpos2 = movePlayer(pos2, roll2);
        printOneMove(player2, roll2, pos2, newpos2, movenum);
        pos2 = newpos2;
        
        if (pos2 >= 100) {
            break;
        }
        
        cout << setfill('-') << setw(65) << endl;
        
        ++movenum;
    }
    
    if (pos1 >= 100) {
        cout << "The winner is " << player1 << "!" << endl;
    }
    if (pos2 >= 100) {
        cout << "The winner is " << player2 << "!" << endl;
    }
    return 0;
}
