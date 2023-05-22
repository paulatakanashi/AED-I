#include <stdio.h>
#include <string.h>

#define MAX_N 100
#define MAX_NAME_LEN 20

int main() {
    int n, k, i;
    char names[MAX_N][MAX_NAME_LEN + 1], winner[MAX_NAME_LEN + 1];

    // leitura da entrada
    scanf("%d %d", &n, &k);
    for (i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    // ordenação dos nomes em ordem alfabética
    for (i = 0; i < n - 1; i++) {
        int j, min_index = i;
        for (j = i + 1; j < n; j++) {
            if (strcmp(names[j], names[min_index]) < 0) {
                min_index = j;
            }
        }
        if (min_index != i) {
            char temp[MAX_NAME_LEN + 1];
            strcpy(temp, names[i]);
            strcpy(names[i], names[min_index]);
            strcpy(names[min_index], temp);
        }
    }

    // encontra o nome do aluno premiado
    strcpy(winner, names[k - 1]);

    // imprime o nome do aluno premiado
    printf("%s\n", winner);

    return 0;
}
