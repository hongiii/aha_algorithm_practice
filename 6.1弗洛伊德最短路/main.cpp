#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;

const int N = 110;
const int INF = 21474836;
int n, m, u, v, w;
int a[N][N];
int dis[N][N];

void floyd()
{
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(a[i][k] < INF && a[k][j] < INF && a[i][k]+a[k][j] < a[i][j])
                    a[i][j] = a[i][k] + a[k][j];
    }
}

int main()
{
    scanf("%d%d", &n, &m);
 //   memset(dis, INF, sizeof(dis));
    memset(a, INF, sizeof(a));
    for(int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        a[u][v] = w;
        a[i][i] = 0;
    }
    floyd();
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            printf("a[%d][%d] = %d\n", i, j, a[i][j]);
    }
    return 0;
}

/*
4 8
1 2 2
1 3 6
1 4 4
2 3 3
3 1 7
3 4 1
4 1 5
4 3 12
*/
