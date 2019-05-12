#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 101;
int a[N][N], num[N], low[N], flag[N];
int n, m;
int time = 0, root = 1;
int  minx(int a, int b)
{
    return  a < b ? a:b;
}
void dfs(int cur, int father)
{
    time++;
   // int child = 0;
    num[cur] = low[cur] = time;
    for(int i = 1; i <= n; i++)
    {
        if(a[cur][i] == 1)
        {
            if(num[i] == 0)
            {
             //   printf("test1\n");
               // child++;
                dfs(i, cur);
                low[cur] = minx(low[cur], low[i]);
                if(low[i] > num[cur])
                    printf("%d-%d\n", cur, i);
            }
            else if(i != father)
            {
                low[cur] = minx(low[cur], num[i]);
            }
//            else if(i == father)
//            {
//                low[cur] = min(low[cur], num[i]);
//            }
        }

    }
}

int main()
{
   scanf("%d%d", &n, &m);
   int u, v;
   memset(num, 0, sizeof(0));
   memset(flag, 0, sizeof(flag));
   memset(a, 0, sizeof(a));
   for(int i = 1; i <= m; i++)
   {
       scanf("%d%d", &u, &v);
       a[u][v] = 1;
       a[v][u] = 1;
   }

   dfs(1, root);

//   for(int i = 1; i <= n; i++)
//   {
//       if(flag[i] == 1)
//       {
//           printf("%d ", i);
//       }
//   }

   return 0;
}

/*
6 6
1 4
1 3
4 2
3 2
2 5
5 6
*/
