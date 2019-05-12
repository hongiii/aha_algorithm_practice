#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int INF = 9999999;
const int N = 10010;
int u[N], v[N], w[N];
int n, m, dis[N];

void bellman_ford()
{
    for(int k = 1; k <= n-1; k++)
    {
        int check = 0;
        for(int i = 1; i <= m; i++)
        {
            if(dis[u[i]] + w[i] < dis[v[i]])
            {
                dis[v[i]] = dis[u[i]] + w[i];
                check = 1;
            }
        }
        if(!check)
            break;
    }
    int flag = 0;
    for(int i = 1; i <= m; i++)
    {
        if(dis[u[i]] + w[i] < dis[v[i]])
        {
            flag = 1;
            break;
        }
    }
    if(flag)
        printf("此图含有负权回路\n");
    return;
}

int main()
{
   // memset(book, 0, sizeof(book));
    memset(dis, INF, sizeof(dis));

    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &u[i], &v[i], &w[i]);
    }

    dis[1] = 0;

    bellman_ford();
    for(int i = 1; i <= n; i++)
        printf("%d ", dis[i]);
    return 0;
}


/*
5 5
2 3 2
1 2 -3
1 5 5
4 5 2
3 4 3

*/
