#include <stdio.h>
#include <ctype.h>

int main(){
    char febre, dorCabeca, dorCorpo, tosse;

    printf("Você tem febre (S/N)? ");
    scanf(" %c", &febre);
    febre = toupper(febre);

    printf("Você tem cor de cabeça? ");
    scanf(" %c", &dorCabeca);
    dorCabeca = toupper(dorCabeca);

    printf("Você tem dor no corpo? ");
    scanf(" %c", &dorCorpo);
    dorCorpo = toupper(dorCorpo);

    printf("Você tem tosse? ");
    scanf(" %c", &tosse);
    tosse = toupper(tosse);

    if(febre == 'S' && dorCabeca == 'S' && dorCorpo == 'S'){
        printf("Seus sintomas são:\n"
        "Febre + Dor de cabeça + Dor no corpo\n"
        "Diagnósitico: Possível febre!\n");
    }
    else if(tosse == 'S' && febre == 'S'){
        printf("Seus sintomas são:\n"
        "Tosse + Febre\n"
        "Diagnósitico: Possível resfriado!\n");
    }
    else if(dorCabeca == 'S'){
        printf("Seus sintomas são:\n"
        "Apenas dor de cabeça\n"
        "Diagnósitico: Possível enxaqueca!\n");
    }
    else if(febre == 'S'){
        printf("Seus sintomas são:\n"
        "Apenas febre\n"
        "Diagnósitico: Consulte um médico!\n");
    }
    else if(febre == 'N' && dorCabeca == 'N' && dorCorpo == 'N' && tosse == 'N'){
        printf("Você não tem sintomas, parece estar bem!\n");
    }
    else{
        printf("Essa combinação de sintomas é desconhecida, procure um médico para melhor avaliação!\n");
    }

}