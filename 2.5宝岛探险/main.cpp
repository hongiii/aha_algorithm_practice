#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

//struct node
//{
//    int x;
//    int y;
//};
//
//const int N = 51;
//int a[N][N], n, m, startx, starty;
//int sum = 1, head, tail;
//node nd[N];
//int book[N][N], next[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
//
//void bfs()
//{
//    int tx, ty;
//    while(head < tail)
//    {
//        for(int i = 0; i < 4; i++)
//        {
//            tx = nd[head].x + next[i][0];
//            ty = nd[head].y + next[i][1];
//            if(tx < 0 || tx > n-1 || ty < 0 || ty > m-1)
//                continue;
//            if(a[tx][ty] != 0 && book[tx][ty] == 0)
//            {
//                book[tx][ty] = 1;
//                sum++;
//                nd[tail].x = tx;
//                nd[tail].y = ty;
//                tail++;
//            }
//        }
//        head++;
//    }
//}
//
//int main()
//{
//    scanf("%d%d%d%d", &n, &m, &startx, &starty);
//    for(int i = 0; i < n; i++)
//        for(int j = 0; j < m; j++)
//        scanf("%d", &a[i][j]);
//    memset(book, 0, sizeof(book));
//
//    head = tail = 0;
//    nd[tail].x = startx - 1;
//    nd[tail].y = starty - 1;
//    tail++;
//    book[startx-1][starty-1] = 1;
//
//    bfs();
//
//    printf("%d\n", sum);
//
//    return 0;
//}

//²ÉÓÃÉîËÑÄØ£¿
const int N = 51;
int a[N][N], n, m, startx, starty;
int sum = 1;
int book[N][N], next[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}}, num = 0;

void dfs(int x, int y, int color)
{
    int tx, ty;
    a[x][y] = num;
    for(int i = 0; i < 4; i++)
    {
        tx = x + next[i][0];
        ty = y + next[i][1];
        if(tx < 0 || tx > n-1 || ty < 0 || ty > m-1)
            continue;
        if(a[tx][ty] != 0 && book[tx][ty] == 0)
        {
            book[tx][ty] = 1;
  //          sum++;
            dfs(tx, ty, color);
        }
    }
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &startx, &starty);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        scanf("%d", &a[i][j]);
    memset(book, 0, sizeof(book));

  //  book[startx-1][starty-1] = 1;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(a[i][j] > 0)
            {
                num--;
                book[i][j] = 1;
                dfs(i, j, num);
            }
        }
    }

  //  printf("%d\n", sum);
    printf("%d\n", -num);

//    for(int i = 0; i < n; i++)
//    {
//        for(int j = 0; j < m; j++)
//        {
//            printf("%d ", a[i][j]);
//        }
//        printf("\n");
//    }

    return 0;
}
/*
10 10 6 8
1 2 1 0 0 0 0 0 2 3
3 0 2 0 1 2 1 0 1 2
4 0 1 0 1 2 3 2 0 1
3 2 0 0 0 1 2 4 0 0
0 0 0 0 0 0 1 5 3 0
0 1 2 1 0 1 5 4 3 0
0 1 2 3 1 3 6 2 1 0
0 0 3 4 8 9 7 5 0 0
0 0 0 3 7 8 6 0 1 2
0 0 0 0 0 0 0 0 1 0
*/
