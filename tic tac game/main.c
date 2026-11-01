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

int check_win(char p) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == p && board[i][1] == p && board[i][2] == p) return 1;
        if (board[0][i] == p && board[1][i] == p && board[2][i] == p) return 1;
    }
    if (board[0][0] == p && board[1][1] == p && board[2][2] == p) return 1;
    if (board[0][2] == p && board[1][1] == p && board[2][0] == p) return 1;
    return 0;
}

int check_draw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ') return 0;
    return 1;
}

int ask_restart() {
    int choice;
    printf("Сыграть еще раз? (1 - Да, 0 - Нет): ");
    if (scanf("%d", &choice) != 1) {
        while (getchar() != '\n');
        return 0;
    }
    return choice == 1;
}

int main() {
    setlocale(LC_ALL, "Russian");
    do {
        init_board();
        char player = 'X';
        int r, c;
        while (1) {
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
            if (check_win(player)) {
                print_board();
                printf("Игрок %c победил!\n", player);
                break;
            }
            if (check_draw()) {
                print_board();
                printf("Ничья!\n");
                break;
            }
            player = switch_player(player);
        }
    } while (ask_restart());
    return 0;
}