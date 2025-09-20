#include <stdio.h>

int main(){
    int a, b, divisores;

    printf("Digite o primeiro número (maior): ");
    scanf("%d", &a);

    printf("Digite o segundo número (menor): ");
    scanf("%d", &b);

    if(a > b){
        for (a - 1; a > b; a--){
            
            if(a % 2 == 0 && a != 2){
                continue;
            }
            else{
                divisores = 0;
                for (int i = 2; i <= a/2; i++){
                    if(a % i == 0){
                        divisores = divisores + 1;
                    }
                }
            }
            if(divisores == 0){
                printf("%d\n", a);
            }
        }
    }
    else{
        printf("A deve ser maior que B");
    }

}

