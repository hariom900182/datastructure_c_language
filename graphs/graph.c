#include "../Queue/queueLs.c"

int visited[7] = {0};

void BFS(int g[][7], int start, int size)
{
    int i, j, u;
    printf("%d ", start);
    visited[start] = 1;
    enqueue(start);
    while (front != NULL)
    {
        u = dequeue();
        for (j = 1; j < size; j++)
        {
            if (g[u][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                enqueue(j);
                visited[j] = 1;
            }
        }
    }
}

void DFS(int g[][7], int start, int size)
{
    int i, j, u;
    if (visited[start] == 0)
    {
        printf("%d ", start);
        visited[start] = 1;
        for (j = 1; j < size; j++)
        {
            if (g[start][j] == 1 && visited[j] == 0)
            {
                DFS(g, j, size);
            }
        }
    }
}

void main()
{
    int G[7][7] = {{0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 1, 0, 0}};

    // BFS(G, 4, 7);

    DFS(G, 4, 7);
}