// URI 1172 - C //
// https://www.beecrowd.com.br/judge/pt/problems/view/1172 //

#include <stdio.h>

int main() {
    int X[10], i;
    
    for (i = 0; i < 10; i++) {
        scanf("%d", &X[i]);
    }

    // Substituição dos valores negativos e nulos por 1
    for (i = 0; i < 10; i++) {
        if (X[i] <= 0) {
            X[i] = 1;
        }
    }

    for (i = 0; i < 10; i++) {
        printf("X[%d] = %d\n", i, X[i]);
    }

    return 0;
}
