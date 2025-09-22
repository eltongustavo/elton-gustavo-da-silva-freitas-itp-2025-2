#include <stdio.h>

int main() {
    int n;
    printf("Digite a quantidade de pontos: ");
    scanf("%d", &n);

    int v[n];
    printf("Digite as alturas: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    int maior = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] > maior) {
            maior = v[i];
        }
    }

    int p1 = -1, p2 = -1;
    for (int i = 0; i < n; i++) {
        if (v[i] == maior) {
            if (p1 == -1) {
                p1 = i;
            } 
            else { 
                p2 = i; break; 
            }
        }
    }

    printf("Comprimento da ponte: %d\n", p2 - p1);

}
