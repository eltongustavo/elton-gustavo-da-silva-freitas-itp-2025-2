#include <stdio.h>

struct livro
{
    char titulo[101];
    int anoLancamento;
    char nomePessoa[51];
};


int main() {
    int opcao;
    while (1) {
        printf("SISTEMA DA BIBLIOTECA\n\n");
        printf("1. Cadastrar Livros\n");
        printf("2. Alugar Livros\n");
        printf("3. Listar Todos os Livros\n");
        printf("4. Sair\n");

        printf("\nSelecione uma das opções acima (1, 2, 3, 4): ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            /* code */ 
        }
        else if (opcao == 2) {
            /* code */
        }
        else if (opcao == 3) {
            /* code */
        }
        else if (opcao == 4) {
            break;
        }
        else {
            printf("Opção Inválida!");
        }      
        
    }

    printf("Sistema encerrado!\n");
}