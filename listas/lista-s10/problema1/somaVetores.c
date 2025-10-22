#include <stdio.h>
#include <stdlib.h>

int *alocarVetor(int n) {
    return (int *) malloc(n * sizeof(int)); // aloca vetor dinamicamente
}

int *somaVetores(int *u, int *v, int n1, int n2) {
    if (n1 != n2)
        return NULL; // dimensões diferentes

    int *soma = malloc(n1 * sizeof(int));
    if (!soma) return NULL;

    for (int i = 0; i < n1; i++)
        soma[i] = u[i] + v[i];

    return soma;
}

int main() {
    int n1, n2;
    scanf("%d %d", &n1, &n2);

    int *u = alocarVetor(n1);
    int *v = alocarVetor(n2);

    for (int i = 0; i < n1; i++)
        scanf("%d", &u[i]);

    for (int i = 0; i < n2; i++)
        scanf("%d", &v[i]);

    int *resultado = somaVetores(u, v, n1, n2);

    if (resultado == NULL)
        printf("dimensoes incompativeis\n");
    else {
        for (int i = 0; i < n1; i++)
            printf("%d ", resultado[i]);
        printf("\n");
        free(resultado); // libera vetor resultante
    }

    free(u);
    free(v);
    return 0;
}
