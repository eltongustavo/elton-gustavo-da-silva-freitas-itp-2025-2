#include <stdio.h>
#include <stdlib.h>

int *buscaNoVetor(int *v, int n, int valor, int *maior, int *qtd) {
    *qtd = 0;
    *maior = v[0];

    for (int i = 0; i < n; i++) {
        if (v[i] == valor) (*qtd)++;
        if (v[i] > *maior) *maior = v[i];
    }

    if (*qtd == 0) {
        return NULL; //caso não ache nada
    }      

    int *indices = malloc((*qtd) * sizeof(int)); // aloca vetor dinamicamente
    if (!indices)
        return NULL;

    int j = 0;
    for (int i = 0; i < n; i++)
        if (v[i] == valor)
            indices[j++] = i;

    return indices; // retorna endereço base do vetor de índices
}

int main() {
    int n;
    scanf("%d", &n);

    int *v = malloc(n * sizeof(int)); // aloca vetor dinamicamente
    if (!v) return 1;

    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    int valor;
    scanf("%d", &valor);

    int qtd, maior;
    int *indices = buscaNoVetor(v, n, valor, &maior, &qtd);

    if (indices == NULL)
        printf("0\n"); // nenhuma ocorrência
    else {
        printf("%d\n", qtd);
        for (int i = 0; i < qtd; i++)
            printf("%d ", indices[i]);
        printf("\n");
        free(indices); // libera memória do vetor de índices
    }

    free(v); // libera memória do vetor principal
    return 0;
}
