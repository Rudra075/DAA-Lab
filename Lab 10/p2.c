#include <stdio.h>

#define MAX 10000

int parent[MAX], size[MAX], land[MAX];

int find(int x)
{
    if (parent[x] != x)
        parent[x] = find(parent[x]);

    return parent[x];
}

int unite(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a == b)
        return 0;

    if (size[a] < size[b])
    {
        int t = a;
        a = b;
        b = t;
    }

    parent[b] = a;
    size[a] += size[b];

    return 1;
}

int main()
{
    int R, C, K;
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    printf("Enter rows, columns and operations: ");
    scanf("%d %d %d", &R, &C, &K);

    int total = R * C;
    int islands = 0;

    for (int i = 0; i < total; i++)
    {
        parent[i] = i;
        size[i] = 1;
        land[i] = 0;
    }

    for (int i = 0; i < K; i++)
    {
        int r, c;

        printf("Enter row and column: ");
        scanf("%d %d", &r, &c);

        if (land[r * C + c])
        {
            printf("Islands = %d\n", islands);
            continue;
        }

        int id = r * C + c;
        land[id] = 1;
        islands++;

        for (int j = 0; j < 4; j++)
        {
            int nr = r + dr[j];
            int nc = c + dc[j];

            if (nr >= 0 && nr < R && nc >= 0 && nc < C)
            {
                int nid = nr * C + nc;

                if (land[nid] && unite(id, nid))
                    islands--;
            }
        }

        printf("Islands = %d\n", islands);
    }

    return 0;
}