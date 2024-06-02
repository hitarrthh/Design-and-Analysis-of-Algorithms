#include <stdio.h>
int max(int a,int b)
{
    return (a>b)? a:b;
}
int knapsack(int m,int weight[],int profit[],int n)
{
    int i,j;
    int knap[n+1][m+1];
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                knap[i][j] = 0;
            }
            else if(weight[i-1] <= j)
            {
                knap[i][j] = max(profit[i-1] + knap[i-1][j-weight[i-1]], knap[i-1][j]);
            }
            else
            {
                knap[i][j] = knap[i-1][j];
            }
        }
    }
    return knap[n][m];
}
void main()
{
    int profit[]= {280,100,120,120};
    int weight[] = {40,10,20,24};
    int m=60;
    int n = sizeof(profit) / sizeof(profit[0]);
    int ans = knapsack(m,weight,profit,n);
    printf("PROFIT: %d",ans);
}