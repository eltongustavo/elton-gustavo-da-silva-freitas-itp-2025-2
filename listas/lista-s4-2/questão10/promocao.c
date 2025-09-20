#include <stdio.h>

int main() {
    float p, q;
    printf("Digite o preco de venda p: ");
    scanf("%f", &p);
    printf("Digite o preco de producao q: ");
    scanf("%f", &q);

    int melhor_x = 0, melhor_y = 0;
    float melhor_razao = 0.0;

    for(int x = 2; x <= 10; x++) {
        for(int y = 1; y < x; y++) {
            float receita = y * p;
            float custo = x * q;
            if(receita >= custo) {
                float razao = (float)x / y;
                if(razao > melhor_razao) {
                    melhor_razao = razao;
                    melhor_x = x;
                    melhor_y = y;
                }
            }
        }
    }

    if(melhor_x > 0) {
        printf("A melhor promocao é: leve %d pague %d\n", melhor_x, melhor_y);
    } else {
        printf("Nao existe promoção possivel sem prejuízo\n");
    }

}
