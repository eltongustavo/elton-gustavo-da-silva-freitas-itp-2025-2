#include <stdio.h>
#include <string.h>

//no enunciado, fala que o modelo LLLALAA é mercosul, mas no exemplo ATX1M010 tem um algarismo a mais.

int main() {
    char placa[11] = {};

    printf("Digite uma placa: ");
    fgets(placa, 11, stdin);

    //verificação se a placa tem 7 ou 8 caracteres
    if (strlen(placa) - 1 != 7 && strlen(placa) - 1 != 8) {
        printf("Inválido!");
        return 1;
    }

    
    if (placa[3] == '-') {
        //verifica o padrão brasileiro
        
        for (int i = 0; i < 3; i++) {
            if(placa[i] < 65 || placa[i] > 90) {
                printf("Inválido!");
                return 1;
            }
        }

        for (int i = 4; i < 8; i++) {
            if(placa[i] < 48 || placa[i] > 57) {
                printf("Inválido!");
                return 1;
            }      
        }

        printf("Brasileiro");
        
        
    } else if ((placa[3] >= 48 && placa[3] <= 57) && (placa[4] >= 65 && placa[4] <= 90)) {
        //verifica o padrão mercosul

        for (int i = 0; i < 3; i++) {
            if(placa[i] < 65 || placa[i] > 90) {
                printf("Inválido!");
                return 1;
            }
        }

        for (int i = 5; i < 7; i++) {
            if(placa[i] < 48 || placa[i] > 57) {
                printf("Inválido!");
                return 1;
            }      
        }

        printf("Mercosul");

    } else {
        printf("Inválido!");
    }

}