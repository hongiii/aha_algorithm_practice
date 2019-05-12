#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 101;
//int dis[N];
//
//int n, m, u[N], v[N], w[N];
//int main()
//{
//    scanf("%d%d", &n, &m);
//    memset(u, 0, sizeof(u));
//    memset(v, 0, sizeof(v));
//    memset(w, 0, sizeof(w));
//    for(int i = 1; i <= n; i++)
//    {
//        dis[i] = 9999;
//    }
//    for(int i = 1; i <= m; i++)
//    {
//        scanf("%d%d%d", &u[i], &v[i], &w[i]);
//    }
//    dis[1] = 0;
//    for(int k = 1; k <= n-1; k++)
//    {
//        for(int i = 1; i <= m; i++)
//        {
//       //     printf("%d %d %d\n", u[i], v[i], w[i]);
//            if(dis[u[i]] != 9999 && dis[u[i]]+w[i] < dis[v[i]])
//            {
//                  if(v[i] == 4)
//                     printf("%d %d %d\n", u[i], v[i], w[i]);
//                  dis[v[i]] = dis[u[i]]+w[i];
//            }
//        }
//    }
//    for(int i = 1; i <= n; i++)
//        printf("%d ", dis[i]);
//    return 0;
//}
int book[N], a[N][N];
int dis[N];
int n, m, u, v, w;
int head, tail;
int num[N];
int main()
{
    scanf("%d%d", &n, &m);
    memset(book, 0, sizeof(book));
    for(int i = 1; i <= n; i++)
    {
        dis[i] = 9999;
        for(int j = 1; j <= n; j++)
            a[i][j] = 9999;
    }
    for(int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        a[u][v] = w;
        a[i][i] = 0;
    }

    head = tail = 0;
    num[tail] = 1;
    dis[1] = 0;
    tail++;
    book[1] = 1;
//    for(int i = 1; i <= n; i++)
//        dis[i] = a[1][i];
//    for(int i = 1; i <= n; i++)
//    {
//        for(int j = 1; j <= n; j++)
//            printf("%d ", a[i][j]);
//        printf("\n");
//        printf("--%d--%d---", dis[i], book[i]);
//    }
    while(head < tail)
    {
        int t = num[head];
        for(int i = 1; i <= n; i++)
        {
          //  printf("Test\n");
        //    printf("%d------%d\n", a[t][i] + dis[t], dis[i]);
            if(a[t][i] + dis[t] < dis[i] && book[i] == 0)
            {
                dis[i] = a[t][i] + dis[t];
                num[tail] = i;
                tail++;
                book[t] = 1;
         //       printf("test\n");
            }
        }
        head++;
    }
    for(int i = 1; i <= n; i++)
        printf("%d ", dis[i]);
    return 0;
}

/*
6 9
1 2 5
1 4 2
2 3 4
2 4 8
2 5 2
3 5 6
3 6 3
4 5 4
5 6 2
*/

/*
5 5
1 2 10
2 3 20
4 2 1
3 4 1
3 5 30
*/
/*
5 7
1 2 2
1 3 2
2 3 2
2 5 2
2 4 2
4 3 -1
4 5 2
*/
