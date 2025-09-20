#include <stdio.h>
#include <math.h>

int main(){
    int cordX, auxX;
    int cordY, auxY;
    int pontuacao = 0;
    float distEuclidiana, distExtra;

    for(int i = 1; i <= 10; i++){   
        printf("(%d lançamento) Coordenada X: ", i);
        scanf("%d", &cordX);

        printf("(%d lançamento) Coordenada Y: ", i);
        scanf("%d", &cordY);

        distEuclidiana = sqrt(pow(cordX,2) + pow(cordY,2));

        if(distEuclidiana <= 1){
            pontuacao += 10;
        }
        else if(distEuclidiana <= 2){
            pontuacao += 6;
        }
        else if(distEuclidiana <= 3){
            pontuacao += 4;
        }

        if(i > 1){
            distExtra = sqrt(pow(cordX - auxX,2) + pow(cordY - auxY,2));

            if(distExtra <= 1){
                pontuacao += 5;
            }
            else if(distExtra <= 2){
                pontuacao += 3;
            }
            else if(distExtra <= 3){
                pontuacao += 2;
            }
        }

        auxX = cordX;
        auxY = cordY;
    }

    printf("\nPontuação total = %d\n", pontuacao);
}
