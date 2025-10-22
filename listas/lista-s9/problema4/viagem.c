#include <stdio.h>

int main() {
    int M;
    scanf("%d", &M);

    int mat[10][10];
    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++)
            scanf("%d", &mat[i][j]);

    int X, Z;
    scanf("%d %d", &X, &Z);

    int menorCusto = mat[X][Z];
    int intermed = -1;  // -1 significa sem cidade intermediária

    for (int Y = 0; Y < M; Y++) {
        if (Y != X && Y != Z) {
            int custo = mat[X][Y] + mat[Y][Z];
            if (custo < menorCusto) {
                menorCusto = custo;
                intermed = Y;
            }
        }
    }

    if (intermed == -1) {
        printf("%d-%d R$%d\n", X, Z, menorCusto);
    } else {
        printf("%d-%d-%d R$%d\n", X, intermed, Z, menorCusto);
    }

    return 0;
}
