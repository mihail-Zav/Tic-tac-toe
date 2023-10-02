#include <string>
#include <iostream>
#include <array>

using namespace std;

void runGame(int array[3][3]);
void drawGame(int array[3][3]);
void receiveInput(int array[3][3]);
bool validateInput(int array[3][3], int row, int column);
bool isFull(int array[3][3]);
string getWinner(int array[3][3]);

int main() {
    int array[3][3];
    runGame(array);
    return 0;
}

void drawGame(int array[3][3]) {
    for (int i = 0; i < 3; i++) {
        cout << '|';
        for (int elem : array[i]) {
            if (elem == 11) { cout << "X"; }
            else if (elem == 10) { cout << "O"; }
            else { cout << " "; }
            cout << '|';
        }
        cout << endl;
        cout << "-------" << endl;
    }
}

void receiveInput(int array[3][3]) {
    int row, column;
    do {
        cout << "Please enter a valid position:" << endl;
        cin >> row >> column;
    } while (validateInput(array, row, column) == false);

    char symbol;

    do {
        cout << "Please enter the symbol you want to place:" << endl;
        cin >> symbol;
    } while (symbol != 'X' && symbol != 'O' && symbol != 'x' && symbol != 'o');

    if (symbol == 'X' || symbol == 'x') { array[row][column] = 11; }
    else { array[row][column] = 10; }
}

bool validateInput(int array[3][3], int row, int column) {

    if (row >= 0 && row <= 2 && column >= 0 && column <= 2) {
        if (array[row][column] != 10 && array[row][column] != 11) { return true; }
    }
    return false;
}



bool isFull(int array[3][3]) {

    bool full = true;
    for (int i = 0; i <= 2; i++) {
        for (int cell : array[i]) {
            if (cell != 11 && cell != 10) { full = false; }
        }
    }
    return full;
}



string getWinner(int array[3][3]) {
    if ((array[0][0] == 10 && array[0][1] == 10 && array[0][2] == 10) || (array[1][0] == 10 && array[1][1] == 10 && array[1][2] == 10) || (array[2][0] == 10 && array[2][1] == 10 && array[2][2] == 10) || (array[0][0] == 10 && array[1][0] == 10 && array[2][0] == 10) || (array[0][1] == 10 && array[1][1] == 10 && array[2][1] == 10) || (array[0][2] == 10 && array[1][2] == 10 && array[2][2] == 10) || (array[0][0] == 10 && array[1][1] == 10 && array[2][2] == 10) || (array[0][2] == 10 && array[1][1] == 10 && array[2][2] == 10)) { return "O"; }

    else if ((array[0][0] == 11 && array[0][1] == 11 && array[0][2] == 11) || (array[1][0] == 11 && array[1][1] == 11 && array[1][2] == 11) || (array[2][0] == 11 && array[2][1] == 11 && array[2][2] == 11) || (array[0][0] == 11 && array[1][0] == 11 && array[2][0] == 11) || (array[0][1] == 11 && array[1][1] == 11 && array[2][1] == 11) || (array[0][2] == 11 && array[1][2] == 11 && array[2][2] == 11) || (array[0][0] == 11 && array[1][1] == 11 && array[2][2] == 11) || (array[0][2] == 11 && array[1][1] == 11 && array[2][2] == 11)) { return "X"; }

    else { return "None"; }
}



void runGame(int array[3][3]) {

    drawGame(array);
    receiveInput(array);
    if (getWinner(array) != "None") {
        if (getWinner(array) == "O") { cout << "O is the winner"; }
        else { cout << "X is the winner"; }
    }

    else if (isFull(array)) { cout << "Game over, the board is full."; }
    else runGame(array);

}