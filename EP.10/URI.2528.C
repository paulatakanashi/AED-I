#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define INF 0x3f3f3f3fU
#define MAXSIZE 1001

typedef unsigned int uint;

uint dist[MAXSIZE];
uint graph[MAXSIZE][MAXSIZE];

void dijkstra(int, int, uint g[MAXSIZE][MAXSIZE], uint *);

int main(){
    int n, m, u, v;

    while (scanf("%d %d", &n, &m) == 2){
        memset(graph, INF, sizeof(graph));

        for (int i = 0; i < m; ++i){
            scanf("%d %d", &u, &v);
            graph[u][v] = graph[v][u] = 1;
        }

        int c, r, e;
        scanf("%d %d %d", &c, &r, &e);

        for (int i = 0; i <= n; ++i)
            graph[e][i] = graph[i][e] = INF;
        dijkstra(c, n, graph, dist);
        printf("%u\n", dist[r]);
    }
    return 0;
}

void dijkstra(int s, int n, uint g[MAXSIZE][MAXSIZE], uint *d){
    bool vis[MAXSIZE];
    memset(vis, false, sizeof(vis));

    memset(d, INF, (n + 1) * sizeof(uint));
    d[s] = 0;

    for (int i = 0; i <= n; ++i){
        int v = -1;
        for (int j = 0; j <= n; ++j){
            if (!vis[j] && (v == -1 || d[j] < d[v]))
                v = j;
        }

        if (d[v] == INF)
            break;

        vis[v] = true;
        for (int j = 0; j <= n; ++j){
            if (d[v] + g[v][j] < d[j])
                d[j] = d[v] + g[v][j];
        }
    }
}
