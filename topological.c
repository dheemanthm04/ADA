#include <stdio.h>
#include <stdlib.h>

void topoSort(int V, int **adj, int *result, int *index) {
    int *indegree = (int *)calloc(V, sizeof(int));
    if (indegree == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    int *queue = (int *)malloc(V * sizeof(int));
    if (queue == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    int front = 0, rear = 0;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    while (front < rear) {
        int node = queue[front++];
        result[(*index)++] = node;

        for (int i = 0; i < V; i++) {
            if (adj[node][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }

    free(indegree);
    free(queue);
}

void addEdge(int **adj, int u, int v) {
    adj[u][v] = 1;
}

int main() {
    int N, E;
    printf("Enter the number of vertices and edges:\n");
    scanf("%d %d", &N, &E);

    int **adj = (int **)malloc(N * sizeof(int));
    if (adj == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    for (int i = 0; i < N; i++) {
        adj[i] = (int *)calloc(N, sizeof(int));
        if (adj[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
    }

    printf("Enter the edges (u v) format:\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    int *res = (int *)malloc(N * sizeof(int));
    if (res == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    int index = 0;
    topoSort(N, adj, res, &index);

    if (index != N) {
        printf("The graph contains a cycle. A topological sort is not possible.\n");
    } else {
        printf("Topological sort of the given graph is:\n");
        for (int i = 0; i < N; i++) {
            printf("%d ", res[i]);
        }
        printf("\n");
    }

    for (int i = 0; i < N; i++) {
        free(adj[i]);
    }
    free(adj);
    free(res);

    return 0;
}
