#include <stdio.h>

int primo(int n) {
    if (n <= 1) return 1;     
    if (n == 2) return 0;        
    if (n % 2 == 0) return 1;     

    for (int i = 3; i*i <= n; i += 2) {
        if (n % i == 0) return 1; 
    }

    return 0; 
}

int main(){

    int aux = 0;

    for (int i = 2; i < 50000; i++){
        if(primo(i) == 0){
            if(primo(i + 2) == 0){
                if(primo(i + 6) == 0){
                    printf("(%d, %d, %d)\n", i, i+2, i+6);
                    i+=7;
                }
            }
        }
    }
    
}