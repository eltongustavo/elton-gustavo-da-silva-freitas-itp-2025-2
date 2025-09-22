#include <stdio.h>

int main() {
    int m, n;

    do {
        printf("Digite a quantidade do algum e quantas você tem: ");
        scanf("%d %d", &m, &n);
    } while (m > 1000 || m < 1 || n > m || n < 0);

    int figurinhasObtidas[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &figurinhasObtidas[i]);
    }

    int tem[1001] = {0}; 

    for (int i = 0; i < n; i++) {
        tem[figurinhasObtidas[i]] = 1;
    }

    for (int i = 1; i <= m; i++) {
        if (!tem[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
    
}
