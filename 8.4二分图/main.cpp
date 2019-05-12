#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 110;
int a[N][N];
int book[N], n, m, match[N];
int dfs(int cur)
{
    for(int i = 1; i <= n; i++)
    {
        if(a[cur][i] == 1 && book[i] == 0)
        {
            book[i] = 1; //��ǵ�i�Ѿ����ʹ�
            /*
            �����iδ����Ի����ҵ����µ����
            */
            if(match[i] == 0 || dfs(match[i]))
            {
                //������Թ�ϵ
                match[i] = cur;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    scanf("%d%d", &n, &m);
    int u, v;
    for(int i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        a[u][v] = 1;
    }
    memset(match, 0, sizeof(match));
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        memset(book, 0, sizeof(book));
        if(dfs(i)) //Ѱ������·
            cnt++;
    }
    printf("\n");
    for(int i = 1; i <= n; i++)
    {
        if(match[i])
            printf("%d->%d\n", match[i], i);
    }
    return 0;
}

/*
3 5
1 1
1 2
2 2
2 3
3 1

match[v] = u;
*/
