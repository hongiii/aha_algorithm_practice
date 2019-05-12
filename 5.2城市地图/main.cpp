//优化：如果距离已经比之前大。直接返回；距离作为参数，我这里距离自己写进去了
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 51;
const int INF = 99999;
int a[N][N], book[N];
int n, m, p, q, r;
int cnt = 0, top = 0;
int root[N];
int mindis = INF;

void dfs(int cur)
{
    if(cur > mindis)
        return;
    if(cur == n)
    {
        if(cnt < mindis)
            mindis = cnt;
        //printf("%d\n", cnt);
        for(int i = 1; i <= top; i++)
        {
                 printf("%d ", root[i]);
        }
        printf("\n");
        return;
    }

    for(int i = 1; i <= n; i++)
    {
        if(a[cur][i] > 0 && a[cur][i] < INF && book[i] == 0)
        {
            book[i] = 1;
            cnt += a[cur][i];
            root[++top] = i;
            dfs(i);
            book[i] = 0;
            cnt -= a[cur][i];
            --top;
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    memset(a, INF, sizeof(a));
    memset(book, 0, sizeof(book));

    for(int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &p, &q, &r);
        a[p][q] = r;
    }

    book[1] = 5;
    root[++top] = 1;
    dfs(1);
    printf("\n\n%d\n", mindis);

    return 0;
}

/*
5 8
1 2 2
1 5 10
2 3 3
2 5 7
3 1 4
3 4 4
4 5 5
5 3 3
*/
