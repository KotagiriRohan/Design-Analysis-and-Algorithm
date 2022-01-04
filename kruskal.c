#include <stdio.h> 
#define V 30
typedef struct edge
{
    int u, v, w;
} edge;
typedef struct edge_list
{
    edge data[V];
    int n;
} edge_list;
edge_list elist;
int graph[V][V], n;
edge_list spanlist;
int find(int belongs[], int vertexno) { return (belongs[vertexno]); }
void applyUnion(int belongs[], int c1, int c2)
{
    int i;
    for (i = 0; i < n; i++)
        if (belongs[i] == c2)
            belongs[i] = c1;
}
void sort()
{
    int i, j;
    edge temp;
    for (i = 1; i < elist.n; i++)
        for (j = 0; j < elist.n - 1; j++)
            if (elist.data[j].w > elist.data[j + 1].w)
            {
                temp = elist.data[j];
                elist.data[j] = elist.data[j + 1];
                elist.data[j + 1] = temp;
            }
}
void kruskal()
{
    int belongs[V], i, j, cno1, cno2;
    elist.n = 0;
    for (i = 1; i < n; i++)
        for (j = 0; j < i; j++)
        {
            if (graph[i][j] != 0)
            {
                elist.data[elist.n].u = i;
                elist.data[elist.n].v = j;
                elist.data[elist.n].w = graph[i][j];
                elist.n++;
            }
        }
    sort();
    for (i = 0; i < n; i++)
        belongs[i] = i;
    spanlist.n = 0;
    for (i = 0; i < elist.n; i++)
    {
        cno1 = find(belongs, elist.data[i].u);
        cno2 = find(belongs, elist.data[i].v);
        if (cno1 != cno2)
        {
            spanlist.data[spanlist.n] = elist.data[i];
            spanlist.n = spanlist.n + 1;
            applyUnion(belongs, cno1, cno2);
        }
    }
}
int main()
{
    printf("Enter the number of vertices\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    kruskal();
    int i, cost = 0;
    printf("\n\nEdge, Weight\n");
    for (i = 0; i < spanlist.n; i++)
    {
        printf("\n%d - %d : %d", spanlist.data[i].u, spanlist.data[i].v, spanlist.data[i].w);
        cost = cost + spanlist.data[i].w;
    }
}