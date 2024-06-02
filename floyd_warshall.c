#include <stdio.h>
#include<limits.h>
#define V 4
void floyd(int d[V][V])
{
    int i,k,j;
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            for(k=0;k<V;k++)
            {
                if(d[j][k] > (d[j][i]+d[i][k]) && d[j][i]!= INT_MAX && d[i][k]!= INT_MAX)
                {
                    d[j][k] = d[j][i]+d[i][k];
                }
            }
        }    
    }
    print_sol(d);
}
void print_sol(int graph[V][V])
{
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            if(graph[i][j] == INT_MAX)
            {
                printf("INF ");
            }
            else
            {
                printf("%d ",graph[i][j]);
            }
        }
        printf("\n");
    }
    
}
void main()
{
    int graph[V][V] = {
        {0,8,INT_MAX,1},
        {INT_MAX,0,1,INT_MAX},
        {4,INT_MAX,0,INT_MAX},
        {INT_MAX,2,9,0},
    };
    floyd(graph);
}