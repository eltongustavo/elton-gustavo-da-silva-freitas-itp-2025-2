#include <stdio.h>

int main(){
    printf("DESCONTOS:\n"
        "Até R$ 100 - Sem desconto!\n"
        "De R$ 100,01 a R$ 500,00 - 10%% de desconto\n"
        "De R$ 500,01 a R$ 1000,00 - 15%% de desconto\n"
        "Acima de R$ 1000,00: 20%% de desconto\n");

        float valor;
        float desconto;

        printf("VALOR: ");
        scanf("%f", &valor);

        if(valor < 100.0){
            printf("SEM DESCONTO!\n");
            printf("Valor final: R$ %.2f\n", valor);
        }
        else if(valor > 100 || valor <= 500){
            desconto = 10;
            valor = valor - ((desconto / 100) * valor);
            printf("DESCONTO DE %d%%\n", (int)desconto);
            printf("Valor final: R$ %.2f\n", valor);
        }
        else if(valor > 500 || valor <= 1000){
            desconto = 15;
            valor = valor - ((desconto / 100) * valor);
            printf("DESCONTO DE %d%%\n", (int)desconto);
            printf("Valor final: R$ %.2f\n", valor);
        }
        else if(valor > 1000){
            desconto = 20;
            valor = valor - ((desconto / 100) * valor);
            printf("DESCONTO DE %d%%\n", (int)desconto);
            printf("Valor final: R$ %.2f\n", valor);
        }
}