#include <stdio.h>
#include <math.h>

void ordenarLados(int lados[3], int l1, int l2, int l3) {
    lados[0] = l1;
    lados[1] = l2;
    lados[2] = l3;

    for (int i = 0; i < 2; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (lados[i] < lados[j]) {
                int aux = lados[i];
                lados[i] = lados[j];
                lados[j] = aux;
            }
        }
    }
}

int main() {
    int l1, l2, l3;
    int lados[3]; 

    printf("Validador de existência de triângulo, digite os lados.\n");
    
    printf("Lado 1: ");
    scanf("%d", &l1);

    printf("Lado 2: ");
    scanf("%d", &l2);

    printf("Lado 3: ");
    scanf("%d", &l3);

    if (l1 + l2 <= l3 || l1 + l3 <= l2 || l2 + l3 <= l1) {
        printf("Esse triângulo não pode existir!\n");
    } else {
        if (l1 == l2 && l2 == l3) {
            printf("Triângulo Equilátero\n");
        } else if (l1 == l2 || l2 == l3 || l1 == l3) {
            printf("Triângulo Isósceles\n");
        } else {
            printf("Triângulo Escaleno\n");
        }

        ordenarLados(lados, l1, l2, l3);

        if(pow(lados[0], 2) > (pow(lados[1], 2) + pow(lados[2], 2))){
            printf("Obtusângulo\n");
        }
        else if(pow(lados[0], 2) < (pow(lados[1], 2) + pow(lados[2], 2))){
            printf("Acutângulo\n");
        }
        else{
            printf("Retângulo\n");
        }

        return 0;
    }
}
