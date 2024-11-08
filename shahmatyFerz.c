// хорошее видео в тему: https://www.youtube.com/watch?v=TrJW0o6C_pw

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
FILE* file_entrance;
FILE* file_exit;

int N, L, K;
int ctrl = 0, kontrol = 0;
int board[24][24] = { 0 };

void setQ(int a, int b) {
    for (int i = 0; i < N; i++) {
        ++board[i][b];
        ++board[a][i];
        if ((b + a - i) >= 0 && (b + a - i) < N) ++board[b + a - i][i];
        if (a - b + i >= 0 && a - b + i < N) ++board[a - b + i][i];
    }
    board[a][b] = -1; //ставим ферзя
}

void remQ(int a, int b) {
    for (int i = 0; i < N; i++) {
        --board[a][i];
        --board[i][b];
        if ((b + a - i) < N && (b + a - i) >= 0) --board[b + a - i][i];
        if (a - b + i < N && a - b + i >= 0) --board[a - b + i][i];
    }
    board[a][b] = 0; // убираем ферзя
}

void printf_from_file_exit() {
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) if (board[i][j] == -1) fprintf(file_exit, "(%d,%d) ", i, j);
    fprintf(file_exit, "\n");
}

void hit(int a) {
    
    for (int j = 0; j < N; j++) {
        if (board[a][j] == 0) {

            ++kontrol;
            setQ(a, j);

            if (kontrol == L) {
                ++ctrl; // +1 решение
                printf_from_file_exit();

            }
            else if (a + 1 < N) hit(a + 1);

            --kontrol;
            remQ(a, j);

        }
    }
    
    if (a + 1 < N) hit(a + 1);
    
}

int main() {

    file_entrance = fopen("input.txt", "r");
    file_exit = fopen("output.txt", "w");

    fscanf(file_entrance, "%d %d %d", &N, &L, &K);

    int x, y;
    for (int i = 0; i < K; i++)
    {
        fscanf(file_entrance, "%d %d", &x, &y);
        setQ(x, y);
    }

    hit(0);

    if (ctrl == 0) fprintf(file_exit, "no solutions");

    fclose(file_exit);
    fclose(file_entrance);
    return 0;
}
