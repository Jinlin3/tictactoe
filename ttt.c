#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

// Global Variables

char board[3][3];
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';
char curPlayer;

// Prototypes

void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
char checkWinner();
void printResult(char);
void switchPlayer();

int main(int argc, char** argv) {
/*  if (argc < 3) {
        printf("error: Not enough arguments for ttt.c\n");
    }
    char* domainName = argv[1];
    char* portNumber = argv[2];
*/

    char winner = ' '; 
    curPlayer = PLAYER1;
    resetBoard();

    while(winner == ' ' && checkFreeSpaces() != 0) {
        printBoard();
        playerMove();
        winner = checkWinner();
        if (winner != ' ' || checkFreeSpaces() == 0) {
            break;
        }
        switchPlayer();
    }
    printBoard();
    printResult(winner);
    return 0;
}

void resetBoard() {

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
    return;
}

void printBoard() {

    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
    return;
}

int checkFreeSpaces() {
    int freeSpaces = 9;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != ' ') {
                freeSpaces--;
            }
        }
    }
    return freeSpaces;
}

void playerMove() {
    int x;
    int y;
    do {

        printf("Enter row number: ");
        scanf("%d", &x);
        x--;

        printf("Enter column number: ");
        scanf("%d", &y);
        y--;

        if (board[x][y] != ' ') {
            printf("Invalid move: position is already taken!\n");
        } else {
            board[x][y] = curPlayer;
            break;
        }

    } while (board[x][y] != ' ');

}

char checkWinner() {
    // Check for row win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            return board[i][0];
        }
    }
    // Check for col win
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            return board[0][i];
        }
    }
    // Check for diag win
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return board[0][2];
    }
    return ' ';
}

void printResult(char winner) {
    if (winner == 'X') {
        printf("PLAYER 1 WINS!\n");
    } else if (winner == 'O') {
        printf("PLAYER 2 WINS\n");
    } else {
        printf("TIE GAME!\n");
    }
    return;
}

void switchPlayer() {
    if (curPlayer == 'X') {
        curPlayer = PLAYER2;
    } else {
        curPlayer = PLAYER1;
    }
    return;
}