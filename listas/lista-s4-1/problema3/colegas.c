#include <stdio.h>
#include <stdlib.h>

int main(){
    int numero1;
    int numero2;
    int somaDiv1 = 0;
    int somaDiv2 = 0;

    printf("Digite um número: ");
    scanf("%d", &numero1);

    printf("Digite um número: ");
    scanf("%d", &numero2);

    for (int i = 1; i <= numero1/2; i++){
        if(numero1 % i == 0){
            somaDiv1 = somaDiv1 + i;
        }
    }

    for (int j = 1; j <= numero2/2; j++){
        if(numero2 % j == 0){
            somaDiv2 = somaDiv2 + j;
        }
    }

    if((abs(somaDiv1 - numero2) <= 2) &&  (abs(somaDiv2 - numero1) <= 2)){
        printf("S\n");
    }
    else{
        printf("N\n");
    }



    

   




}