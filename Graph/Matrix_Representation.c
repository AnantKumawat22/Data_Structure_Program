#include<stdio.h>
#include<conio.h>

struct Graph
{
    int V;
    int E;
    int **Adj;
};

struct Graph* adjMatrixOfGraph()
{
    int i, j, k;
    struct Graph *G = (struct Graph *)malloc(sizeof(struct Graph));
    if (G)
    {
        printf("Memory Error.");
        return;
    }
    printf("Enter number of nodes and numner of edges.");
    scanf("%d%d", &G->V, &G->E);
    G->Adj = (int*)malloc(sizeof(int) * (G->V*G->V));
    for(i = 0; i < G->V; i++)
    {
        for(j = 0; j < G->V; j++)
        {
            G->Adj[i][j] = 0;
        }
    }
    print("Enter node numners in a pair that connects an edge.");
    for(k = 0; k < G->V; k++)
    {
        scanf("%d%d", &i, &j);
        G->Adj[i][j] = 1;
        G->Adj[j][i] = 1;
    }
}