#include <stdio.h>
#include <math.h>

int main(){
    float coordenadaAranha[2]; 
    float comprimentoTeia;
    int quantidadeAlvos;

    printf("Coordenada inicial do homem aranha (x y): ");
    scanf("%f %f", &coordenadaAranha[0], &coordenadaAranha[1]);

    printf("Comprimento da teia: ");
    scanf("%f", &comprimentoTeia);

    printf("Quantidade de alvos: ");
    scanf("%d", &quantidadeAlvos);

    float alvos[quantidadeAlvos][2];

    for(int i = 0; i < quantidadeAlvos; i++){
        printf("Alvo %d (x y): ", i+1);
        scanf("%f %f", &alvos[i][0], &alvos[i][1]);
    }

    printf("\n");

    int aux = 0;

    for (int i = 0; i < quantidadeAlvos; i++){
        float distancia;

        distancia = sqrt( pow(alvos[i][0] - coordenadaAranha[0], 2) + pow(alvos[i][1] - coordenadaAranha[1], 2));
        printf("%f \n", distancia);

        if(distancia > comprimentoTeia){
            break;
        }else{
            aux = aux + 1;
            coordenadaAranha[0] = 2 * alvos[i][0] - coordenadaAranha[0];
        }     
    }

    printf("\n");
    printf("%d | %d\n", aux, quantidadeAlvos);

    if(aux == quantidadeAlvos){
        printf("S\n");
    }else{
        printf("N\n");
    }
    
    return 0;
}
