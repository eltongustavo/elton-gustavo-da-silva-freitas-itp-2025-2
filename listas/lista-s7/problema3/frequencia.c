#include <stdio.h>
#include <string.h>

int main() {
    char entrada[1000];
    printf("Digite o nome do aluno e a frequência: ");
    fgets(entrada, sizeof(entrada), stdin);
    entrada[strcspn(entrada, "\n")] = 0; // remove \n

    // separa nome e frequência
    char *nome = strtok(entrada, " ");
    char *frequencia = strtok(NULL, "");

    if (frequencia == NULL) {
        printf("Entrada inválida. Insira nome e frequência separados por espaço.\n");
        return 1;
    }

    int barras = 0;
    for (int i = 0; frequencia[i] != '\0'; i++) {
        if (frequencia[i] == '/')
            barras++;
    }

    int ocorrencias_nome = 0;
    char *ptr = frequencia;
    while ((ptr = strstr(ptr, nome)) != NULL) {
        ocorrencias_nome++;
        ptr += strlen(nome); // avança após o nome encontrado para evitar sobreposição
    }

    if (barras - ocorrencias_nome != 1) {
        printf("O aluno(a) %s faltou %d vezes", nome, barras - ocorrencias_nome);
    } else {
        printf("O aluno(a) %s faltou %d vez", nome, barras - ocorrencias_nome);
    }

    return 0;
}
