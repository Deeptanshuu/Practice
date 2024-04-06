#include <stdio.h>

#define INFINITY 9999
#define MAX 10

void Dijkstra(int Graph[MAX][MAX], int n, int start);

int main() {
    int Graph[MAX][MAX], i, j, n, u;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &Graph[i][j]);
        }
    }

    printf("\nEnter the starting node: \n");
    scanf("%d", &u);

    Dijkstra(Graph, n, u);

    return 0;
}

void printPath(int start, int end, int pred[]) {
    // Base case
    if (end == start) {
        printf("%d", start);
        return;
    }
    // Recursively print the path
    printPath(start, pred[end], pred);
    printf(" -> %d", end);
}

void Dijkstra(int Graph[MAX][MAX], int n, int start) {
    int distance[MAX], pred[MAX];
    int visited[MAX] = {0};
    int count, mindistance, nextnode, i, j;

    // Initialization
    for (i = 0; i < n; i++) {
        distance[i] = INFINITY;
        pred[i] = -1;
    }

    distance[start] = 0;
    count = 0;

    while (count < n - 1) {
        mindistance = INFINITY;

        // Finding the next node to visit
        for (i = 0; i < n; i++) {
            if (!visited[i] && distance[i] < mindistance) {
                mindistance = distance[i];
                nextnode = i;
            }
        }

        visited[nextnode] = 1;
        for (i = 0; i < n; i++) {
            if (!visited[i] && Graph[nextnode][i] != 0 && distance[nextnode] + Graph[nextnode][i] < distance[i]) {
                distance[i] = distance[nextnode] + Graph[nextnode][i];
                pred[i] = nextnode;
            }
        }
        count++;
    }

    // Printing the shortest paths and distances
    for (i = 0; i < n; i++) {
        if (i != start) {
            printf("Shortest path from %d to %d: ", start, i);
            printPath(start, i, pred);
            printf("\nDistance: %d\n", distance[i]);
        }
    }
}
