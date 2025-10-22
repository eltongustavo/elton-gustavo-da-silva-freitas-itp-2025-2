#include <stdio.h>
#include <string.h>

int main() {
    int chuva[12];
    char *meses[] = {
        "Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho",
        "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"
    };

    for (int i = 0; i < 12; i++)
        scanf("%d", &chuva[i]);

    // Bubble Sort 
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11 - i; j++) {
            if (chuva[j] < chuva[j + 1]) {
                int temp = chuva[j];
                chuva[j] = chuva[j + 1];
                chuva[j + 1] = temp;

                char *tempMes = meses[j];
                meses[j] = meses[j + 1];
                meses[j + 1] = tempMes;
            }
        }
    }

    for (int i = 0; i < 12; i++)
        printf("%s %d\n", meses[i], chuva[i]);

    return 0;
}
