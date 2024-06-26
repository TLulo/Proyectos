#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */

#define CELL_MAX (3 * 3 - 1)

void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < length;i++) printf("................");
    printf("\n");

}

void print_board(char board[3][3])
{
    int cell = 0;

    print_sep(3);
    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 3; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(3);
    }
}

char get_winner(char board[3][3])
{
    char winner = '-';
    //
    //horizontal
    for(unsigned int row = 0; row<3;row++){
        bool ganah = false;
        for(unsigned int column = 1; column<3;column++){
              ganah = board[row][0] == board[row][column];
        }
        if (ganah){
                winner = board[row][0];
        }    
    }//fin horizontales
    //Verticales
    for(unsigned int column = 0; column<3;column++){
        bool ganav = false;
        for(unsigned int row = 1; row<3;row++){
              ganav = board[0][column] == board[row][column];
        }
        if (ganav){
                winner = board[0][column];
        }    
    }//fin vertical
    //Diagonal principal
    bool wpd= false;
    bool wsd = false;
    for (unsigned int i = 0; i < 2;i++){
        wpd = board[i][i] == board[i+1][i+1];
    }
    if (wpd){
                winner = board[0][0];
        }
    int j = 2;
    for (unsigned int i = 0; i<3;i++){
        wsd = board[0][2] == board[i][j];
        j --;
    }
    if (wsd){
                winner = board[0][2];
        }
    //Diagonal secundaria
    
    //Fin diagonales
    //
    return winner;
}

bool has_free_cell(char board[3][3])
{
    bool free_cell=false;
    //
    for(unsigned int fila = 0;fila < 3;fila++){
        for(unsigned columna = 0;columna < 3;columna++){
                free_cell = free_cell || board[fila][columna] == '-'; 
        } 
    }
    //
    return free_cell;
}

int main(void)
{
    printf("TicTacToe [InCoMpLeTo :'(]\n");

    char board[3][3] = {
        { '-', '-', '-' },
        { '-', '-', '-' },
        { '-', '-', '-' }
    };

    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board)) {
        print_board(board);
        printf("\nTurno %c - Elija posición (número del 0 al %d): ", turn,
               CELL_MAX);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / 3;
            int colum = cell % 3;
            if (board[row][colum] == '-') {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board);
            } else {
                printf("\nCelda ocupada!\n");
            }
        } else {
            printf("\nCelda inválida!\n");
        }
    }
    print_board(board);
    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Ganó %c\n", winner);
    }
    return 0;
}
