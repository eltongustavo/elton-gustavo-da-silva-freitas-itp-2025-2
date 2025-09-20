#include <stdio.h>

int main() {
    int preco1, preco2, quantia;
    printf("Digite o preço do primeiro fornecedor: ");
    scanf("%d", &preco1);

    printf("Digite o preço do segundo fornecedor: ");
    scanf("%d", &preco2);

    printf("Digite a quantia disponível: ");
    scanf("%d", &quantia);

    int melhor_i = 0, melhor_j = 0;
    int menor_resto = quantia;

    for(int i = 0; i <= 10; i++) {
        for(int j = 0; j <= 10; j++) {
            int gasto = i * preco1 + j * preco2;
            if(gasto <= quantia) {
                int resto = quantia - gasto;
                if(resto < menor_resto) {
                    menor_resto = resto;
                    melhor_i = i;
                    melhor_j = j;
                }
            }
        }
    }

    printf("Resta menos comprando %d do primeiro e %d do segundo\n", melhor_i, melhor_j);

    return 0;
}
