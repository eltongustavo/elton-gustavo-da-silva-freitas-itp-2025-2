#include <stdio.h>
#include <stdlib.h>

int main() {
    int c1, c2, c3, c4;

    for (c1 = 0; c1 < 4; c1++) {
        for (c2 = 0; c2 < 4; c2++) {
            if (c2 == c1 || abs(c2 - c1) == 1) continue;

            for (c3 = 0; c3 < 4; c3++) {
                if (c3 == c1 || c3 == c2 || abs(c3 - c1) == 2 || abs(c3 - c2) == 1) continue;

                for (c4 = 0; c4 < 4; c4++) {
                    if (c4 == c1 || c4 == c2 || c4 == c3 ||
                        abs(c4 - c1) == 3 || abs(c4 - c2) == 2 || abs(c4 - c3) == 1) continue;

                    for (int i = 0; i < 4; i++) {
                        for (int j = 0; j < 4; j++) {
                            if ((i == 0 && j == c1) || (i == 1 && j == c2) ||
                                (i == 2 && j == c3) || (i == 3 && j == c4))
                                printf("Q ");
                            else
                                printf(". ");
                        }
                        printf("\n");
                    }
                    printf("\n");
                }
            }
        }
    }
}
