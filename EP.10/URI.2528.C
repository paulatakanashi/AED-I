#include <stdio.h>
#include <stdbool.h>

#define MAX_CITIES 1000
#define MAX_ROUTES (MAX_CITIES * (MAX_CITIES - 1) / 2)

int graph[MAX_CITIES][MAX_CITIES];
int visited[MAX_CITIES];

int min(int a, int b) {
    return (a < b) ? a : b;
}

void dfs(int current_city, int destination_city, int forbidden_city, int current_time, int *min_time) {
    if (current_city == destination_city) {
        // Atualiza o menor tempo encontrado
        *min_time = min(*min_time, current_time);
        return;
    }
    
    visited[current_city] = true;
    
    for (int i = 0; i < MAX_CITIES; i++) {
        // Verifica se há uma rota entre as cidades e se a cidade não foi visitada e não é a cidade proibida
        if (graph[current_city][i] && !visited[i] && i != forbidden_city) {
            // Realiza a chamada recursiva para a próxima cidade
            dfs(i, destination_city, forbidden_city, current_time + 1, min_time);
        }
    }
    
    visited[current_city] = false;
}

int main() {
    int num_cities, num_routes;
    
    while (scanf("%d %d", &num_cities, &num_routes) != EOF) {
        // Inicializa o grafo e o array de visitados
        for (int i = 0; i < MAX_CITIES; i++) {
            for (int j = 0; j < MAX_CITIES; j++) {
                graph[i][j] = 0;
            }
            visited[i] = false;
        }
        
        // Lê as rotas
        for (int i = 0; i < num_routes; i++) {
            int city_a, city_b;
            scanf("%d %d", &city_a, &city_b);
            // Marca a rota entre as cidades no grafo
            graph[city_a][city_b] = graph[city_b][city_a] = 1;
        }
        
        int curytiba, riacho, estadunido;
        scanf("%d %d %d", &curytiba, &riacho, &estadunido);
        
        int min_time = MAX_CITIES + 1;
        // Chama a função DFS para encontrar o menor tempo necessário
        dfs(curytiba, riacho, estadunido, 0, &min_time);
        
        printf("%d\n", min_time);
    }
    
    return 0;
}
