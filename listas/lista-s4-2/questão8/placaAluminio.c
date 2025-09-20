#include <stdio.h>

int main() {
    int preco1, preco2, quantia;
    printf("Digite o preço do primeiro fornecedor: ");
    scanf("%d", &preco1);

    printf("Digite o preço do segundo fornecedor: ");
    scanf("%d", &preco2);

    printf("Digite a quantia disponível: ");
    scanf("%d\n", &quantia);

    for(int i = 0; i <= 10; i++) {
        for(int j = 0; j <= 10; j++) {
            int gasto = i * preco1 + j * preco2;
            if(gasto <= quantia) {
                int resto = quantia - gasto;
                printf("Comprando %d do primeiro e %d do segundo resta: %d\n", i, j, resto);
            }
        }
        printf("\n");
    }

}
