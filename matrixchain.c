#include<stdio.h> 
#include<string.h> 
# define INT_MAX 2147483647
int min(int a, int b)
{
    if (a <= b)
    {
        return a;
    }
    return b;
}
int dp[100][100];
int matrixChainMemoised(int *p, int i, int j)
{
    if (i == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    dp[i][j] = INT_MAX;
    for (int k = i; k < j; k++)
    {
        dp[i][j] = min(dp[i][j], matrixChainMemoised(p, i, k) + matrixChainMemoised(p, k + 1, j) + p[i - 1] * p[k] * p[j]);
    }
    return dp[i][j];
}
int matrixChainOrder(int *p, int n)
{
    int i = 1, j = n - 1;
    return matrixChainMemoised(p, i, j);
}
int main()
{
    int n;
    printf("Enter the value of n\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the values\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    memset(dp, -1, sizeof dp);
    printf("Minimum number of multiplication is %d", matrixChainOrder(arr, n));
}