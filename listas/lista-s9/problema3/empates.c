#include <stdio.h>

int main() {
    int M;
    scanf("%d", &M);

    int mat[20][20];
    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++)
            scanf("%d", &mat[i][j]);

    int empates = 0;
    for (int i = 0; i < M; i++) {
        for (int j = i + 1; j < M; j++) { // percorre apenas metade da matriz
            if (mat[i][j] == mat[j][i]) {
                empates++;
            }
        }
    }

    printf("%d\n", empates);
    return 0;
}
