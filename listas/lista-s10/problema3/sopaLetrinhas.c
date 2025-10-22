#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *misturar(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int tam = len1 + len2;

    char *resultado = malloc(tam + 1);
    if (!resultado) return NULL;

    int i = 0, j = 0, k = 0;
    // Alterna letras enquanto houver em ambas
    while (i < len1 && j < len2) {
        resultado[k++] = str1[i++];
        resultado[k++] = str2[j++];
    }
    // Adiciona o restante da string maior
    while (i < len1) resultado[k++] = str1[i++];
    while (j < len2) resultado[k++] = str2[j++];

    resultado[k] = '\0';
    return resultado;
}

int main() {
    char str1[101], str2[101];

    fgets(str1, sizeof(str1), stdin);
    fgets(str2, sizeof(str2), stdin);

    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    char *resultado = misturar(str1, str2);
    if (resultado) {
        printf("%s\n", resultado);
        free(resultado); // libera memória alocada
    }

    return 0;
}
