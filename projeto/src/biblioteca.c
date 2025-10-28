#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Estrutura do livro
struct livro {
    char titulo[103];
    char autor[103];
    int anoLancamento;
    char nomePessoa[53];
};

// Vetor dinâmico de livros
struct livro *biblioteca = NULL;
int qtdLivros = 0;      // Quantidade de livros cadastrados
int capacidade = 0;     // Capacidade atual do vetor

// --- Constantes de largura das colunas ---
#define MAX_TITLE 36
#define MAX_AUTHOR 20
#define MAX_YEAR 10
#define MAX_ALUGADO 20

// Redimensiona o vetor da biblioteca dinamicamente conforme necessário
void redimensionarBiblioteca() {
    if (qtdLivros >= capacidade) {
        capacidade = (capacidade == 0) ? 5 : capacidade * 2;
        biblioteca = realloc(biblioteca, capacidade * sizeof(struct livro));
        if (!biblioteca) {
            printf("Erro de alocação de memória!\n");
            exit(1);
        }
    }
}

// Imprime uma linha separadora genérica
void imprimirLinha() {
    for (int i = 0; i < 60; i++) {
        printf("-");
    }
    printf("\n");
}

// Copia uma string com truncamento e adiciona "..." se ultrapassar o limite
void trunc_copy(const char *src, char *dest, size_t max_len) {
    size_t src_len = strlen(src);
    if (src_len <= max_len) {
        strcpy(dest, src);
    } else {
        if (max_len > 3) {
            strncpy(dest, src, max_len - 3);
            strcpy(dest + max_len - 3, "...");
        } else {
            strncpy(dest, src, max_len);
            dest[max_len] = '\0';
        }
    }
}

// Exibe todos os livros cadastrados em formato de tabela
void listarLivros() {
    if (qtdLivros == 0) {
        printf("Nenhum livro cadastrado.\n\n");
        return;
    }

    // Aloca a matriz de strings dinamicamente (qtdLivros x 4 colunas)
    char ***lista = malloc(qtdLivros * sizeof(char **));
    if (!lista) {
        printf("Erro de memória!\n");
        return;
    }

    // Aloca espaço para cada célula da tabela
    for (int i = 0; i < qtdLivros; i++) {
        lista[i] = malloc(4 * sizeof(char *));
        lista[i][0] = malloc(MAX_TITLE + 1);
        lista[i][1] = malloc(MAX_AUTHOR + 1);
        lista[i][2] = malloc(MAX_YEAR + 1);
        lista[i][3] = malloc(MAX_ALUGADO + 1);
    }

    // Preenche a matriz com os dados truncados
    for (int i = 0; i < qtdLivros; i++) {
        trunc_copy(biblioteca[i].titulo, lista[i][0], MAX_TITLE);
        trunc_copy(biblioteca[i].autor, lista[i][1], MAX_AUTHOR);

        char anoBuf[16];
        sprintf(anoBuf, "%d", biblioteca[i].anoLancamento);
        trunc_copy(anoBuf, lista[i][2], MAX_YEAR);

        if (strcmp(biblioteca[i].nomePessoa, "") == 0) {
            trunc_copy("Não foi alugado", lista[i][3], MAX_ALUGADO);
        } else {
            trunc_copy(biblioteca[i].nomePessoa, lista[i][3], MAX_ALUGADO);
        }
    }

    // Cabeçalho da tabela
    printf("\n%-3s | %-37s | %-20s | %-10s | %-20s\n",
           "ID", "Título", "Autor", "Ano", "Alugado para");
    printf("-----------------------------------------------------------------------------------------------------\n");

    // Linhas da tabela
    for (int i = 0; i < qtdLivros; i++) {
        printf("%-3d | %-36s | %-20s | %-10s | %-20s\n",
               i + 1, lista[i][0], lista[i][1], lista[i][2], lista[i][3]);
    }

    printf("-----------------------------------------------------------------------------------------------------\n\n");

    // Libera toda a memória alocada
    for (int i = 0; i < qtdLivros; i++) {
        for (int j = 0; j < 4; j++) {
            free(lista[i][j]);
        }
        free(lista[i]);
    }
    free(lista);
}

// Limpa o buffer de entrada (stdin)
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

// Cadastra um novo livro no sistema
void cadastrarLivro() {
    struct livro l;

    while (1) {
        printf("Título: ");
        fgets(l.titulo, sizeof(l.titulo), stdin);
        l.titulo[strcspn(l.titulo, "\n")] = '\0';
        if (strlen(l.titulo) == 0) {
            printf("Erro: o título não pode ser vazio!\n");
            continue;
        }

        printf("Autor: ");
        fgets(l.autor, sizeof(l.autor), stdin);
        l.autor[strcspn(l.autor, "\n")] = '\0';
        if (strlen(l.autor) == 0) {
            printf("Erro: o autor não pode ser vazio!\n");
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

        break; // Sai do loop se todas as validações passarem
    }

    l.nomePessoa[0] = '\0'; // Nenhum aluguel no início
    redimensionarBiblioteca();
    biblioteca[qtdLivros] = l;
    qtdLivros++;

    printf("Livro cadastrado com sucesso!\n\n");
}

// Permite que um usuário alugue um livro disponível
void alugarLivro() {
    if (qtdLivros == 0) {
        printf("Nenhum livro disponível para aluguel.\n\n");
        return;
    }

    char nome[53];
    int opcaoLivro;

    printf("Digite seu nome: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    printf("Livros disponíveis: \n[0]. Para sair\n");
    for (int i = 0; i < qtdLivros; i++) {
        printf("[%d]. %s - %s, %d", i + 1, biblioteca[i].titulo,
               biblioteca[i].autor, biblioteca[i].anoLancamento);
        if (strlen(biblioteca[i].nomePessoa) > 0) {
            printf(" - %s", biblioteca[i].nomePessoa);
        }
        printf("\n");
    }

    printf("\nEscolha qual livro você quer alugar pelo índice: ");
    if (scanf("%d", &opcaoLivro) != 1) {
        printf("Entrada inválida!\n\n");
        limparBufferEntrada();
        return;
    }
    limparBufferEntrada();

    if (opcaoLivro == 0) {
        printf("Saindo... Voltando ao menu principal!\n");
    } else if (opcaoLivro > 0 && opcaoLivro <= qtdLivros) {
        if (strlen(biblioteca[opcaoLivro - 1].nomePessoa) == 0) {
            strcpy(biblioteca[opcaoLivro - 1].nomePessoa, nome);
            printf("Alugando livro: %s para %s\n\n",
                   biblioteca[opcaoLivro - 1].titulo,
                   biblioteca[opcaoLivro - 1].nomePessoa);
        } else {
            printf("Esse livro já está alugado!\n\n");
        }
    } else {
        printf("Opção inválida!\n");
    }
}

// Busca livros pelo nome do título ou autor (sem diferenciação de maiúsculas/minúsculas)
void buscarLivro() {
    if (qtdLivros == 0) {
        printf("Nenhum livro cadastrado.\n\n");
        return;
    }

    char termo[103];
    printf("Digite parte do título ou autor para buscar: ");
    fgets(termo, sizeof(termo), stdin);
    termo[strcspn(termo, "\n")] = '\0';

    // Converte o termo de busca para minúsculo
    for (int i = 0; termo[i]; i++) {
        termo[i] = tolower((unsigned char)termo[i]);
    }

    int encontrados = 0;
    imprimirLinha();

    // Procura correspondências parciais no título ou autor
    for (int i = 0; i < qtdLivros; i++) {
        char tituloLower[103], autorLower[103];
        strcpy(tituloLower, biblioteca[i].titulo);
        strcpy(autorLower, biblioteca[i].autor);

        for (int j = 0; tituloLower[j]; j++) {
            tituloLower[j] = tolower((unsigned char)tituloLower[j]);
        }
        for (int j = 0; autorLower[j]; j++) {
            autorLower[j] = tolower((unsigned char)autorLower[j]);
        }

        if (strstr(tituloLower, termo) || strstr(autorLower, termo)) {
            printf("Título: %s\nAutor: %s\nAno Lançamento: %d\nPessoa que alugou: %s\n\n",
                   biblioteca[i].titulo, biblioteca[i].autor,
                   biblioteca[i].anoLancamento,
                   (strlen(biblioteca[i].nomePessoa) == 0)
                       ? "NÃO FOI ALUGADO"
                       : biblioteca[i].nomePessoa);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("Nenhum livro encontrado com esse termo.\n\n");
    }

    imprimirLinha();
}

// Função principal do programa
int main() {
#ifdef _WIN32
    system("chcp 65001 > nul"); // Garante UTF-8 no Windows
#endif

    int opcao;
    while (1) {
        printf("SISTEMA DA BIBLIOTECA\n\n");
        printf("1. Cadastrar Livros\n");
        printf("2. Alugar Livros\n");
        printf("3. Listar Todos os Livros\n");
        printf("4. Buscar Livros\n");
        printf("5. Sair\n");
        printf("\nSelecione uma das opções acima (1, 2, 3, 4, 5): ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada inválida!\n\n");
            limparBufferEntrada();
            continue;
        }
        limparBufferEntrada();
        printf("\n");

        switch (opcao) {
            case 1: {
                cadastrarLivro();
                break;
            }
            case 2: {
                alugarLivro();
                break;
            }
            case 3: {
                listarLivros();
                break;
            }
            case 4: {
                buscarLivro();
                break;
            }
            case 5: {
                free(biblioteca);
                printf("Sistema encerrado!\n");
                return 0;
            }
            default: {
                printf("Opção Inválida!\n");
                break;
            }
        }
    }

    return 0;
}
