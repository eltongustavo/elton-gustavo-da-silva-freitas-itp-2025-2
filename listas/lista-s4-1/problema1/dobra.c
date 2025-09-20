#include <stdio.h>

int main(){
    float comprimentoFolha;
    float larguraFolha;
    float larguraBolso;

    printf("Comprimento da folha: ");
    scanf("%f", &comprimentoFolha);

    printf("Largura da folha: ");
    scanf("%f", &larguraFolha);

    printf("Comprimento do bolso: ");
    scanf("%f", &larguraBolso);

    int contador = 0;

    while(comprimentoFolha > larguraBolso && larguraFolha > larguraBolso){
        if(comprimentoFolha > larguraFolha){
            comprimentoFolha /= 2;
        }else if(comprimentoFolha <= larguraFolha){
            larguraFolha /= 2;
        }
        contador += 1;
    }

    printf("%d dobras\n", contador);
}