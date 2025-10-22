#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int largada[n], chegada[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &largada[i]); // ordem de largada

    for (int i = 0; i < n; i++)
        scanf("%d", &chegada[i]); // ordem de chegada

    int posicaoLargada[21]; // guarda posição inicial de cada piloto
    for (int i = 0; i < n; i++)
        posicaoLargada[largada[i]] = i + 1;

    int melhorPiloto = 0;
    int maiorGanho = 0;

    for (int i = 0; i < n; i++) {
        int piloto = chegada[i];
        int posFinal = i + 1;
        int ganho = posicaoLargada[piloto] - posFinal; // diferença entre largada e chegada

        if (ganho > maiorGanho) {
            maiorGanho = ganho;
            melhorPiloto = piloto;
        } else if (ganho == maiorGanho && maiorGanho > 0) {
            // empate entre dois pilotos
            melhorPiloto = 0;
        }
    }

    if (maiorGanho <= 0 || melhorPiloto == 0)
        printf("empate\n");
    else
        printf("%d\n", melhorPiloto);

    return 0;
}
