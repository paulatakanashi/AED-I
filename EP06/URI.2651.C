#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100000

int main()
{
    char string[MAX];
    char string2[MAX];
    
    // Lê a string de entrada
    fgets(string, MAX, stdin);
    
    char search[] = "zelda";
    int i = 0;
    
    // Converte a string de entrada para letras minúsculas
    while (string[i] != '\0')
    {
        string2[i] = tolower(string[i]);
        i++;
    }
    
    // Verifica se a substring "zelda" está presente na string convertida
    char *ptr = strstr(string2, search);
    
    if (ptr)
    {
        printf("Link Bolado\n");
    }
    else
    {
        printf("Link Tranquilo\n");
    }
    
    return 0;
}
