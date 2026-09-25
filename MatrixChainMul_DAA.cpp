#include <iostream>
#include <climits>
using namespace std;

int matrixChainMultiplication(int p[], int n)
{
    int dp[n][n];

    // Cost is 0 when there is only one matrix
    for (int i = 1; i < n; i++)
        dp[i][i] = 0;

    // length = number of matrices in the chain
    for (int length = 2; length < n; length++)
    {
        for (int i = 1; i < n - length + 1; i++)
        {
            int j = i + length - 1;
            dp[i][j] = INT_MAX;

            // Try every possible split
            for (int k = i; k < j; k++)
            {
                int cost = dp[i][k]
                         + dp[k + 1][j]
                         + p[i - 1] * p[k] * p[j];

                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }

    return dp[1][n - 1];
}

int main()
{
    // A1 = 10x30, A2 = 30x5, A3 = 5x60
    int p[] = {10, 30, 5, 60};

    int n = sizeof(p) / sizeof(p[0]);

    cout << "Minimum number of scalar multiplications = "
         << matrixChainMultiplication(p, n);

    return 0;
}