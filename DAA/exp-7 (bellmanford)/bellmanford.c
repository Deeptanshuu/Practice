#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100
#define MAX_EDGES 100

struct Edge
{
    int source, destination, weight;
};

struct Graph
{
    int vertices, edges;
    struct Edge *edge;
};

struct Graph *createGraph(int vertices, int edges)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->edges = edges;
    graph->edge = (struct Edge *)malloc(edges * sizeof(struct Edge));
    return graph;
}

void BellmanFord(struct Graph *graph, int source)
{
    int vertices = graph->vertices;
    int edges = graph->edges;
    int dist[MAX_VERTICES];

    // Initialize distances from source to all other vertices as INFINITY
    for (int i = 0; i < vertices; i++)
        dist[i] = INT_MAX;
    dist[source] = 0;

    // Relax all edges vertices-1 times
    for (int i = 1; i <= vertices - 1; i++)
    {
        for (int j = 0; j < edges; j++)
        {
            int u = graph->edge[j].source;
            int v = graph->edge[j].destination;
            int weight = graph->edge[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    // Check for negative-weight cycles
    for (int i = 0; i < edges; i++)
    {
        int u = graph->edge[i].source;
        int v = graph->edge[i].destination;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
        {
            printf("Graph contains negative weight cycle");
            return; // If negative cycle is detected, return
        }
    }

    // Print the shortest distances
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < vertices; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main()
{
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    struct Graph *graph = createGraph(vertices, edges);

    printf("Enter source, destination and weight of each edge:\n");
    for (int i = 0; i < edges; ++i)
    {
        scanf("%d %d %d", &graph->edge[i].source, &graph->edge[i].destination, &graph->edge[i].weight);
    }

    int source;
    printf("Enter source vertex: ");
    scanf("%d", &source);

    BellmanFord(graph, source);

    return 0;
}
