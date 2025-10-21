#include <stdio.h>
#include <string.h>

int main() {
    char frase[20]  = {};

    printf("Digite . e x para preencher o mapa: ");

    fgets(frase, 20, stdin);

    //verifica se todas as posições são válidas
    for (size_t i = 0; i < strlen(frase) - 1; i++) {
        if(frase[i] != '.' && frase[i] != 'x') {
            printf("Mapa inválido!");
            return 1;
        }
    }

    int indice;
    printf("Informe um índice de 0 a 19: ");
    scanf("%d", &indice);

    if (frase[indice] == 'x') {
        printf("bum!");
    } else {
        //verifica se há bombas nas proximidades

        int contador = 0;

        if (frase[indice - 1] == 'x') {
            contador++;
        }

        if (frase[indice + 1] == 'x') {
            contador++;
        }

        //Mostra quantas bombas existem
        if (contador == 0) {
            printf("0");
        } else if (contador == 1) {
            printf("1");
        } else {
            printf("2");
        }
        
    }

}
