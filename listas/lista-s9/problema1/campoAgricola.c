#include <stdio.h>

int main() {
    int M, N;
    scanf("%d %d", &M, &N);

    int campo[10][10];
    int irrigado[10][10] = {0};

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &campo[i][j]); //leitura de todas as posições

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (campo[i][j] == 2) { //se for um irrigador
                if (i > 0) irrigado[i-1][j] = 1;
                if (i < M-1) irrigado[i+1][j] = 1;
                if (j > 0) irrigado[i][j-1] = 1;
                if (j < N-1) irrigado[i][j+1] = 1;
            }
        }
    }

    int cobertos = 0, nao_cobertos = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (campo[i][j] == 1) { // se é um setor fértil
                if (irrigado[i][j]) cobertos++;
                else nao_cobertos++;
            }
        }
    }

    printf("%d %d\n", cobertos, nao_cobertos);
    return 0;
}
