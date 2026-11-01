#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

char board[3][3];

void init_board() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

void print_board() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

int is_valid_move(int row, int col) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3) return 0;
    if (board[row][col] != ' ') return 0;
    return 1;
}

char switch_player(char current) {
    return (current == 'X') ? 'O' : 'X';
}

int main() {
    setlocale(LC_ALL, "Russian");
    init_board();
    char player = 'X';
    int r, c;
    for (int turn = 0; turn < 9; turn++) {
        print_board();
        while (1) {
            printf("Ход игрока %c (строка и столбец 1-3): ", player);
            if (scanf("%d %d", &r, &c) != 2) {
                while (getchar() != '\n');
                printf("Ошибка! Введите два числа.\n");
                continue;
            }
            if (is_valid_move(r - 1, c - 1)) {
                board[r - 1][c - 1] = player;
                break;
            }
            else {
                printf("Неверный ход! Попробуйте еще раз.\n");
            }
        }
        player = switch_player(player);
    }
    print_board();
    return 0;
}