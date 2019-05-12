//#include <iostream>
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <cmath>
//using namespace std;
//
//const int N = 1000+10;
//int a[N][N], dis[N], n, m, u, v, w;
//const int INF = 21474836;
//int book[N];
//
//void dijkstra()
//{
//    //需要把集合Q中的n-1个顶点拿到P中
//    for(int i = 1; i <= n-1; i++)
//    {
//        int minx = INF;
//        int tmp;
//        for(int j = 1; j <= n; j++)
//        {
//            if(book[j] == 0 && dis[j] < minx)
//            {
//                tmp = j;
//                minx = dis[j];
//            }
//        }
//        book[tmp] = 1;
//        printf("%d\n", tmp);
//        for(int j = 1; j <= n; j++)
//        {
//            if(dis[tmp] + a[tmp][j] < dis[j])
//                dis[j] = dis[tmp] + a[tmp][j];
//        }
//    }
//}
//
//int main()
//{
//    memset(a, INF, sizeof(a));
//    memset(dis, INF, sizeof(dis));
//    memset(book, 0, sizeof(book));
//    scanf("%d%d", &n, &m);
//    for(int i = 1; i <= m; i++)
//    {
//        scanf("%d%d%d", &u, &v, &w);
//        a[u][v] = w;
//        a[i][i] = 0;
//    }
//
//    book[1] = 1;
//    for(int i = 1; i <= n; i++)
//        dis[i] = a[1][i];
//    dijkstra();
//
//    for(int i = 1; i <= n; i++)
//        printf("%d ", dis[i]);
//
//    return 0;
//}
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 1000+10;
int u[N], v[N], w[N], dis[N], n, m;
const int INF = 21474836;
int book[N];
int first[N], next[N];

void dijkstra()
{
    //需要把集合Q中的n-1个顶点拿到P中
    for(int i = 1; i <= n-1; i++)
    {
        int tmp;
        int minx = INF;
        for(int j = 1; j <= n; j++)
        {
            if(dis[j] < minx && book[j] == 0)
            {
                minx = dis[j];
                tmp = j;
            }
        }
      //  printf("%d\n", tmp);
        book[tmp] = 1;
        //tmp是从集合Q中找出的距离最小的一个顶点
        //k是这个顶点在输入中的边的编号 u[k]
        int k = first[tmp];
        while(k != -1)
        {
            if(dis[u[k]] + w[k] < dis[v[k]])
                dis[v[k]] = dis[u[k]] + w[k];
            k = next[k];
        }
    }
    return;
}

int main()
{
    memset(first, -1, sizeof(first));
    memset(next, -1, sizeof(next));
    memset(dis, INF, sizeof(dis));
    memset(book, 0, sizeof(book));
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &u[i], &v[i], &w[i]);
        next[i] = first[u[i]];
        first[u[i]] = i;
    }
    dis[1] = 0;
    book[1] = 1;
    int k = first[1];
    while(k != -1)
    {
        dis[v[k]] = w[k];
        k = next[k];
    }

//    for(int i = 1; i <= n; i++)
//        printf("%d ", dis[i]);
//
//    printf("\n");
    dijkstra();

    for(int i = 1; i <= n; i++)
        printf("%d ", dis[i]);

    return 0;
}

/*
6 9
1 2 1
1 3 12
2 3 9
2 4 3
3 5 5
4 3 4
4 5 13
4 6 15
5 6 4
*/

/*
6 9
1 2 1
1 3 12
2 3 9
2 4 3
3 5 5
4 3 4
4 5 13
4 6 15
5 6 4
*/
