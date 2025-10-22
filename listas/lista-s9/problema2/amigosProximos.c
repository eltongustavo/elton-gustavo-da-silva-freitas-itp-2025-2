#include <stdio.h>

int main() {
    int M, x;
    scanf("%d", &M);

    int mat[100][100];
    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++)
            scanf("%d", &mat[i][j]);

    scanf("%d", &x);

    for (int j = 0; j < M; j++) {
        if (j != x && mat[x][j] == 0) {
            for (int k = 0; k < M; k++) {
                if (mat[x][k] && mat[j][k]) {
                    printf("%d ", j);
                    break;
                }
            }
        }
    }
    printf("\n");
    return 0;
}