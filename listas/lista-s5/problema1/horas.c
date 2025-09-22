#include <stdio.h>

void imprimirHorario(int h, int m, int formato) {

    while(m >= 60){
        m -= 60;
        h++;
    }
    while(m < 0){
        m += 60;
        h--;
    }

    while (h >= 24) h -= 24;
    while (h < 0) h += 24;

    if(formato == 0){ 
        printf("%02d:%02d\n", h, m);
    } 
    else{ 
        int h12 = h % 12;
        if (h12 == 0) h12 = 12; 

        if (h < 12) {
            printf("%02d:%02d AM\n", h12, m);
        } 
        else {
            printf("%02d:%02d PM\n", h12, m);
        }
    }
}

int main() {
    int h, m, formato;
    printf("Digite o horário do começo da ronda (h min formato): ");
    scanf("%d %d %d", &h, &m, &formato);

    imprimirHorario(h, m, formato);
    imprimirHorario(h + 1, m, formato);         
    imprimirHorario(h + 2, m + 10, formato);    
    imprimirHorario(h + 4, m + 40, formato);    
    imprimirHorario(h + 12, m + 5, formato);     
}
