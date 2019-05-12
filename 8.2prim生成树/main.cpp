#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 110;
int n, m;
const int INF = 99999;
int a[N][N], book[N];
int dis[N];

int main()
{
   scanf("%d%d", &n, &m);
   int u, v, w;
   memset(book, 0, sizeof(book));
   for(int i = 1; i <= n; i++)
       dis[i] = INF;
   for(int i = 1; i <= n; i++)
   {
       for(int j = 1; j <= n; j++)
       {
           a[i][j] = INF;
       }
   }
   for(int i = 1; i <= m; i++)
   {
       scanf("%d%d%d", &u, &v, &w);
       a[u][v] = w;
       a[v][u] = w;
       a[i][i] = 0;
   }
   for(int i = 1; i <= n; i++)
      dis[i] = a[1][i];
    book[1] = 1;
//   for(int i = 1; i <= n; i++)
//    printf("%d  ", dis[i]);
//   printf("----\n");
   //Prim
   int sum = 0;
   for(int k = 1; k <= n-1; k++)
   {
       int t, minx = INF;
       for(int i = 1; i <= n; i++)
       {
           if(book[i] == 0 && dis[i] < minx)
           {
              minx = dis[i];
              t = i;
           }
       }
       book[t] = 1;
       sum += dis[t];
       for(int i = 1; i <= n; i++)
       {
           if(a[t][i] < dis[i])
           {
               dis[i] = a[t][i];
           }
       }
   }
   printf("%d\n", sum);
   return 0;
}

/*
6 9
2 4 11
3 5 13
4 6 3
5 6 4
2 3 6
4 5 7
1 2 1
3 4 9
1 3 2
*/
