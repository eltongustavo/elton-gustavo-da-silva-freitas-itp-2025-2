#include <stdio.h>

int main() {
    int v[10];
    int visitado[10] = {0};

    printf("Digite as sugestoes dos nativos (10 numeros): ");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &v[i]);
    }

    int atual = 0;
    while (1) {
        if (visitado[atual] == 1) {
            printf("Primeira ilha a ser visitada duas vezes: ilha %d\n", atual);
            break;
        }
        else {
            visitado[atual] = 1;
            atual = v[atual];
        }
    }
}
