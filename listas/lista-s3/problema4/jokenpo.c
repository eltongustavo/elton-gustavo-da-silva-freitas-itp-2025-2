#include <stdio.h>
#include <ctype.h>

int main(){
    char jogador1;
    char jogador2;
    
    printf("Faça a sua escolha Jogador 1:\n(P) - pedra\n(A) - papel\n(T) - tesoura\n:");
    scanf(" %c", &jogador1);

    printf("Faça a sua escolha Jogador 2:\n(P) - pedra\n(A) - papel\n(T) - tesoura\n:");
    scanf(" %c", &jogador2);

    jogador1 = toupper(jogador1);
    jogador2 = toupper(jogador2);

    if(jogador1 == jogador2){
        printf("j1:%c x j2:%c = empate!\n", jogador1, jogador2);
    }
    else if(jogador1 == 'P' && jogador2 == 'T'){
        printf("j1:%c x j2:%c = vitória para o jogador 1!\n", jogador1, jogador2);
    }
    else if(jogador1 == 'A' && jogador2 == 'P'){
        printf("j1:%c x j2:%c = vitória para o jogador 1!\n", jogador1, jogador2);
    }
    else if(jogador1 == 'T' && jogador2 == 'A'){
        printf("j1:%c x j2:%c = vitória para o jogador 1!\n", jogador1, jogador2);
    }
    else if(jogador1 == 'P' && jogador2 == 'A'){
        printf("j1:%c x j2:%c = vitória para o jogador 2!\n", jogador1, jogador2);
    }
    else if(jogador1 == 'A' && jogador2 == 'T'){
        printf("j1:%c x j2:%c = vitória para o jogador 2!\n", jogador1, jogador2);
    }
    else if(jogador1 == 'T' && jogador2 == 'P'){
        printf("j1:%c x j2:%c = vitória para o jogador 2!\n", jogador1, jogador2);
    }else{
        printf("Alguns dos jogadores não jogou uma opção válida!\n");
    }
    
}