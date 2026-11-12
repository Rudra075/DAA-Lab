#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int N, i, j, k, L;

    printf("Enter N: ");
    scanf("%d", &N);

    int *arr = (int *)malloc(N * sizeof(int));

    printf("Enter %d dimensions:\n", N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    // dp[i][j] stores minimum multiplications
    // required to multiply matrices Ai to Aj
    long long **dp = (long long **)malloc(N * sizeof(long long *));

    for (i = 0; i < N; i++)
    {
        dp[i] = (long long *)malloc(N * sizeof(long long));
    }

    // Cost is zero when multiplying one matrix
    for (i = 1; i < N; i++)
    {
        dp[i][i] = 0;
    }

    // L is chain length
    for (L = 2; L < N; L++)
    {
        for (i = 1; i < N - L + 1; i++)
        {
            j = i + L - 1;

            dp[i][j] = LLONG_MAX;

            for (k = i; k < j; k++)
            {
                long long cost = dp[i][k]
                               + dp[k + 1][j]
                               + (long long)arr[i - 1]
                               * arr[k]
                               * arr[j];

                if (cost < dp[i][j])
                {
                    dp[i][j] = cost;
                }
            }
        }
    }

    printf("Minimum number of scalar multiplications = %lld\n",
           dp[1][N - 1]);

    // Free memory
    for (i = 0; i < N; i++)
    {
        free(dp[i]);
    }

    free(dp);
    free(arr);

    return 0;
}