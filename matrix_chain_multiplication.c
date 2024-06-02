#include <limits.h>
#include <stdio.h>
 
int MatrixChainOrder(int p[], int i, int j)
{
    if (i == j)
        return 0;
    int k;
    int min = INT_MAX;
    int count;
    for (k = i; k < j; k++)
    {
        count = MatrixChainOrder(p, i, k)
                + MatrixChainOrder(p, k + 1, j)
                + p[i - 1] * p[k] * p[j];
 
        if (count < min)
            min = count;
    }
    return min;
}
int main()
{
    int arr[] = { 4,5,7,3,2,7,6 };
    int N = sizeof(arr) / sizeof(arr[0]);
    printf("Minimum number of multiplications is %d ",
           MatrixChainOrder(arr, 1, N - 1));
    getchar();
    return 0;
}
/*
#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 6

int matrixChainOrder(int dims[], int n) {
    int dp[MAX_SIZE][MAX_SIZE];
    
    for (int i = 0; i < n; i++)
        dp[i][i] = 0;
    
    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }
    
    return dp[1][n - 1];
}

int main() {
    int dims[] = {4, 5, 7, 3, 2, 7, 6};
    int n = sizeof(dims) / sizeof(dims[0]);
    
    int cost = matrixChainOrder(dims, n);
    printf("Minimum cost of matrix chain multiplication: %d\n", cost);
    
    return 0;
}
*/