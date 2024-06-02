#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 5

int minKey(int key[], int set[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (set[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void printMST(int parent[], int graph[V][V]) {
    int totalCost = 0;
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
        totalCost += graph[i][parent[i]];
    }
    printf("Total Cost: %d\n", totalCost);
}

void primMST(int graph[V][V]) {
    int parent[V];
    int key[V];
    int set[V];
    
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        set[i] = 0;
    }
    
    key[0] = 0;
    parent[0] = -1;
    
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, set);
        set[u] = 1;
        
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && set[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    
    printMST(parent, graph);
}

int main() {
    int graph[V][V] = {
        {0, 1, 2, 0, 0},
        {1, 0, 0, 3, 0},
        {2, 0, 0, 6, 5},
        {0, 3, 6, 0, 4},
        {0, 0, 5, 4, 0}
    };
    primMST(graph);
    return 0;
}
