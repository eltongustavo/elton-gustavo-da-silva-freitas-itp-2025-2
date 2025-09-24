#include <stdio.h>
#include <string.h>

struct livro
{
    char titulo[103];
    int anoLancamento;
    char nomePessoa[53];
};

struct livro biblioteca[100]; 
int qtdLivros = 0;

void cadastrarLivro()
{
    do{
        printf("Título: ");
        fgets(biblioteca[qtdLivros].titulo, 101, stdin);
        biblioteca[qtdLivros].titulo[strcspn(biblioteca[qtdLivros].titulo, "\n")] = '\0';

        printf("Ano Lançamento: ");
        scanf("%d", &biblioteca[qtdLivros].anoLancamento);
        getchar();

        strcpy(biblioteca[qtdLivros].nomePessoa, "");
    } while ((sizeof(biblioteca[qtdLivros].titulo) <= 100 && sizeof(biblioteca[qtdLivros].titulo) > 0) || 
            (&biblioteca[qtdLivros].anoLancamento <= 0));
    qtdLivros += 1;
}

void listarLivros()
{
    for (int i = 0; i < qtdLivros; i++) {

        printf("Título: %s\n", biblioteca[i].titulo);
        printf("Ano Lançamento: %d\n", biblioteca[i].anoLancamento);

        if (strcmp(biblioteca[i].nomePessoa, "") == 0){
            printf("Pessoa que alugou: %s\n", "NÃO FOI ALUGADO");
        }
        else{
            printf("Pessoa que alugou: %s\n", biblioteca[i].nomePessoa);
        }

        printf("\n");
    }
}

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
        getchar();

        if (opcao == 1) {
            cadastrarLivro();
        }
        else if (opcao == 2) {
            /* code */
        }
        else if (opcao == 3) {
            listarLivros();
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