#include <stdio.h>
#include <math.h>

float altura(float x, float y) {
    return sinf(cosf(y) + x) + cosf(y + sinf(x));
}

int seguro(float x, float y) {
    float pontos[5][2] = {
        {x, y},
        {x+0.2f, y+0.2f},
        {x-0.2f, y-0.2f},
        {x+0.2f, y-0.2f},
        {x-0.2f, y+0.2f}
    };

    for(int i = 0; i < 5; i++){
        float h = altura(pontos[i][0], pontos[i][1]);
        if(h < 0.0f || h > 2.0f){
            return 0;
        }
    }
    return 1;
}

int main() {
    float x, y;
    printf("Coordenadas (x, y): ");
    scanf("%f %f", &x, &y);

    if(!seguro(x, y)){
        printf("troque de coordenada\n");
    } 
    else{
        int vizinhosSeguros = 0;
        if (seguro(x + 2.0f, y)) vizinhosSeguros++;
        if (seguro(x - 2.0f, y)) vizinhosSeguros++;
        if (seguro(x, y + 2.0f)) vizinhosSeguros++;
        if (seguro(x, y - 2.0f)) vizinhosSeguros++;

        if(vizinhosSeguros <= 1){
            printf("inseguro\n");
        } 
        else if(vizinhosSeguros <= 3) {
            printf("relativamente seguro\n");
        } 
        else {
            printf("seguro\n");
        }
    }

}
