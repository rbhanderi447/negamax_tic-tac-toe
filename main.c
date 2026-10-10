#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>


int opponent(int player){
    if(player == 1) return 2;
    else return 1;
}


void printBoard(int board[3][3]) {
    printf("\n");
    printf("       1     2     3\n");
    printf("    +-----+-----+-----+\n");

    for (int i = 0; i < 3; i++) {
        printf("  %d |", i + 1);

        for (int j = 0; j < 3; j++) {
            printf("  %c  |", (char)board[i][j]);
        }

        printf("\n");
        printf("    +-----+-----+-----+\n");
    }

    printf("\n");
}

bool checkWin(int board[3][3], int player){
    char symbol = (player == 1) ? 'X' : 'O';

    for(int i = 0; i < 3; i++){
        if(board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) return true;
        if(board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) return true;
    }

    if(board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) return true;
    if(board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) return true;

    return false;
}

bool draw(int board[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == ' '){
                return false;
            }
        }
    }
    return true;
    
}


int negamax(int board[3][3], int player, int alpha, int beta){
    if(checkWin(board, opponent(player))) return -1;
    if(checkWin(board, player)) return 1;
    if(draw(board)) return 0;

    int score = -1;
    int bestScore = -2;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == ' '){
                if(player == 1){board[i][j] = 'X';}
                else{board[i][j] = 'O';}
                score = -negamax(board, opponent(player), -beta, -alpha);
                if(score > bestScore){
                    bestScore = score;
                }
                if(bestScore > alpha){
                    alpha = bestScore;
                }
                board[i][j] = ' ';
                if(alpha >= beta){
                    return bestScore;
                }
                
            }
        }
    }

    return bestScore;

}

int bestMove(int board[3][3], int player, int theMove[2]){
    int bestScore = -2;
    int score = -1;
    int bMove[2] = {0, 0};

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == ' '){
                if(player == 1){board[i][j] = 'X';}
                else{board[i][j] = 'O';}
                score = -negamax(board, opponent(player), -2, 2);
                if(score > bestScore){
                    bestScore = score;
                    bMove[0] = i;
                    bMove[1] = j;
                }
                board[i][j] = ' ';
            }
        }
    }
    theMove[0] = bMove[0];
    theMove[1] = bMove[1];
    return 0;
}

int main(){

    srand(time(NULL));

    int board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };


    printf("Welcome to Tic Tac Toe!\n");
    

    int firstMover = rand() % 2 + 1;

    if(firstMover == 1){
        printf("You go first!\n");
    }
    else{
        printf("The computer goes first!\n");
    }

    int currentPlayer = firstMover;
    int player = currentPlayer;


    while(true){
        if(currentPlayer == 1){
            printBoard(board);
            int row, col;
            if (scanf("%d %d", &row, &col) != 2) {
                printf("Invalid input! Enter numbers 1 to 3.\n");
                continue;
            }

            if(row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row - 1][col - 1] == ' '){
                board[row - 1][col - 1] = 'X';
            } else {
                printf("Invalid move! Try again.\n");
                continue;
            }
        }
        else{
            int move[2];
                
            bestMove(board, 2, move);
            board[move[0]][move[1]] = 'O';

            printBoard(board);

        }
        currentPlayer = opponent(currentPlayer);

        if(checkWin(board, 1)){
            printf("You win!\n");
            break;
        }else if(checkWin(board, 2)){
            printf("You lose!\n");
            break;
        }
        else if(draw(board)){
            printf("Draw!\n");
            break;
        }

    }



    return 0;
}
