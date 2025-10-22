#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    if ((m < 1 || m > 30) || (n < m || n > 50)) {
        printf("Números inválidos para M e N\n");
        return 1;
    }

    int sorteados[m];
    for (int i = 0; i < m; i++) scanf("%d", &sorteados[i]);

    int aposta[n];
    for (int i = 0; i < n; i++) scanf("%d", &aposta[i]);

    int acertos = 0;
    // compara cada número sorteado com cada número apostado
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (sorteados[i] == aposta[j]) {
                acertos++;
                break; // evita contar duas vezes o mesmo número
            }
        }
    }

    printf("%d\n", acertos);
    return 0;
}
