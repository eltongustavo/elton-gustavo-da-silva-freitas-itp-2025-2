#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  

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
    struct livro l; 

    do {
        
        printf("Título: ");
        fgets(l.titulo, sizeof(l.titulo), stdin);
        l.titulo[strcspn(l.titulo, "\n")] = '\0';

        if (strlen(l.titulo) == 0) {
            printf("Erro: o título não pode ser vazio!\n");
            continue;
        }

        
        char anoBuf[16];
        printf("Ano Lançamento: ");
        fgets(anoBuf, sizeof(anoBuf), stdin);
        l.anoLancamento = atoi(anoBuf);

        if (l.anoLancamento <= 0) {
            printf("Erro: o ano deve ser maior que zero!\n");
            continue;
        }

        break; 

    } while (1);

    
    l.nomePessoa[0] = '\0';

    biblioteca[qtdLivros] = l;
    qtdLivros++;

    printf("Livro cadastrado com sucesso!\n\n");
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

void alugarLivro()
{
    char nome[53];
    int opcaoLivro;

    printf("Digite seu nome: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0'; 

    printf("Livros disponíveis: \n");
    printf("[0]. Para sair\n");

    for (int i = 0; i < qtdLivros; i++) {
        printf("[%d]. %s, %d", i+1, biblioteca[i].titulo, biblioteca[i].anoLancamento);
        if (strlen(biblioteca[i].nomePessoa) > 0) {
            printf(" - %s", biblioteca[i].nomePessoa);
        }
        printf("\n");
    }

    printf("\nEscolha qual livro você quer alugar pelo índice: ");
    scanf("%d", &opcaoLivro);
    getchar(); 

    if (opcaoLivro == 0) {
        printf("Saindo... Voltando ao menu principal!\n");
    }
    else if (opcaoLivro > 0 && opcaoLivro <= qtdLivros) {
        if (strlen(biblioteca[opcaoLivro - 1].nomePessoa) == 0) {
            strcpy(biblioteca[opcaoLivro - 1].nomePessoa, nome);
            printf("Alugando livro: %s para %s\n\n", biblioteca[opcaoLivro - 1].titulo, biblioteca[opcaoLivro - 1].nomePessoa);
        }
        else {
            printf("Esse livro já está alugado!\n\n");
        }
    }
    else {
        printf("Opção inválida!\n");
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

        printf("\n");

        if (opcao == 1) {
            cadastrarLivro();
        }
        else if (opcao == 2) {
            alugarLivro();
        }
        else if (opcao == 3) {
            listarLivros();
        }
        else if (opcao == 4) {
            break;
        }
        else {
            printf("Opção Inválida!\n");
        }      
        
    }

    printf("Sistema encerrado!\n");
}