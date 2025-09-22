#include <stdio.h>

int main() {

    int n;

    do {
        printf("Digite o número de questões: ");
        scanf("%d", &n);
    } while (n < 1 || n > 20);

    int gabarito[n];
    int respostaAluno[n];
    int acertos = 0;

    for (int i = 0; i < n; i++) {
        printf("Digite o gabarito da questão %d: ", i+1);
        scanf("%d", &gabarito[i]);
    }

    for (int i = 0; i < n; i++) {
        printf("Digite a resposta do aluno referente a questão %d: ", i+1);
        scanf("%d", &respostaAluno[i]);
    }

    for (int i = 0; i < n; i++) {
        if (gabarito[i] == respostaAluno[i]) {
            acertos += 1;
        }
    }

    printf("%d acertos\n", acertos);
    


    
    

}