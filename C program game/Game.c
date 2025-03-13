#include <stdio.h>

char board[3][3]; 

void initBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---+---+---\n");
    }
    printf("\n");
}

char checkWin() {
    // Rows & Columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0];
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i];
    }
    
   
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2];

    return ' '; 


int isDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ') return 0;
    return 1; // Board is full
}


void playGame() {
    int row, col;
    char player = 'X'; 

    initBoard();

    while (1) {
        printBoard();
        printf("Player %c, enter row (1-3) and column (1-3): ", player);
        scanf("%d %d", &row, &col);

        row--; col--; 

        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            printf("Invalid move! Try again.\n");
            continue;
        }

        
        board[row][col] = player;

        
        char winner = checkWin();
        if (winner != ' ') {
            printBoard();
            printf("Player %c wins!\n", winner);
            break;
        }

        
        if (isDraw()) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }

        
        player = (player == 'X') ? 'O' : 'X';
    }
}

int main() {
    printf("Welcome to Tic-Tac-Toe!\n");
    playGame();
    return 0;
}
