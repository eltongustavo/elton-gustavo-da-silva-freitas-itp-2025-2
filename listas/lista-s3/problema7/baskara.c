#include <stdio.h>
#include <math.h>

int main(){
    int a, b, c, delta;
    
    printf("Digite o valor de a: ");
    scanf("%d", &a);

    printf("Digite o valor de b: ");
    scanf("%d", &b);

    printf("Digite o valor de c: ");
    scanf("%d", &c);

    delta = pow(b, 2) - 4 * a * c;

    if(delta < 0){
        printf("Essa equação não tem raízes reais");
    }
    else if(delta == 0){
        printf("Essa equação tem duas raízes reais iguais");
        float x = -b / (2*a);
        printf("Raíz única da equação: %f", x);
    }else{
        printf("Essa equação tem duas raízes reais\n");
        float x1 = (float)((-b + sqrt(delta)) / 2 * a);
        float x2 = (float)((-b - sqrt(delta)) / 2 * a);

        printf("X1: %.1f\n", x1);
        printf("X1: %.1f\n", x2);
    }




}