#include <stdio.h>

int main(){
    int n;
    printf (" Digite um valor para n: ");
    scanf ("%d", &n );

    int aux = 1;

    for(int i = 1; i <= n; i++) {

        for (int j = 0; j <= n; j++){   
            if(j < i){
                printf("%d ", aux);
                aux++;
            }
        }

        printf ("\n");
    }
}