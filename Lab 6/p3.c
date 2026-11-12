#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    char X[100], Y[100];
    int m, n, i, j;

    printf("Enter first string: ");
    scanf("%99s", X);

    printf("Enter second string: ");
    scanf("%99s", Y);

    m = strlen(X);
    n = strlen(Y);

    // Create DP table
    int **dp = (int **)malloc((m + 1) * sizeof(int *));

    for (i = 0; i <= m; i++)
    {
        dp[i] = (int *)malloc((n + 1) * sizeof(int));
    }

    // Fill DP table
    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (X[i - 1] == Y[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    printf("Length of LCS = %d\n", dp[m][n]);

    // Reconstruct LCS
    int length = dp[m][n];
    char *lcs = (char *)malloc((length + 1) * sizeof(char));

    lcs[length] = '\0';

    i = m;
    j = n;

    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            lcs[length - 1] = X[i - 1];
            i--;
            j--;
            length--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    printf("Longest Common Subsequence = %s\n", lcs);

    // Free memory
    for (i = 0; i <= m; i++)
    {
        free(dp[i]);
    }

    free(dp);
    free(lcs);

    return 0;
}